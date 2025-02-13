#include <stack>
#include <iostream>
#include <vector>

// 미로 탐색에 사용할 좌표 구조체.
struct Location2D
{
    Location2D(int row = 0, int col = 0)
        : row(row), col(col)
    {

    }

    int row;        // 행. 가로줄. y좌표.
    int col;        // 열. 세로줄. x좌표.
};

// 맵 배열.
int mapSize = 0;
std::vector<std::vector<char>> map;
//{
//    /*{'1','1','1','1','1','1'},
//    {'e','0','1','0','0','1'},
//    {'1','0','0','0','1','1'},
//    {'1','0','1','0','1','1'},
//    {'1','0','1','0','0','x'},
//    {'1','1','1','1','1','1'}*/
//};

//"A string\tof ,,tokens\nand some  more tokens";
char seps[] = " ,\n";


bool parseMap(const char* path)
{
    //std::ifstream file(path);
    //std::string mapText;
    char string[256]{};
    char* token{};          // 자르고 남은 문자열.
    char* nextToken{};           // 잘린 문자열.
    char seps[] = " ,\t\n";
    FILE* file = nullptr;
    fopen_s(&file, path, "r"); //파일 열기

    if (file)
    {
        // 첫 줄 읽기.
        if (!fgets(string, 256, file))
        {
            fclose(file);
            return false;
        }

        sscanf_s(string, "size %d", &mapSize);

        // 줄 데이터 저장을 위한 임시 배열 선언.
        std::vector<char> line;
        line.reserve(mapSize);

        // 맵 데이터 해석을 위한 루프.
        while (!feof(file))
        {
            fgets(string, 256, file);

            token = strtok_s(string, seps, &nextToken);
            while (token)
            {
                line.emplace_back(token[0]);
                token = strtok_s(nullptr, seps, &nextToken);
            }
            map.emplace_back(line);
            line.clear();
        }
        fclose(file); //파일 닫기
        return true;
    }
    return false;
}

// 이동 가능 여부 판단 함수.
bool IsValidLocation(int row, int col)
{
    if (row < 0 || row >= mapSize || col < 0 || col >= mapSize)
    {
        return false;
    }
    return map[row][col] == '0' || map[row][col] == 'x';
}

// 시작 지점 검색 함수.
void FindStartLocation(int& row, int& col)
{
    for (int i = 0; i < mapSize; ++i)
    {
        for (int j = 0; j < mapSize; ++j)
        {
            // 맵 출력.
            std::cout << map[i][j] << " ";
            if (map[i][j] == 'e')
            {
                row = i;
                col = j;
            }
        }
        std::cout << "\n";
    }
}


// 미로 탈출 함수.
void EscapeMaze()
{
    // 맵 크기 확인.
    //mapSize = (int)map.size();

    // 위치 저장을 위한 변수 선언.
    int row = 0;
    int col = 0;

    // 탐색 시작을 위해 시작 위치 찾기.
    FindStartLocation(row, col);

    // 스택 선언.
    std::stack<Location2D> stack;

    // 탐색 시작을 위해 시작 위치 스택에 삽입.
    stack.push(Location2D(row, col));

    // 미로 탐색.
    while (!stack.empty())
    {
        // 현재 위치 반환.
        Location2D current = stack.top();
        stack.pop();

        // 탐색 위치 출력.
        std::cout << "(" << current.row << "," << current.col << ") ";

        // 값 저장.
        row = current.row;
        col = current.col;

        // 탈출 조건 확인.
        if (map[row][col] == 'x')
        {
            std::cout << " \n미로 탐색 성공\n";
            return;
        }

        // 탐색 진행.
        // 방문한 현재 위치는 재방문 방지를 위해 표시.
        map[row][col] = '.';

        // 상,하,좌,우 위치 중 이동 가능한 위치를 스택에 삽입.
        if (IsValidLocation(current.row - 1, current.col))
        {
            stack.push(Location2D(current.row - 1, current.col));
        }
        if (IsValidLocation(current.row + 1, current.col))
        {
            stack.push(Location2D(current.row + 1, current.col));
        }
        if (IsValidLocation(current.row, current.col - 1))
        {
            stack.push(Location2D(current.row, current.col - 1));
        }
        if (IsValidLocation(current.row, current.col + 1))
        {
            stack.push(Location2D(current.row, current.col + 1));
        }
    }

}


int main()
{
    if (parseMap("../Assets/Map.txt"))
    {
        EscapeMaze();
    }


    std::cin.get();
}