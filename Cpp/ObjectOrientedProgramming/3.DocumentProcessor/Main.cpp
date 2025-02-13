#include <iostream>

#include "Document.h"
#include "DocumentProcessor.h"

#include "TranslateIntoFrenchProcess.h"
#include "RepaginateProcess.h"
#include "SpellcheckProcess.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

//// 문서 처리자를 구성하는 함수.
//DocumentProcessor* Configure()
//{
//    DocumentProcessor* processor = new DocumentProcessor();
//    processor->GetProcesses().emplace_back(new TranslateIntoFrenchProcess());
//    processor->GetProcesses().emplace_back(new SpellcheckProcess());
//    processor->GetProcesses().emplace_back(new RepaginateProcess());
//
//    return processor;
//}

DocumentProcessor* Configure()
{
    DocumentProcessor* processor = new DocumentProcessor();
    processor->AddDocumentProcess(DocumentProcess::TranslateIntoFrench);
    processor->AddDocumentProcess(DocumentProcess::SpellCheck);
    processor->AddDocumentProcess(DocumentProcess::Repaginate);

    return processor;
}


int main()
{

    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    // 문서 객체 생성.
    Document doc1("Jake", "2025.02.13", "C++ Programming");
    Document doc2("Ian", "2024.01.31", "Hello Iphone");

    // 문서 처리자 객체 생성 (팩토리 패턴).
    DocumentProcessor* processor = Configure();

    // 문서 처리.
    std::cout << "문서1 처리\n";
    processor->Process(doc1);
    std::cout << "\n";
    std::cout << "문서2 처리\n";
    processor->Process(doc2);
    std::cout << "\n";

    // 메모리 해제.
    delete processor;

    std::cin.get();
}