#pragma once

#include <iostream>
#include "Document.h"

// Document를 처리하는 Utility 클래스.
// 맞춤법 검사, 페이지 재설정, 번역 기능 포함.
class DocumentProcess
{
public:
    static void SpellCheck(const Document& document)
    {
        std::cout << "문서 맞춤법 검사 완료.\n" << document.GetAuthor() << "\n";
        
    }
    static void Repaginate(const Document& document)
    {
        std::cout << "문서 페이지 재설정 완료.\n";
    }

    static void TranslateIntoFrench(const Document& document)
    {
        std::cout << "프랑스어로 번역 완료.\n";
    }

};