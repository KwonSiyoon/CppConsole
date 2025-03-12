#include "Renderer.h"
#include <vector>
#include <d3dcompiler.h>
#include "Math/Vector3.h"
//#include "../Shader/Shader.h"
#include "TriangleMesh.h"
#include "QuadMesh.h"
#include "Core/Common.h"    

namespace Blue
{
	Renderer::Renderer(uint32 width, uint32 height, HWND window)
	{
		// 장치 생성에 사용하는 옵션.
		uint32 flag = 0;

#if _DEBUG
		flag |= D3D11_CREATE_DEVICE_DEBUG;
#endif

		// 생성할 라이브러리 버전.
		D3D_FEATURE_LEVEL featureLevels[] = {
			D3D_FEATURE_LEVEL_11_1,
			D3D_FEATURE_LEVEL_11_0
		};

		// 장치 생성.
		ThrowIfFailed(D3D11CreateDevice(
			nullptr, 
			D3D_DRIVER_TYPE_HARDWARE, 
			nullptr, 
			flag, 
			featureLevels, 
			_countof(featureLevels), 
			D3D11_SDK_VERSION, 
			&device, 
			nullptr,
			&context
		), TEXT("Failed to create devices."));

		IDXGIFactory* factory = nullptr;
		//CreateDXGIFactory(__uuidof(factory), reinterpret_cast<void**>(&factory)); // 정석방법.
		ThrowIfFailed(CreateDXGIFactory(IID_PPV_ARGS(&factory)), TEXT("Failed to create dxgifactory."));    // 매크로 사용 방법.




		// 스왑 체인 정보 구조체.
		//DXGI_MODE_DESC BufferDesc;
		//DXGI_SAMPLE_DESC SampleDesc;
		//DXGI_USAGE BufferUsage;
		//UINT BufferCount;
		//HWND OutputWindow;
		//BOOL Windowed;
		//DXGI_SWAP_EFFECT SwapEffect;
		//UINT Flags;
		DXGI_SWAP_CHAIN_DESC swapChainDesc = {};
		swapChainDesc.Windowed = true;              // 창 모드.
		swapChainDesc.OutputWindow = window;
		swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
		swapChainDesc.BufferCount = 2;              // 백버퍼 개수.
		swapChainDesc.SampleDesc.Count = 1;         // 멀티 샘플링 개수.
		swapChainDesc.SampleDesc.Quality = 0;       // 멀티 샘플링 수준.
		swapChainDesc.BufferDesc.Width = width;
		swapChainDesc.BufferDesc.Height = height;
		swapChainDesc.BufferDesc.Format = DXGI_FORMAT_B8G8R8A8_UNORM;
		swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_FLIP_DISCARD;

		// SwapChain 생성.
		ThrowIfFailed(factory->CreateSwapChain(device, &swapChainDesc, &swapChain), TEXT("Failed to create a swap chain."));

		//// 장치 생성.
		//ThrowIfFailed(D3D11CreateDeviceAndSwapChain(
		//    nullptr,                                    // IDXGIAdapter* pAdapter,
		//    D3D_DRIVER_TYPE_HARDWARE,                   // D3D_DRIVER_TYPE DriverType,
		//    nullptr,                                    // HMODULE Software,
		//    flag,                                       // UINT Flags,
		//    featureLevels,                              // ( FeatureLevels ) CONST D3D_FEATURE_LEVEL* pFeatureLevels,
		//    _countof(featureLevels),                    // UINT FeatureLevels,
		//    D3D11_SDK_VERSION,                          // UINT SDKVersion,
		//    &swapChainDesc,                             // CONST DXGI_SWAP_CHAIN_DESC* pSwapChainDesc,
		//    &swapChain,                                 // IDXGISwapChain** ppSwapChain,
		//    &device,                                    // ID3D11Device** ppDevice,
		//    nullptr,                                    // D3D_FEATURE_LEVEL* pFeatureLevel,
		//    &context                                    // ID3D11DeviceContext** ppImmediateContext
		//), TEXT("Failed to create devices."));

		// 결과 확인.
		/*if (FAILED(result))
		{
			MessageBoxA(nullptr, "Failed to create devices.", "Error", MB_OK);
			__debugbreak();
		}*/

		// 렌더 타겟 뷰 생성.
		ID3D11Texture2D* backbuffer = nullptr;
		//swapChain->GetBuffer(0, __uuidof(backbuffer), reinterpret_cast<void**>(&backbuffer));
		ThrowIfFailed(swapChain->GetBuffer(0, IID_PPV_ARGS(&backbuffer)), TEXT("Failed to get back buffer."));
		/*auto result = swapChain->GetBuffer(0, IID_PPV_ARGS(&backbuffer));
		if (FAILED(result))
		{
			MessageBoxA(nullptr, "Failed to get back buffer.", "Error", MB_OK);
			__debugbreak();
		}*/

		ThrowIfFailed(device->CreateRenderTargetView(backbuffer, nullptr, &renderTargetView), TEXT("Failed to create render target view."));
		/*result = device->CreateRenderTargetView(backbuffer, nullptr, &renderTargetView);
		if (FAILED(result))
		{
			MessageBoxA(nullptr, "Failed to create render target view.", "Error", MB_OK);
			__debugbreak();
		}*/

		// 렌더 타겟 뷰 바인딩(연결). 
		//context->OMSetRenderTargets(1, &renderTargetView, nullptr);


		// 뷰포트(화면).
		viewport.TopLeftX = 0.0f;
		viewport.TopLeftY = 0.0f;
		viewport.Width = (float)width;
		viewport.Height = (float)height;
		viewport.MaxDepth = 1.0f;
		viewport.MinDepth = 0.0f;

		// 뷰포트 설정.
		context->RSSetViewports(1, &viewport);

		//// 정점 데이터 생성.
		//Vector3 vertices[] =
		//{
		//    Vector3(0.0f, 0.5f, 0.5f),
		//    Vector3(0.5f, -0.5f, 0.5f),
		//    Vector3(-0.5f, -0.5f, 0.5f)
		//};

		//// @Temp: 임시 리소스 생성.
		//// 버퍼(Buffer) - 메모리 덩어리.
		//D3D11_BUFFER_DESC vertexBufferDesc = {};
		//vertexBufferDesc.ByteWidth = Vector3::Stride() * 3;
		//vertexBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;

		//// 정점 데이터.
		//D3D11_SUBRESOURCE_DATA vertexData = {};
		//vertexData.pSysMem = vertices;

		//// (정점)버퍼 생성.
		//result = device->CreateBuffer(&vertexBufferDesc, &vertexData, &vertexBuffer);

		//if (FAILED(result))
		//{
		//    MessageBoxA(nullptr, "Failed to create vertex buffer.", "Error", MB_OK);
		//    __debugbreak();
		//}

		//// 인덱스(색인) 버퍼 생성(정점을 조립하는 순서).
		//int indices[] = { 0, 1, 2 };

		//// 버퍼(Buffer) - 메모리 덩어리.
		//D3D11_BUFFER_DESC indexBufferDesc = {};
		//indexBufferDesc.ByteWidth = sizeof(int) * 3;
		//indexBufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;

		//// 인덱스 데이터.
		//D3D11_SUBRESOURCE_DATA indexData = {};
		//indexData.pSysMem = indices;

		//// (인덱스)버퍼 생성.
		//result = device->CreateBuffer(&indexBufferDesc, &indexData, &indexBuffer);
		//if (FAILED(result))
		//{
		//    MessageBoxA(nullptr, "Failed to create index buffer.", "Error", MB_OK);
		//    __debugbreak();
		//}

		//// 쉐이더 컴파일.
		//ID3DBlob* vertexShaderBuffer = nullptr;
		//result = D3DCompileFromFile(TEXT("VertexShader.hlsl"), nullptr, nullptr, "main", "vs_5_0", 0, 0, &vertexShaderBuffer, nullptr);
		//if (FAILED(result))
		//{
		//    MessageBoxA(nullptr, "Failed to compile vertex shader.", "Error", MB_OK);
		//    __debugbreak();
		//}

		//// 쉐이더 생성.
		//result = device->CreateVertexShader(vertexShaderBuffer->GetBufferPointer(), vertexShaderBuffer->GetBufferSize(), nullptr, &vertexShader);
		//if (FAILED(result))
		//{
		//    MessageBoxA(nullptr, "Failed to create vertex shader.", "Error", MB_OK);
		//    __debugbreak();
		//}

		//// 입력 레이아웃.
		//// 정점 쉐이더에 전달할 정점 데이터가 어떻게 생겼는지 알려줌.
		
        /*
		//LPCSTR SemanticName;
		//UINT SemanticIndex;
		//DXGI_FORMAT Format;
		//UINT InputSlot;
		//UINT AlignedByteOffset;
		//D3D11_INPUT_CLASSIFICATION InputSlotClass;
		//UINT InstanceDataStepRate;
		//*/
		//D3D11_INPUT_ELEMENT_DESC inputDesc[] =
		//{
		//    {"POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0}
		//};
		//result = device->CreateInputLayout(inputDesc, 1, vertexShaderBuffer->GetBufferPointer(), vertexShaderBuffer->GetBufferSize(), &inputLayout);
		//if (FAILED(result))
		//{
		//    MessageBoxA(nullptr, "Failed to create input layout.", "Error", MB_OK);
		//    __debugbreak();
		//}

		//// 픽셀 쉐이더 컴파일/생성.
		//// 각 리소스 바인딩.
		//ID3DBlob* pixelShaderBuffer = nullptr;
		//result = D3DCompileFromFile(TEXT("PixelShader.hlsl"), nullptr, nullptr, "main", "ps_5_0", 0u, 0u, &pixelShaderBuffer, nullptr);
		//if (FAILED(result))
		//{
		//    MessageBoxA(nullptr, "Failed to compile pixel shader", "Error", MB_OK);
		//    __debugbreak();
		//}

		//result = device->CreatePixelShader(pixelShaderBuffer->GetBufferPointer(), pixelShaderBuffer->GetBufferSize(), nullptr, &pixelShader);
		//if (FAILED(result))
		//{
		//    MessageBoxA(nullptr, "Failed to compile pixel shader", "Error", MB_OK);
		//    __debugbreak();
		//}

		

	}
	Renderer::~Renderer()
	{
	}
	void Renderer::Draw()
	{
		// 쉐이더 객체 생성.
		if (mesh == nullptr)
		{
			mesh = std::make_unique<QuadMesh>();
			//mesh = std::make_unique<TriangleMesh>();
            mesh->transform.scale = Vector3::One * 0.5f;
            mesh->transform.position.x = 0.5f;
		}

        if (mesh2 == nullptr)
        {
            mesh2 = std::make_unique<QuadMesh>();
            //mesh = std::make_unique<TriangleMesh>();
            mesh2->transform.scale = Vector3::One * 0.5f;
            mesh2->transform.position.x = -0.5f;

        }

        if (mesh3 == nullptr)
        {
            mesh3 = std::make_unique<TriangleMesh>();
            //mesh = std::make_unique<TriangleMesh>();
            mesh3->transform.scale = Vector3::One * 0.5f;
            //mesh3->transform.position.x = -0.5f;

        }

		// 그리기 전 작업. BeginScene
		context->OMSetRenderTargets(1, &renderTargetView, nullptr);


		// 지우기(Clear)
		float color[] = { 0.6f, 0.7f, 0.8f, 1.0f };
		context->ClearRenderTargetView(renderTargetView, color);

		// @Test.
		mesh->Update(1.0f / 60.0f);
		mesh2->Update(1.0f / 60.0f);

		// 드로우(Draw). Draw
		mesh->Draw();
		mesh2->Draw();
		//mesh3->Draw();
		
		
		
		// 리소스 바인딩.
		// 정점 버퍼 전달.
		//static unsigned int stride = Vector3::Stride();
		//static unsigned int offset = 0u;
		//context->IASetVertexBuffers(0u, 1u, &vertexBuffer, &stride, &offset);

		//// 인덱스 버퍼 전달.
		//context->IASetIndexBuffer(indexBuffer, DXGI_FORMAT_R32_UINT, 0u);
		//

		//shader->Bind();
		//// 입력 레이아웃 전달.
		//context->IASetInputLayout(inputLayout);
		//
		//// 조립할 모양 설정.
		//context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

		//// 쉐이더 설정.
		//context->VSSetShader(vertexShader, nullptr, 0u);
		//context->PSSetShader(pixelShader, nullptr, 0u);

		//// 드로우 콜.
		//context->DrawIndexed(3u, 0u, 0);



		// 버퍼 교환. EndScene / Present.
		swapChain->Present(1u, 0u);
	}
}