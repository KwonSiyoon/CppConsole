﻿#include "Renderer.h"
#include "Core/Common.h"    
#include "Level/Level.h"
#include "Actor/Actor.h"

#include "RenderTexture.h"
#include "Resource/TextureLoader.h"
#include "Component/StaticMeshComponent.h"

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
		swapChainDesc.Windowed = true;                  // 창 모드.
		swapChainDesc.OutputWindow = window;
		swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
		swapChainDesc.BufferCount = 2;                  // 백버퍼 개수.
		swapChainDesc.SampleDesc.Count = 1;             // 멀티 샘플링 개수.
		swapChainDesc.SampleDesc.Quality = 0;           // 멀티 샘플링 수준.
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

        backbuffer->Release();
        backbuffer = nullptr;

        // 뎁스 스텐실 뷰 생성.
        ID3D11Texture2D* depthStencilBuffer = nullptr;
        D3D11_TEXTURE2D_DESC depthStencilDesc = {};
        depthStencilDesc.Width = width;
        depthStencilDesc.Height = height;
        depthStencilDesc.MipLevels = 1;
        depthStencilDesc.ArraySize = 1;
        depthStencilDesc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
        depthStencilDesc.SampleDesc.Count = 1;
        depthStencilDesc.SampleDesc.Quality = 0;
        depthStencilDesc.BindFlags = D3D11_BIND_DEPTH_STENCIL;

        // 2차원 리소스 생성.
        ThrowIfFailed(device->CreateTexture2D(&depthStencilDesc, nullptr, &depthStencilBuffer), TEXT("Failed to create depth stencil buffer."));

        D3D11_DEPTH_STENCIL_VIEW_DESC depthStencilViewDesc = {};
        depthStencilViewDesc.Format = depthStencilDesc.Format;
        depthStencilViewDesc.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2D;

        // 뷰 생성.
        ThrowIfFailed(device->CreateDepthStencilView(depthStencilBuffer, &depthStencilViewDesc, &depthStencilView), TEXT("Failed to create depth stencil view."));

        // 사용한 리소스 해제.
        depthStencilBuffer->Release();
        depthStencilBuffer = nullptr;


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
        if (context)
        {
            context->ClearState();
            context->Flush();
            context->Release();
            context = nullptr;
        }
        if (swapChain)
        {
            swapChain->Release();
            swapChain = nullptr;
        }
        if (renderTargetView)
        {
            renderTargetView->Release();
            renderTargetView = nullptr;
        }

        if (depthStencilView)
        {
            depthStencilView->Release();
            depthStencilView = nullptr;
        }

        //ID3D11Debug* debug = nullptr;
        //device->QueryInterface(IID_PPV_ARGS(&debug));
        if (device)
        {
            device->Release();
            device = nullptr;
        }

        /*mesh.reset();
        mesh2.reset();
        mesh3.reset();*/

        /*debug->ReportLiveDeviceObjects(D3D11_RLDO_DETAIL | D3D11_RLDO_IGNORE_INTERNAL);
        debug->Release();*/
	}
	void Renderer::Draw(std::shared_ptr<Level> level)
	{
        // 화면 크기 변경 중일 때는 중단.
        if (isResizing)
        {
            return;
        }

        // Pass-1.
        for (int ix = 0; ix < (int)TextureLoader::Get().renderTextures.size(); ++ix)
        {
            // 그리기 전단계
            // 렌더 텍스처 가져오기.
            auto renderTexture = TextureLoader::Get().renderTextures[ix];

            //EmptyRTVsAndSRVs();

            // 렌더 타겟 설정.
            context->OMSetRenderTargets(1, renderTexture->GetRenderTargetAddress(), renderTexture->GetDepthStencilView());


            // 지우기(Clear)
            float color[] = { 1.0f, 1.0f, 1.0f, 1.0f };
            context->ClearRenderTargetView(renderTexture->GetRenderTarget(), color);
            context->ClearDepthStencilView(renderTexture->GetDepthStencilView(), D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);         // memset 하는 것.

            // 그리기
            // 드로우(Draw). Draw
            // 카메라 바인딩.
            if (level->GetCamera())
            {
                level->GetCamera()->Draw();
            }

            for (uint32 actorIndex = 0; actorIndex < level->ActorCount(); actorIndex++)
            {
                // 액터 가져오기.
                auto actor = level->GetActor(actorIndex);

                // 렌더 텍스처 사용 여부 확인.
                auto meshComponent = actor->GetComponent<StaticMeshComponent>();
                if (meshComponent && meshComponent->UseRenderTexture())
                {
                    continue;
                }

                // Draw.
                if (actor->IsActive())
                {
                    actor->Draw();
                }
            }
        }

        // Final-Pass.
		// 그리기 전 작업. BeginScene
        //EmptyRTVsAndSRVs();

		context->OMSetRenderTargets(1, &renderTargetView, depthStencilView);

		// 지우기(Clear)
		float color[] = { 0.6f, 0.7f, 0.8f, 1.0f };
		context->ClearRenderTargetView(renderTargetView, color);
        context->ClearDepthStencilView(depthStencilView, D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);         // memset 하는 것.


		// 드로우(Draw). Draw
        // 카메라 바인딩.
        if (level->GetCamera())
        {
            level->GetCamera()->Draw();
        }

        for (uint32 ix = 0; ix < level->ActorCount(); ix++)
        {
            // 액터 가져오기.
            auto actor = level->GetActor(ix);

            // Draw.
            if (actor->IsActive())
            {
                //for (const auto& component : actor->components)
                //{
                //    // Check if component i drawable.
                //}
                actor->Draw();
            }
        }

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
    void Renderer::OnResize(uint32 width, uint32 height)
    {
        // 창 변경으로 인한 리소스 크기 조정.
        if (!device || !context || !swapChain)
        {
            return;
        }

        isResizing = true;
        
        // context 비우기.
        context->ClearState();
        context->Flush();

        // 렌더타겟 해제.
        if (renderTargetView)
        {
            renderTargetView->Release();
            renderTargetView = nullptr;
        }

        // 뎁스 스텐실 뷰 해제.
        if (depthStencilView)
        {
            depthStencilView->Release();
            depthStencilView = nullptr;
        }

        // 스왑체인 백버퍼 크기 변경.
        // BufferCount에 0을 넣으면 쓰고있던 개수를 자동으로 넣어줌.
        ThrowIfFailed(swapChain->ResizeBuffers(0, width, height, DXGI_FORMAT_B8G8R8A8_UNORM, 0), TEXT("Failed to resize swapchain buffer."));

        // 렌더타겟 재생성.
        ID3D11Texture2D* backbuffer = nullptr;
        ThrowIfFailed(swapChain->GetBuffer(0, IID_PPV_ARGS(&backbuffer)), TEXT("Failed to get buffer from swapchain."));
        ThrowIfFailed(device->CreateRenderTargetView(backbuffer, nullptr, &renderTargetView), TEXT("Failed to created render target view."));
        backbuffer->Release();
        backbuffer = nullptr;

        // 뎁스 스텐실 뷰 생성.
        ID3D11Texture2D* depthStencilBuffer = nullptr;
        D3D11_TEXTURE2D_DESC depthStencilDesc = {};
        depthStencilDesc.Width = width;
        depthStencilDesc.Height = height;
        depthStencilDesc.MipLevels = 1;
        depthStencilDesc.ArraySize = 1;
        depthStencilDesc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
        depthStencilDesc.SampleDesc.Count = 1;
        depthStencilDesc.SampleDesc.Quality = 0;
        depthStencilDesc.BindFlags = D3D11_BIND_DEPTH_STENCIL;

        // 2차원 리소스 생성.
        ThrowIfFailed(device->CreateTexture2D(&depthStencilDesc, nullptr, &depthStencilBuffer), TEXT("Failed to create depth stencil buffer."));

        D3D11_DEPTH_STENCIL_VIEW_DESC depthStencilViewDesc = {};
        depthStencilViewDesc.Format = depthStencilDesc.Format;
        depthStencilViewDesc.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2D;

        // 뷰 생성.
        ThrowIfFailed(device->CreateDepthStencilView(depthStencilBuffer, &depthStencilViewDesc, &depthStencilView), TEXT("Failed to create depth stencil view."));

        // 사용한 리소스 해제.
        depthStencilBuffer->Release();
        depthStencilBuffer = nullptr;

        // 뷰포트 업데이트.
        // 뷰포트(화면).
        viewport.TopLeftX = 0.0f;
        viewport.TopLeftY = 0.0f;
        viewport.Width = (float)width;
        viewport.Height = (float)height;
        viewport.MaxDepth = 1.0f;
        viewport.MinDepth = 0.0f;

        // 뷰포트 설정.
        context->RSSetViewports(1, &viewport);
        
        isResizing = false;
    }
    void Renderer::EmptyRTVsAndSRVs()
    {
        static ID3D11RenderTargetView* nullRTV[8] = {};
        context->OMSetRenderTargets(8, nullRTV, nullptr);

        static ID3D11ShaderResourceView* nullSRVs[16] = {};
        context->PSSetShaderResources(0, _countof(nullSRVs), nullSRVs);
    }
}