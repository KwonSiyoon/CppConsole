//#pragma once
//
//#include "Document.h"
//#include "DocumentProcess.h"
//
//// 문서를 처리하는 처리자.
//class DocumentProcessor
//{
//public:
//    static void Process(const Document& document)
//    {
//        DocumentProcess::TranslateIntoFrench(document);
//        DocumentProcess::SpellCheck(document);
//        DocumentProcess::Repaginate(document);
//    }
//};

#pragma once

#include "IDocumentProcess.h"
#include "DocumentProcess.h"

#include <vector>
#include <functional>

// 문서를 처리하는 처리자 클래스.
class DocumentProcessor
{
public:
    /*std::vector<IDocumentProcess*>& GetProcesses() { return processes; }

    ~DocumentProcessor()
    {
        for (IDocumentProcess* process : processes)
        {
            delete process;
        }
    }

    void Process(const Document& doc)
    {
        for (IDocumentProcess* process : processes)
        {
            process->Process(doc);
        }
    }*/
    void AddDocumentProcess(std::function<void(const Document&)> process)
    {
        processes.emplace_back(process);
    }

    void Process(const Document& doc)
    {
        for (const std::function<void(const Document&)>& process : processes)
        {
            process(doc);
        }
    }


    


private:
    //std::vector<IDocumentProcess*> processes;
    std::vector<std::function<void(const Document&)>> processes;
};