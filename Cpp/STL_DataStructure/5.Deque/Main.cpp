#include <deque>
#include <iostream>

int main()
{
    // 덱 선언.
    std::deque<int> deque;

    // 데이터 추가.
    deque.emplace_back(100);
    deque.emplace_front(200);

    for (int i = 0; i < (int)deque.size(); ++i)
    {
        std::cout << deque[i] << "\n";
    }

    std::cout << "\n";

    for (auto iter = deque.begin(); iter != deque.end(); ++iter)
    {
        std::cout << *iter << "\n";
    }

    std::cout << "\n";
    // 데이터 추출.
    auto data = deque.back();
    // 데이터 제거.
    deque.pop_back();

    std::cout << data << "\n";

    std::cout << "\n";
    for (auto& value : deque)
    {
        std::cout << value << "\n";
    }

    deque.clear();
    std::cout << "\n";
    if(deque.empty())
    {
        std::cout << "덱이 비었습니다.\n";
    }


    std::cin.get();
}