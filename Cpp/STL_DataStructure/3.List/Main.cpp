#include <iostream>
#include <list>
#include <algorithm>


// 아이템 구조체
struct Item
{
    Item(int code = 0, int price = 0)
        : code(code), price(price)
    {
    }

    int code = 0;           // 아이템 코드.
    int price = 0;          // 아이템 가격.
};


// 데이터 출력용 연산자 오버로딩.
std::ostream& operator<<(std::ostream& os, const Item& item)
{
    return os << "코드: " << item.code << ", 가격: " << item.price;
}

// 아이템 코드를 기준으로 정렬하는 함수 객체(Functor).
struct ItemLessComparer
{
    bool operator()(const Item& left, const Item& right)
    {
        return left.code < right.code;
    }
};


int main()
{
    // 리스트 생성.
    std::list<Item> itemList;

    // 데이터 추가.
    itemList.emplace_front(Item(1, 200));
    itemList.emplace_front(Item(2, 1000));

    // 뒤에 추가.
    itemList.emplace_back(Item(3, 300));
    itemList.emplace_back(Item(4, 4400));

    // 출력.
    for (std::list<Item>::iterator iter = itemList.begin(); iter != itemList.end(); ++iter)
    {
        std::cout << *iter << "\n";
    }


    // 삭제.
    itemList.pop_front();

    // 맨 앞에 있는 데이터 읽기.
    Item& frontItem = itemList.front();
    std::cout << "------ 맨 앞 데이터 읽음. ------ \n";
    std::cout << frontItem << "\n";

    itemList.emplace_back(Item(7, 7400));
    itemList.emplace_back(Item(8, 4800));
    itemList.emplace_back(Item(6, 3600));
    itemList.emplace_back(Item(5, 500));



    std::cout << "------ 전체 출력. ------\n";
    // 출력.
    for (std::list<Item>::iterator iter = itemList.begin(); iter != itemList.end(); ++iter)
    {
        std::cout << *iter << "\n";
    }

    // 정렬.
    ItemLessComparer lessComparer;
    itemList.sort(lessComparer);
    std::cout << "------ 정렬 후 출력. ------ \n";
    // 출력.
    for (std::list<Item>::iterator iter = itemList.begin(); iter != itemList.end(); ++iter)
    {
        std::cout << *iter << "\n";
    }

    // 정렬2.
    itemList.sort(
        [](const Item& left, const Item& right) 
        {
        return left.code > right.code;
        }
    );
    std::cout << "------ 정렬2 후 출력. ------ \n";
    // 출력.
    for (std::list<Item>::iterator iter = itemList.begin(); iter != itemList.end(); ++iter)
    {
        std::cout << *iter << "\n";
    }

    // 정렬3. algorithm 헤더의 sort에 List는 포함이 안되어있음.
    //std::sort(itemList.begin(), itemList.end(), lessComparer);
    //std::cout << "------ 정렬3 후 출력. ------ \n";
    //// 출력.
    //for (std::list<Item>::iterator iter = itemList.begin(); iter != itemList.end(); ++iter)
    //{
    //    std::cout << *iter << "\n";
    //}

    std::cin.get();

}
