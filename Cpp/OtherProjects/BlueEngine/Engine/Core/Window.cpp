﻿#include "Window.h"

namespace Blue
{
    Window::Window(uint32 width, uint32 height, const std::wstring& title, HINSTANCE instance, WNDPROC messageProcedure)
        : width(width), height(height), title(title), instance(instance)
    {
        // 창 생성에 필요한 설정 구조체.
        WNDCLASS wc = { };

        // 메시지 처리를 위한 콜백 전달.
        wc.lpfnWndProc = messageProcedure;

        // 프로그램 주소 전달.
        wc.hInstance = instance;

        // 창 생성에 사용할 클래스 이름 전달.
        wc.lpszClassName = className.c_str();
        
        // 클래스 등록.
        if (!RegisterClass(&wc))
        {
            // 오류 메시지 확인.
            //auto error = GetLastError();

            // 메시지 출력 #1 - 출력창(output) 이용.
            OutputDebugStringA("창 등록 실패\n");

            // #2 - 메시지 박스 이용.
            MessageBoxA(nullptr, "창 등록 실패", "오류", MB_OKCANCEL);

            // 중단점 설정.
            __debugbreak();
        }

        // 화면 가운데 위치 설정.
        unsigned int positionX = (GetSystemMetrics(SM_CXSCREEN) - width) / 2;
        unsigned int positionY = (GetSystemMetrics(SM_CYSCREEN) - height) / 2;

        // 창 크기 조정.
        RECT rect = { 0, 0, (long)width, (long)height };
        // 제목 포함 1280x800인걸 클라이언트 크기만 1280x800인 창으로 만들기.
        AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, FALSE);    
        // GetClientRect - 제목쪽 크기를 제외한 내부 창 크기 가져오기.

        // 창 크기 재설정.
        unsigned int windowWidth = rect.right - rect.left;
        unsigned int windowHeight = rect.bottom - rect.top;

        // 생성.
        handle = CreateWindow(
            //0,                              // Optional window styles. CreateWindowEx를 사용할때만 필요.
            className.c_str(),                      // Window class
            title.c_str(),                  // Window text         // 창 이름.
            WS_OVERLAPPEDWINDOW,            // Window style

            // Size and position
            // x , y , nWidth, nHeight
            //CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
            //positionX, positionY, width, height,
            positionX, positionY, windowWidth, windowHeight,

            nullptr,       // Parent window        // 창 안에 창 넣을때 부모 지정.
            nullptr,       // Menu
            instance,  // Instance handle      // 프로그램 주소
            nullptr        // Additional application data 
        );


        // 실패시 오류 메시지 출력.
        if (handle == nullptr)
        {
            // 메시지 출력 #1 - 출력창(output) 이용.
            OutputDebugStringA("창 생성 실패\n");

            // #2 - 메시지 박스 이용.
            MessageBoxA(nullptr, "창 생성 실패", "오류", MB_OKCANCEL);

            // 중단점 설정.
            __debugbreak();

        }

        // 창 보이기
        ShowWindow(handle, SW_SHOW);

        // 창 메시지 업데이트.
        UpdateWindow(handle);
    }
    Window::~Window()
    {
        // 클래스 등록 해제.
        UnregisterClass(className.c_str(), instance);
    }
    void Window::SetWidthHeight(uint32 width, uint32 height)
    {
        this->width = width;
        this->height = height;
    }
}