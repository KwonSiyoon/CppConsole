//#include <Windows.h>
//
//#include "Core/Window.h"
//#include "Render/Renderer.h"
#include "Core/Engine.h"
#include <iostream>

#include "Math/Vector2.h"

using namespace Blue;
#pragma region surplus



//// 창에 관련된 메시지를 처리하는 콜백 함수.
//LRESULT CALLBACK WindowProc(HWND handle, UINT message, WPARAM wparam, LPARAM lparam)
//{
//    // 메시지 처리.
//    switch (message)
//    {
//        // 창이 삭제되면 실행됨.
//    case WM_DESTROY:
//        // 이때 프로그램 종료 메시지를 발행.
//        PostQuitMessage(0);
//        return 0;
//        break; 
//    default:
//        break;
//    }
//
//    // 기본 메시지 처리.
//    return DefWindowProc(handle, message, wparam, lparam);
//
//}


// 창 모드로 할 때 메인 함수(Entry Point).
// 콘솔 모드에서의 int main(){}의 역할.
//int WINAPI WinMain(
//    _In_ HINSTANCE hInstance,
//    _In_opt_ HINSTANCE hPrevInstance,
//    _In_ LPSTR lpCmdLine,
//    _In_ int nShowCmd
//)
//{
//    /*
//    // 창 만들기
//    // https://learn.microsoft.com/ko-kr/windows/win32/learnwin32/creating-a-window 참조.
//    // 창 메시지
//    // https://learn.microsoft.com/ko-kr/windows/win32/learnwin32/window-messages 참조.
//    // Register the window class.
//
//    
//    //// 창에 사용할 클래스 이름.
//    ////const wchar_t* className = L"Sample Window Class";
//    //const wchar_t* className = TEXT("Sample Window Class");
//
//    //// 창 생성에 필요한 설정 구조체.
//    //WNDCLASS wc = { };
//
//
//    //// 메시지 처리를 위한 콜백 전달.
//    //wc.lpfnWndProc = WindowProc;
//    //
//    //// 프로그램 주소 전달.
//    //wc.hInstance = hInstance;
//
//    //// 창 생성에 사용할 클래스 이름 전달.
//    //wc.lpszClassName = className;
//
//    //// 클래스 등록.
//    //if (!RegisterClass(&wc))
//    //{
//    //    // 오류 메시지 확인.
//    //    auto error = GetLastError();
//
//    //    // 메시지 출력 #1 - 출력창(output) 이용.
//    //    OutputDebugStringA("창 등록 실패\n");
//
//    //    // #2 - 메시지 박스 이용.
//    //    MessageBoxA(nullptr, "창 등록 실패", "오류", MB_OKCANCEL);
//
//    //    // 중단점 설정.
//    //    __debugbreak();
//    //}
//
//    //// 창의 가로 크기.
//    //unsigned int width = 1280;
//    //unsigned int height = 800;
//    //// 화면 가운데 위치 설정.
//    //unsigned int positionX = (GetSystemMetrics(SM_CXSCREEN) - width) / 2;
//    //unsigned int positionY = (GetSystemMetrics(SM_CYSCREEN) - height) / 2;
//
//    //// 창 크기 조정.
//    //RECT rect = { 0, 0, (long)width, (long)height };
//    //AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, FALSE);
//
//    //// 창 크기 재설정.
//    //unsigned int windowWidth = rect.right - rect.left;
//    //unsigned int windowHeight = rect.bottom- rect.top;
//
//    //// 생성.
//    //HWND hwnd = CreateWindow(
//    //    //0,                              // Optional window styles. CreateWindowEx를 사용할때만 필요.
//    //    className,                      // Window class
//    //    TEXT("Blue Engine Demo"),    // Window text         // 창 이름.
//    //    WS_OVERLAPPEDWINDOW,            // Window style
//
//    //    // Size and position
//    //    // x , y , nWidth, nHeight
//    //    //CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
//    //    //positionX, positionY, width, height,
//    //    positionX, positionY, windowWidth, windowHeight,
//
//    //    nullptr,       // Parent window        // 창 안에 창 넣을때 부모 지정.
//    //    nullptr,       // Menu
//    //    hInstance,  // Instance handle      // 프로그램 주소
//    //    nullptr        // Additional application data 
//    //);
//
//
//    //// 실패시 오류 메시지 출력.
//    //if (hwnd == nullptr)
//    //{
//    //    // 메시지 출력 #1 - 출력창(output) 이용.
//    //    OutputDebugStringA("창 생성 실패\n");
//
//    //    // #2 - 메시지 박스 이용.
//    //    MessageBoxA(nullptr, "창 생성 실패", "오류", MB_OKCANCEL);
//
//    //    // 중단점 설정.
//    //    __debugbreak();
//
//    //    return 0;
//    //}
//
//    //// 창 보이기
//    //ShowWindow(hwnd, SW_SHOW);
//
//    //// 창 메시지 업데이트.
//    //UpdateWindow(hwnd);
//    */
//
//    /*
//    //// 창 생성.
//    //Window window(1280, 800, TEXT("Title"), hInstance, WindowProc);
//
//    //// 렌더러 생성.
//    //Renderer renderer(window.Width(), window.Height(), window.Handle());
//
//
//    //// 메시지 처리 루프.
//    //MSG msg = {};
//    //while (msg.message != WM_QUIT)
//    //{
//    //    // 창에 메시지가 들어올 때 실행.
//    //    if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
//    //    {
//    //        // 번역 후 전달해야 올바르게 전달이 됨.
//    //        // 메시지 번역.
//    //        TranslateMessage(&msg);
//
//    //        // 메세지 전달.
//    //        DispatchMessage(&msg);
//    //    }
//    //    else // 창에 메시지가 없을 때 다른 작업 처리.
//    //    {
//    //        // 엔진 루프.
//    //        renderer.Draw();
//    //    }
//    //}
//    */
//
//    // 엔진 생성 및 실행.
//    Engine engine(1280, 800, TEXT("Title"), hInstance);
//    engine.Run();
//
//
//    return 0;
//}

#pragma endregion

#include "Core/Common.h"
#include <typeinfo>
#include "Shader/Shader.h"
#include "Shader/TextureMappingShader.h"

template<typename T, typename std::enable_if<std::is_base_of<Shader, T>::value>::type* = nullptr>
void TestClass()
{
    std::boolalpha(std::cout);
    std::cout << typeid(T).name() << "\n";
    std::cout << std::is_base_of<Shader, T>::value << "\n";
}


int main()
{
    TestClass<TextureMappingShader>();


    //std::cout << "테스트\n";
    
    //ThrowIfFailed(E_FAIL, TEXT("Text"));
    

    Engine engine(1280, 800, TEXT("Title"), GetModuleHandle(nullptr));
    engine.Run();

    // Vector2 테스트.
    /*Vector2 v1(1.0f, 2.0f);
    Vector2 v2(2.0f, 4.0f);

    Vector2 v3 = v1 + v2;
    Vector2 v4 = v1 + 2.0f;

    std::wcout << v3.ToString() << " | " << v4.ToString() << "\n";*/

}