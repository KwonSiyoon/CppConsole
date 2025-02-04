#include <iostream>
#include <unordered_map>

// 게임 캐릭터 클래스.
class GameCharacter
{
public:
    GameCharacter() = default;
    GameCharacter(int code, int level, int money)
        : code(code), level(level), money(money)
    {

    }

    // Getter.
    const int Code() const { return code; }
    const int Level() const { return level; }
    const int Money() const { return money; }

    // 출력을 위한 연산자 오버로딩.
    friend std::ostream& operator<<(std::ostream& os, const GameCharacter& character)
    {
        return os << "코드: " << character.code << " | 레벨: " << character.level << " | 돈: " << character.money << "\n";
    }

private:
    int code;
    int level;
    int money;
};

void Find(int num, std::unordered_map<int, GameCharacter> characters)
{
    // 검색.
    auto iter = characters.find(num);

    // 검색에 성공했는지 확인.
    if (iter != characters.end())
    {
        // 캐릭터 정보 출력.
        std::cout << iter->second << "\n";
    }
    else
    {
        std::cout << "Error: 검색 실패.\n\n";
    }
}


int main()
{
    // 해시테이블 선언.
    std::unordered_map<int, GameCharacter> characters;

    // 데이터 추가.
    GameCharacter character1(10, 1, 30000);
    GameCharacter character2(11, 2, 40000);
    GameCharacter character3(14, 5, 50000);
    characters.insert(std::make_pair(character1.Code(), character1));           // insert 방법 1
    characters.insert({character2.Code(), character2});                         // insert 방법 2
    std::pair<int, GameCharacter> pair(character3.Code(), character3);          // insert 방법 3
    characters.insert(pair);

    for (int i = 15; i < 100; ++i)
    {
        GameCharacter character(i, i, i * 1000);
        characters.insert({ character.Code(), character });
    }

    //// 검색.
    //auto iter = characters.find(10);

    //// 검색에 성공했는지 확인.
    //if (iter != characters.end())
    //{
    //    // 캐릭터 정보 출력.
    //    std::cout << iter->second << "\n";
    //}
    //else
    //{
    //    std::cout << "Error: 검색 실패.\n\n";
    //}

    Find(10, characters);
    Find(20, characters);
    Find(30, characters);
    Find(0, characters);

    // 검색2
    auto result = characters[0];            // 검색 실패하면 새로 default로 만들고 반환.
    std::cout << result << "검색2-1\n";    
    
    result = characters[20];                // 검색 실패했는지를 모름
    std::cout << result << "검색2-2\n";    


    // 출력.
    for (auto& pair : characters)
    {
        std::cout << "캐릭터 정보 " << pair.second;
    }

    std::cin.get();
}


