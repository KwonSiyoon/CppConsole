#include "Engine.h"
#include "Window.h"
#include "../Render/Renderer.h"

namespace Blue 
{
    // 싱글톤 객체 설정.
    Engine* Engine::instance = nullptr;

    Engine::Engine(uint32 width, uint32 height, const std::wstring& title, HINSTANCE hInstance)
    {
        // 싱글톤 객체 값 설정.
        instance = this;

        // 창 객체 생성.
        window = std::make_shared<Window>(width, height, title, hInstance, WindowProc);

        // 렌더러 생성.
        renderer = std::make_shared<Renderer>(width, height, window->Handle());

    }
    Engine::~Engine()
    {
    }
    LRESULT Engine::WindowProc(HWND handle, UINT message, WPARAM wparam, LPARAM lparam)
    {
        // 메시지 처리.
        switch (message)
        {
            // 창이 삭제되면 실행됨.
        case WM_DESTROY:
            // 이때 프로그램 종료 메시지를 발행.
            PostQuitMessage(0);
            return 0;
            break;
        default:
            break;
        }

        // 기본 메시지 처리.
        return DefWindowProc(handle, message, wparam, lparam);
    }
    void Engine::Run()
    {
        // 메시지 처리 루프.
        MSG msg = {};
        while (msg.message != WM_QUIT)
        {
            // 창에 메시지가 들어올 때 실행.
            if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
            {
                // 번역 후 전달해야 올바르게 전달이 됨.
                // 메시지 번역.
                TranslateMessage(&msg);

                // 메세지 전달.
                DispatchMessage(&msg);
            }
            else // 창에 메시지가 없을 때 다른 작업 처리.
            {
                // 엔진 루프.
                renderer->Draw();
            }
        }
    }
    Engine& Engine::Get()
    {
        return *instance;
    }
    ID3D11Device& Engine::Device() const
    {
        return *renderer->device;
    }
    ID3D11DeviceContext& Engine::Context() const
    {
        return *renderer->context;
    }
}