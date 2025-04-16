#include "Transform.h"
#include "Core/Engine.h"
#include "Core/Common.h"    

namespace Blue
{
    Transform::Transform()
    {
        // 트랜스폼 행렬 계산(SRT).
        transformMatrix = Matrix4::Scale(scale) * Matrix4::Rotation(rotation) * Matrix4::Translation(position);

        // 전치 행렬. (CPU와 GPU가 행렬을 다루는 방식이 달라서).
        // 행기준 행렬을 열기준 행렬로 변환하기 위해 전치행렬 처리.
        transformMatrix = Matrix4::Transpose(transformMatrix);

        // 상수 버퍼.
        D3D11_BUFFER_DESC bufferDesc = {};
        bufferDesc.ByteWidth = Matrix4::Stride();
        bufferDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
        bufferDesc.Usage = D3D11_USAGE_DYNAMIC;
        bufferDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;

        // 버퍼에 담을 데이터 설정.
        D3D11_SUBRESOURCE_DATA bufferData = {};
        bufferData.pSysMem = &transformMatrix;

        // 버퍼 생성.
        ID3D11Device& device = Engine::Get().Device();
        ThrowIfFailed(device.CreateBuffer(&bufferDesc, &bufferData, &constantBuffer), TEXT("Failed to create a transform buffer."));

    }
    Transform::~Transform()
    {
        // 리소스 해제
        if (constantBuffer)
        {
            constantBuffer->Release();
            constantBuffer = nullptr;
        }
    }
    void Transform::Tick()
    {
        // 데이터 업데이트.
        // 트랜스폼 행렬 계산(SRT).
        transformMatrix = Matrix4::Scale(scale) * Matrix4::Rotation(rotation) * Matrix4::Translation(position);

        // 전치 행렬. (CPU와 GPU가 행렬을 다루는 방식이 달라서).
        // 행기준 행렬을 열기준 행렬로 변환하기 위해 전치행렬 처리.
        transformMatrix = Matrix4::Transpose(transformMatrix);
    }
    void Transform::Bind()
    {
        static ID3D11DeviceContext& context = Engine::Get().Context();

        //// 데이터 업데이트.
        //// 트랜스폼 행렬 계산(SRT).
        //transformMatrix = Matrix4::Scale(scale) * Matrix4::Rotation(rotation) * Matrix4::Translation(position);
        //// 전치 행렬. (CPU와 GPU가 행렬을 다루는 방식이 달라서).
        //// 행기준 행렬을 열기준 행렬로 변환하기 위해 전치행렬 처리.
        //transformMatrix = Matrix4::Transpose(transformMatrix);

        // 버퍼 업데이트.
        //context.UpdateSubresource(constantBuffer, 0u, nullptr, &transformMatrix, 0u, 0u); //cpu에 권한 준 장점을 활용 못함.
        D3D11_MAPPED_SUBRESOURCE resource = {};
        context.Map(constantBuffer, 0u, D3D11_MAP_WRITE_DISCARD, 0u, &resource);    // D3D11_MAP_WRITE_DISCARD -> GPU가 읽고 CPU가 쓸 때 사용.
        //resource.pData = &transformMatrix; // 결국 복사하므로 memcpy가 조금 더 빠름.
        memcpy(resource.pData, &transformMatrix, sizeof(Matrix4));
        context.Unmap(constantBuffer, 0u);

        // 버퍼 바인딩.
        context.VSSetConstantBuffers(0u, 1u, &constantBuffer);

    }
    Vector3 Transform::Forward()
    {
        // 로컬 기준 앞쪽 방향 벡터 구하기.
        // 월드 기준 앞쪽 방향 벡터를 로컬의 방향만큼 회전 적용.
        return Vector3::Forward* Matrix4::Rotation(rotation);
    }
    Vector3 Transform::Right()
    {
        // 로컬 기준 오른쪽 방향 벡터 구하기.
        // 월드 기준 오른쪽 방향 벡터를 로컬의 방향만큼 회전 적용.
        return Vector3::Right * Matrix4::Rotation(rotation);
    }
    Vector3 Transform::Up()
    {
        // 로컬 기준 위쪽 방향 벡터 구하기.
        // 월드 기준 위쪽 방향 벡터를 로컬의 방향만큼 회전 적용.
        return Vector3::Up* Matrix4::Rotation(rotation);
    }
}