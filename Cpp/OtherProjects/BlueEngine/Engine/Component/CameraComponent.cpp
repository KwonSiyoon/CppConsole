#include "CameraComponent.h"
#include "Core/Engine.h"
#include "Core/Common.h"
#include "Math/Transform.h"
#include "Actor/Actor.h"


namespace Blue
{
    CameraComponent::CameraComponent()
    {
        // 뷰행렬 업데이트 및 바인딩.
        /*data.viewMatrix =
            Matrix4::Translation(owner->transform.position * -1.0f)
            * Matrix4::Transpose(Matrix4::Rotation(owner->transform.rotation));*/

        // 행렬 전치.
        data.viewMatrix = Matrix4::Transpose(data.viewMatrix);

        // 데이터 담아서 버퍼 생성.
        D3D11_BUFFER_DESC bufferDesc = {};
        bufferDesc.ByteWidth = sizeof(CameraBuffer);
        bufferDesc.Usage = D3D11_USAGE_DYNAMIC;
        bufferDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
        bufferDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;

        // 버퍼 데이터.
        D3D11_SUBRESOURCE_DATA bufferData = {};
        bufferData.pSysMem = &data;

        // 버퍼 생성.
        ID3D11Device& device = Engine::Get().Device();
        ThrowIfFailed(device.CreateBuffer(&bufferDesc, &bufferData, &cameraBuffer), TEXT("Failed to create camera buffer."));

    }
    void CameraComponent::Draw()
    {
        Component::Draw();

        // 뷰행렬 업데이트 및 바인딩.
        data.viewMatrix = 
            Matrix4::Translation(owner->transform.position * -1.0f) 
            * Matrix4::Transpose(Matrix4::Rotation(owner->transform.rotation));

        static ID3D11DeviceContext& context = Engine::Get().Context();

        // 전치 행렬. (CPU와 GPU가 행렬을 다루는 방식이 달라서).
        // 행기준 행렬을 열기준 행렬로 변환하기 위해 전치행렬 처리.
        data.viewMatrix= Matrix4::Transpose(data.viewMatrix);

        // 버퍼 업데이트.
        //context.UpdateSubresource(constantBuffer, 0u, nullptr, &transformMatrix, 0u, 0u); //cpu에 권한 준 장점을 활용 못함.
        D3D11_MAPPED_SUBRESOURCE resource = {};
        context.Map(cameraBuffer, 0u, D3D11_MAP_WRITE_DISCARD, 0u, &resource);    // D3D11_MAP_WRITE_DISCARD -> GPU가 읽고 CPU가 쓸 때 사용.
        //resource.pData = &transformMatrix; // 결국 복사하므로 memcpy가 조금 더 빠름.
        memcpy(resource.pData, &data, sizeof(CameraBuffer));
        context.Unmap(cameraBuffer, 0u);

        // 버퍼 바인딩.
        context.VSSetConstantBuffers(1u, 1u, &cameraBuffer);

    }
}
