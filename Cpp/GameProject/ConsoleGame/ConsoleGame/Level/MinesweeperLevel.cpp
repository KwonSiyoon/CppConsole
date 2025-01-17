#include "MinesweeperLevel.h"
#include "Engine/Timer.h"
#include "Game/Game.h"
#include "Actor/Mine.h"
#include "Actor/MineIndicator.h"
#include "Actor/Wall.h"
#include <Windows.h>
#include <iostream>
#include <queue>

MinesweeperLevel::MinesweeperLevel(int xSize, int ySize)
{
    // 커서 감추기.
    Engine::Get().SetCursorType(CursorType::NoCursor);
    Vector2 startPos = Vector2(2, 2);
    
    
    if (xSize != 0 && ySize != 0)
    {
        gameSize = Vector2(xSize, ySize);
    }
    
    int totalSizeX = gameSize.x + 2; // 벽 2칸.
    int totalSizeY = gameSize.y + 2; // 벽 2칸.

    mapArray = new int* [gameSize.y] {};
    for (int y = 0; y < gameSize.y; ++y)
    {
        mapArray[y] = new int[gameSize.x] {};
    }

    // 벽 만들기. Actor 인스턴스 생성.
    for (int y = 0; y < totalSizeY; ++y)
    {
        for (int x = 0; x < totalSizeX; ++x)
        {
            if (y == 0 || y == totalSizeY-1 || x == 0 || x== totalSizeX-1)
            {
                Wall* wall = new Wall(Vector2(startPos.x + x, startPos.y + y));
                actors.PushBack(wall);
            }
            
        }
    }

    // 지뢰 배열 저장.
    for (int y = 0; y < gameSize.y; ++y)
    {
        for (int x = 0; x < gameSize.x; ++x)
        {
            if (Random(1, 10) <= 2)
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
                Mine* mine = new Mine(Vector2(startPos.x + x + 1, startPos.y + y + 1));
                mines.push_back(mine);
                actors.PushBack(mine);
            }
            else
            {
                MineIndicator* indicator = new MineIndicator(
                    Vector2(startPos.x + x + 1, startPos.y + y + 1),
                    mapArray[y][x]
                );
                indicators.push_back(indicator);
                actors.PushBack(indicator);
            }
        }
    }
}

MinesweeperLevel::~MinesweeperLevel()
{
    for (int y = 0; y < gameSize.y; y++)
    {
        delete[] mapArray[y];
    }
    delete[] mapArray;
}

void MinesweeperLevel::MouseEvent()
{
    static INPUT_RECORD rec;
    static DWORD dwRead;
    static HANDLE hCin = GetStdHandle(STD_INPUT_HANDLE);
    static HANDLE hCout = GetStdHandle(STD_OUTPUT_HANDLE);
    // 현재 콘솔 정보 가져오기
    static CONSOLE_SCREEN_BUFFER_INFO csbi;

    SetConsoleMode(hCin, ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);

    if (ReadConsoleInput(hCin, &rec, 1, &dwRead))
    {
        if (rec.EventType == MOUSE_EVENT)
        {
            GetConsoleScreenBufferInfo(hCout, &csbi);

            int x = rec.Event.MouseEvent.dwMousePosition.X;
            // Y좌표를 윈도우의 시작점을 기준으로 계산
            int y = rec.Event.MouseEvent.dwMousePosition.Y - csbi.srWindow.Top;
            //std::cout << "마우스 클릭 좌표: X=" << x << ", Y=" << y << std::endl;

            if (rec.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
            {
                for (auto* actor : mines)
                {
                    if (actor->Position() == Vector2(x, y))
                    {
                        actor->Open();
                        return;
                    }
                }
                for (auto* actor : indicators)
                {
                    if (actor->Position() == Vector2(x, y))
                    {
                        //actor->IsOpened();
                        // 클릭한 위치를 게임 좌표로 변환 (startPos 고려)
                        int gameX = x - 3;  // startPos.x(2) + 1
                        int gameY = y - 3;  // startPos.y(2) + 1
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
                        return;
                    }
                }
                for (auto* actor : indicators)
                {
                    if (actor->Position() == Vector2(x, y))
                    {
                        actor->OnFlag();
                        return;
                    }
                }
            }
        }
    }
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
        MineIndicator* indicator = GetIndicatorAt(x + 3, y + 3);

        // indicator가 없거나(지뢰 위치) 이미 열려있으면 스킵
        if (!indicator || indicator->GetOpened())
            continue;

        // indicator 열기
        indicator->Open();

        // 현재 위치가 0일 때만 주변 탐색
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
    MouseEvent();
}

void MinesweeperLevel::Draw()
{
    Super::Draw();
}
