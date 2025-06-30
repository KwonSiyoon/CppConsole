

#include <iostream>
#include <cstdint>
#include <windows.h>

class Base
{
public:
    virtual void A() {}
};

int main()
{
    int arr[10000000];

    Base* obj = new Base();
    void** vtable = *(void***)obj;

    // 함수 포인터 유효성 검사용: 주소가 이 범위 내면 유효한 함수일 확률이 높음
    MEMORY_BASIC_INFORMATION mbi;
    SIZE_T totalSize = 0;

    for (int i = 0; i < 64; ++i)
    {
        void* funcPtr = vtable[i];

        // 유효한 메모리인지 확인
        if (VirtualQuery(funcPtr, &mbi, sizeof(mbi)) == 0) break;
        if (mbi.State != MEM_COMMIT) break;
        if ((mbi.Protect & PAGE_EXECUTE_READ) == 0 &&
            (mbi.Protect & PAGE_EXECUTE_READWRITE) == 0 &&
            (mbi.Protect & PAGE_EXECUTE) == 0 &&
            (mbi.Protect & PAGE_EXECUTE_WRITECOPY) == 0)
        {
            break;
        }

        totalSize += sizeof(void*);
    }

    std::cout << "Estimated vtable size in bytes: " << totalSize << " bytes\n";

    delete obj;
    return 0;
}



//#include <iostream>
//#include <typeinfo>
//#include <cstdint>
//#include <cstring>
//
//class VirtualBase
//{
//public:
//    virtual void FuncA() { std::cout << "VirtualBase::FuncA()\n"; }
//    virtual void FuncB() { std::cout << "VirtualBase::FuncB()\n"; }
//};
//
//class VirtualDerived : public VirtualBase
//{
//public:
//    void FuncA() override { std::cout << "VirtualDerived::FuncA()\n"; }
//    void FuncB() override { std::cout << "VirtualDerived::FuncB()\n"; }
//    virtual void FuncC() { std::cout << "VirtualDerived::FuncC()\n"; }
//};
//
//typedef void(*VFuncPtr)();
//
//int main()
//{
//    VirtualBase* base = new VirtualDerived();
//
//    std::cout << "--- RTTI ---" << std::endl;
//    std::cout << "typeid(*base): " << typeid(*base).name() << std::endl;
//
//    std::cout << "\n--- VTable Info ---" << std::endl;
//
//    // vptr은 객체의 첫 8바이트 (64bit 기준)
//    std::uintptr_t* vptr = *(std::uintptr_t**)base;
//    std::cout << "vptr address: " << vptr << std::endl;
//
//    // vtable에서 함수 포인터를 몇 개나 가져올 수 있는지 확인
//    std::cout << "vtable function pointers:" << std::endl;
//
//    for (int i = 0; i < 10; ++i)
//    {
//        if (vptr[i] == 0) break;  // null pointer로 종료
//        std::cout << " [" << i << "]: " << (void*)vptr[i] << std::endl;
//
//        VFuncPtr func = reinterpret_cast<VFuncPtr>(vptr[i]);
//        //func(); // 실제 함수 실행도 가능 (주의!)
//    }
//
//    delete base;
//    return 0;
//}


//#include <iostream>
//#include <typeinfo>
//#include <cstdint>
//
//// 가상 함수 없음
//class NoVirtualBase
//{
//public:
//    void Func() {}
//};
//
//class NoVirtualDerived : public NoVirtualBase
//{
//public:
//    void Func2() {}
//};
//
//// 가상 함수 있음
//class VirtualBase
//{
//public:
//    virtual void Func() {}
//};
//
//class VirtualDerived : public VirtualBase
//{
//public:
//    void Func() override {}
//};
//
//int main()
//{
//    std::cout << "--- [1] 가상 함수 없는 클래스 ---" << std::endl;
//    NoVirtualBase* nvBase = new NoVirtualDerived();
//
//    std::cout << "typeid(*nvBase).name(): " << typeid(*nvBase).name() << std::endl;
//    std::cout << "sizeof(NoVirtualBase): " << sizeof(NoVirtualBase) << std::endl;
//    std::cout << "sizeof(NoVirtualDerived): " << sizeof(NoVirtualDerived) << std::endl;
//
//    std::cout << "\n--- [2] 가상 함수 있는 클래스 ---" << std::endl;
//    VirtualBase* vBase = new VirtualDerived();
//
//    std::cout << "typeid(*vBase).name(): " << typeid(*vBase).name() << std::endl;
//    std::cout << "sizeof(VirtualBase): " << sizeof(VirtualBase) << std::endl;
//    std::cout << "sizeof(VirtualDerived): " << sizeof(VirtualDerived) << std::endl;
//
//    delete nvBase;
//    delete vBase;
//
//    return 0;
//}
