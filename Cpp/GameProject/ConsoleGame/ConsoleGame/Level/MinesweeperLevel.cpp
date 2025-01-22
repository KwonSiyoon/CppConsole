#include "MinesweeperLevel.h"
#include "Engine/Timer.h"
#include "Game/Game.h"
#include "Actor/Mine.h"
#include "Actor/MineIndicator.h"
#include "Actor/Wall.h"
#include <Windows.h>
#include <iostream>
#include <queue>

MinesweeperLevel::MinesweeperLevel(int xSize, int ySize, const Vector2& startPos)
{
    // 커서 감추기.
    Engine::Get().SetCursorType(CursorType::NoCursor);
    //startPos = Vector2(2, 2);
    this->startPos = startPos;
    if (xSize != 0 && ySize != 0)
    {
        gameSize = Vector2(xSize, ySize);
    }

    Initialize(gameSize, this->startPos);
    
}

MinesweeperLevel::~MinesweeperLevel()
{
    for (int y = 0; y < gameSize.y; y++)
    {
        delete[] mapArray[y];
    }
    delete[] mapArray;
}

void MinesweeperLevel::Initialize(const Vector2& gameSize, const Vector2& startPos)
{
    int totalSizeX = gameSize.x + 2; // 벽 2칸.
    int totalSizeY = gameSize.y + 2; // 벽 2칸.

    mapArray = new int* [gameSize.y] {};
    for (int y = 0; y < gameSize.y; ++y)
    {
        mapArray[y] = new int[gameSize.x] {};
    }
    Wall* wall;
    // 벽 만들기. Actor 인스턴스 생성.
    for (int y = 0; y < totalSizeY; ++y)
    {
        for (int x = 0; x < totalSizeX; ++x)
        {
            if (y == 0)
            {
                if (x == 0)
                {
                    // 왼쪽 위
                    wall = new Wall(Vector2(startPos.x + x, startPos.y + y), "┌");
                }
                else if (x == totalSizeX - 1)
                {
                    wall = new Wall(Vector2(startPos.x + x, startPos.y + y), "┐");
                }
                else
                {
                    wall = new Wall(Vector2(startPos.x + x, startPos.y + y), "─");
                }
                actors.PushBack(wall);
            }
            else if (y == totalSizeY - 1)
            {
                if (x == 0)
                {
                    // 왼쪽 아래
                    wall = new Wall(Vector2(startPos.x + x, startPos.y + y), "└");
                }
                else if (x == totalSizeX - 1)
                {
                    wall = new Wall(Vector2(startPos.x + x, startPos.y + y), "┘");
                }
                else
                {
                    wall = new Wall(Vector2(startPos.x + x, startPos.y + y), "─");
                }
                actors.PushBack(wall);
            }
            else if (x == 0 || x == totalSizeX - 1)
            {
                wall = new Wall(Vector2(startPos.x + x, startPos.y + y), "│");
                actors.PushBack(wall);
            }
            
        }
    }

    // 지뢰 배열 저장.
    for (int y = 0; y < gameSize.y; ++y)
    {
        for (int x = 0; x < gameSize.x; ++x)
        {
            if (Random(1, 1000) <= 125)
            {
                mapArray[y][x] = -1;
            }
        }
    }
    // Indicator 저장.
    for (int y = 0; y < gameSize.y; ++y)
    {
        for (int x = 0; x < gameSize.x; ++x)
        {
            if (mapArray != nullptr && mapArray[y][x] != -1)
            {
                mapArray[y][x] = CheckSurroundMines(mapArray, x, y);
            }
        }
    }

    for (int y = 0; y < gameSize.y; ++y)
    {
        for (int x = 0; x < gameSize.x; ++x)
        {
            if (mapArray[y][x] == -1)
            {
                Mine* mine = new Mine(
                    Vector2(startPos.x + x + 1, startPos.y + y + 1), 
                    std::bind(&MinesweeperLevel::DecreaseMineCount, this)
                );
                mines.push_back(mine);
                actors.PushBack(mine);
            }
            else
            {
                MineIndicator* indicator = new MineIndicator(
                    Vector2(startPos.x + x + 1, startPos.y + y + 1),
                    mapArray[y][x], 
                    [this]() {--indicatorCounts; }
                );
                indicators.push_back(indicator);
                actors.PushBack(indicator);
            }
        }
    }

    indicatorCounts = (int)indicators.size();
    mineCounts = (int)mines.size();
}

// 발표. 마우스 이벤트 처리.
void MinesweeperLevel::MouseEvent()
{
    static INPUT_RECORD rec;
    static DWORD dwRead;
    static HANDLE hCin = GetStdHandle(STD_INPUT_HANDLE);
    static HANDLE hCout = GetStdHandle(STD_OUTPUT_HANDLE);
    // 현재 콘솔 정보 가져오기
    static CONSOLE_SCREEN_BUFFER_INFO csbi;

    FlushConsoleInputBuffer(hCin);
    SetConsoleMode(hCin, ENABLE_EXTENDED_FLAGS | ENABLE_MOUSE_INPUT);

    //ReadConsoleInput(
    //    HANDLE hConsoleInput,           // 콘솔 입력 핸들
    //    PINPUT_RECORD lpBuffer,         // 입력 이벤트를 저장할 버퍼
    //    DWORD nLength,                  // 읽을 이벤트의 수
    //    LPDWORD lpNumberOfEventsRead    // 실제로 읽은 이벤트의 수를 저장할 포인터
    //);
    if (ReadConsoleInput(hCin, &rec, 1, &dwRead))
    {
        if (rec.EventType == MOUSE_EVENT)
        {
            int x = rec.Event.MouseEvent.dwMousePosition.X;
            // Y좌표를 윈도우의 시작점을 기준으로 계산
            int y = rec.Event.MouseEvent.dwMousePosition.Y;
            //std::cout << "마우스 클릭 좌표: X=" << x << ", Y=" << y << std::endl;

            if (rec.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
            {
                for (auto* actor : mines)
                {
                    if (actor->Position() == Vector2(x, y))
                    {
                        actor->Open();
                        GameOver();
                        return;
                    }
                }
                for (auto* actor : indicators)
                {
                    if (actor->Position() == Vector2(x, y))
                    {
                        //actor->IsOpened();
                        // 클릭한 위치를 게임 좌표로 변환 (startPos 고려)
                        int gameX = x - (startPos.x + 1);  // startPos.x(2) + 1
                        int gameY = y - (startPos.y + 1);  // startPos.y(2) + 1
                        if (mapArray[gameY][gameX] == 0)
                        {
                            OpenSurroundingZeros(gameX, gameY);
                        }
                        else
                        {
                            actor->Open();
                        }
                        return;
                    }
                }
            }
            else if (rec.Event.MouseEvent.dwButtonState == RIGHTMOST_BUTTON_PRESSED)
            {
                for (auto* actor : mines)
                {
                    if (actor->Position() == Vector2(x, y))
                    {
                        actor->OnFlag();
                        if (actor->GetFlag())
                        {
                            --mineCounts;
                        }
                        else
                        {
                            ++mineCounts;
                        }
                        return;
                    }
                }
                for (auto* actor : indicators)
                {
                    if (actor->Position() == Vector2(x, y))
                    {
                        actor->OnFlag();
                        if (actor->GetFlag())
                        {
                            --mineCounts;
                        }
                        else
                        {
                            ++mineCounts;
                        }
                        return;
                    }
                }
            }
        }
    }
}

void MinesweeperLevel::GameOver()
{
    isGameOver = true;
}

int MinesweeperLevel::CheckSurroundMines(int**& array, int x, int y)
{
    int count = 0;
    for (int i = -1; i <= 1; ++i)
    {
        for (int j = -1; j <= 1; ++j)
        {
            if (i == 0 && j == 0) continue;
            // 새로운 좌표
            int newY = y + i;
            int newX = x + j;

            // 배열 범위 체크
            if (newY >= 0 && newY < gameSize.y &&
                newX >= 0 && newX < gameSize.x)
            {
                if (array[newY][newX] == -1)
                {
                    ++count;
                }
            }
        }
    }
    return count;
}

// queue를 이용한 재귀.
void MinesweeperLevel::OpenSurroundingZeros(int x, int y)
{
    std::queue<std::pair<int, int>> searchQueue;
    searchQueue.push({ x, y });

    while (!searchQueue.empty())
    {
        int x = searchQueue.front().first;
        int y = searchQueue.front().second;
        searchQueue.pop();

        // 범위 체크
        if (x < 0 || x >= gameSize.x || y < 0 || y >= gameSize.y)
            continue;

        // 해당 위치의 indicator 찾기
        MineIndicator* indicator = GetIndicatorAt(x + startPos.x+1, y + startPos.y +1);

        // indicator가 없거나(지뢰 위치) 이미 열려있으면 스킵
        if (!indicator || indicator->GetOpened())
            continue;

        // indicator 열기
        indicator->Open();

        // 현재 위치의 indicator의 값이 0일 때만 주변 탐색
        if (mapArray[y][x] == 0)
        {
            // 8방향 탐색
            for (int i = -1; i <= 1; ++i)
            {
                for (int j = -1; j <= 1; ++j)
                {
                    if (i == 0 && j == 0) continue;
                    searchQueue.push({ x + j, y + i });
                }
            }
        }
    }
}

// 재귀함수로 구현.
//void MinesweeperLevel::OpenSurroundingZeros(int x, int y)
//{
//    // 범위 체크
//    if (x < 0 || x >= gameSize.x || y < 0 || y >= gameSize.y)
//        return;
//
//    // 해당 위치의 indicator 찾기
//    MineIndicator* indicator = GetIndicatorAt(x + 3, y + 3);  // startPos(2,2) 고려
//
//    // indicator가 없거나(지뢰 위치) 이미 열려있으면 리턴
//    if (!indicator || indicator->GetOpened()) return;
//
//    // indicator 열기
//    indicator->IsOpened();
//
//    // 현재 위치가 0일 때만 주변 탐색
//    if (mapArray[y][x] == 0)
//    {
//        // 8방향 탐색
//        for (int i = -1; i <= 1; ++i)
//        {
//            for (int j = -1; j <= 1; ++j)
//            {
//                if (i == 0 && j == 0) continue;
//                OpenSurroundingZeros(x + j, y + i);
//            }
//        }
//    }
//}

MineIndicator* MinesweeperLevel::GetIndicatorAt(int x, int y)
{
    for (auto* indicator : indicators)
    {
        if (indicator->Position() == Vector2(x, y))
            return indicator;
    }
    return nullptr;
}


void MinesweeperLevel::Update(float deltaTime)
{
    Super::Update(deltaTime);
    if (Game::Get().GetKeyDown(VK_ESCAPE))
	{
		Game::Get().ToggleMenu();
	}
    
    if (isGameOver)
    {
        for (auto* actor : mines)
        {
            actor->Open();
        }
        Retry();
        return;
    }
    if (isGameClear || isGameOver)
    {
        return;
    }
    MouseEvent();
    if (indicatorCounts <= 0)
    {
        GameClear();
    }
    if (Game::Get().GetKeyDown(VK_RETURN))
    {
        GameClear();
    }
}

void MinesweeperLevel::Draw()
{
    Super::Draw();
    if (isGameClear)
    {
        SetColor(Color::Green);
        Engine::Get().SetCursorPosition(Vector2(startPos.x + 1, startPos.y + gameSize.y + 2));
        Log("게임 클리어!! ESC를 눌러 메뉴로 이동이 가능합니다.");
        SetColor(Color::White);
    }
    /*if (!isGameClear && !isGameOver) // 파괴로 최적화 하려 했으나 다시 돌아왔을 때 안보이는 현상 있음.
    {
        for (auto* actor : mines)
        {
            if (actor->GetOpen())
            {
                actor->Destroy();
                mines.erase(remove(mines.begin(), mines.end(), actor), mines.end());
            }
        }
        for (auto* actor : indicators)
        {
            if (actor->GetOpened())
            {
                actor->Destroy();
                indicators.erase(remove(indicators.begin(), indicators.end(), actor), indicators.end());
            }
        }
    }*/
    
    if (gameSize.x < 32)
    {
        Engine::Get().SetCursorPosition(Vector2(startPos.x - 1, startPos.y - 1));
    }
    else
    {
        Engine::Get().SetCursorPosition(Vector2(startPos.x-1 + gameSize.x - 32, startPos.y-1));
    }
    std::cout << "남은 지뢰: " << mineCounts << " | 남은 숫자칸: " << indicatorCounts;
}

void MinesweeperLevel::DecreaseMineCount()
{
    if (isGameOver) return;
    --mineCounts;
}

void MinesweeperLevel::DecreaseIndicatorCount()
{
    --indicatorCounts;
}

void MinesweeperLevel::GameClear()
{
    isGameClear = true;
    for (auto* actor : mines)
    {
        actor->Open();
    }
    SetColor(Color::Green);
    Engine::Get().SetCursorPosition(Vector2(startPos.x + 1, startPos.y + gameSize.y + 2));
    Log("게임 클리어!! ESC를 눌러 메뉴로 이동이 가능합니다.");
    SetColor(Color::White);
}

void MinesweeperLevel::Retry()
{
    Engine::Get().SetCursorPosition(Vector2(startPos.x+1, startPos.y+gameSize.y+2));
    SetColor(Color::Red);
    std::cout << "게임 오버!! Space Bar 를 눌러 재시작.";
    SetColor(Color::White);
    if (Game::Get().GetKeyDown(VK_SPACE))
    {
        system("cls");
        Game::Get().ClearAndLoadLevel(new MinesweeperLevel(gameSize.x, gameSize.y, startPos));
    }
}
