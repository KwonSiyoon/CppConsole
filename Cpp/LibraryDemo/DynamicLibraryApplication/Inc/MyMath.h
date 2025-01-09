#pragma once

#ifdef BUILD_DLL
#define MATH_DLL __declspec(dllexport)
#else
#define MATH_DLL __declspec(dllimport)
#endif


// DLL 라이브러리용 클래스 제작.
// Dynamic Linking Library.
// Dynamic -> RunTime -> 실행중에.
// __declspec(dllexport) -> 외부 공개용으로 설정 MSCompiler.
// __declspec(dllexport) | __declspec(dllimport)
//class __declspec(dllexport) Math
class MATH_DLL Math
{
public:
	static int Add(int a, int b);
	static int Substract(int a, int b);
	static int Multiply(int a, int b);
	static int Divide(int a, int b);
};