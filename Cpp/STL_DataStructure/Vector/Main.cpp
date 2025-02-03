#include <vector>
#include <iostream>

int main()
{
    // vector 변수 선언.
    std::vector<int> vector;


    // 비었는지 확인.
    // if(vector.size() == 0)
    if (vector.empty())
    {
        std::cout << "vector가 비었음.\n";
    }


    // 자료 삽입.
    for (int i = 0; i < 1000; ++i)
    {
        vector.emplace_back(i);
    }

    // 요소 삭제.
    for (auto iter = vector.begin(); iter != vector.end(); )
    {
        iter = vector.erase(iter);
        if (std::distance(iter, vector.end()) >= 9)
        {
            //std::advance(iter, 10);
            iter += 9;
        }
    }
    
    // 오류남. erase의 작동방식에 대한 이해 필요.
    //for (int i = 0; i < 1000; i += 10)
    //{
    //    // 삭제를 원하는 위치의 반복자(iterator) 저장.
    //    auto iterator = vector.begin() + i;

    //    // 앞에서 구한 반복자를 활용해 배열 원소 삭제.
    //    vector.erase(iterator);
    //}


    // 모두 소거.
    // 내부 저장 변수가 포인터인 경우에는 delete를 직접 해주어야함.
    vector.clear();

    // 비었는지 확인.
    if (vector.empty())
    {
        std::cout << "vector가 비었음.\n";
    }

    // 크기 조정.
    vector.resize(0);

    // 공간 확보.
    // 재할당 방지 목적 / 공간 최적화.
    vector.reserve(0);

    vector.shrink_to_fit();

    std::cin.get();

}