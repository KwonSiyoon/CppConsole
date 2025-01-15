#include "GameLevel.h"
#include "Engine/Engine.h"
#include "Actor/Wall.h"
#include "Actor/Ground.h"
#include "Actor/Box.h"
#include "Actor/Target.h"
#include "Actor/Player.h"

GameLevel::GameLevel()
{
    // 커서 감추기.
    Engine::Get().SetCursorType(CursorType::NoCursor);

    // 맵 파일 불러와 레벨 로드.
    // 파일 읽기.
    FILE* file = nullptr;
    fopen_s(&file, "../Assets/Maps/Stage1.txt", "rb");

    // 파일 처리.
    if (file == nullptr)
    {
        std::cout << "맵 파일 열기 실패.\n";
        __debugbreak();
        return;
    }

    // 파일 읽기.
    // 끝 위치로 이동.
    fseek(file, 0, SEEK_END);

    // 이동한 위치의 FP 가져오기.(File Pointer/Position)
    size_t readSize = ftell(file);

    // FP 원위치.
    //fseek(file, 0, SEEK_SET); // rewind(file)과 동일.
    rewind(file);

    // 파일 읽어서 버퍼에 담기.
    char* buffer = new char[readSize + 1];
    size_t bytesRead = fread(buffer, 1, readSize, file);

    if (readSize != bytesRead)
    {
        std::cout << "읽어온 크기가 다름\n";
        __debugbreak();
        return;
    }

    buffer[readSize] = '\0';

    // 테스트 출력.
    //std::cout << buffer << "\n";

    // 파일 읽을 때 사용할 인덱스.
    int index = 0;

    // 좌표 계산을 위한 변수 선언.
    int xPosition = 0;
    int yPosition = 0;

    // 테스트 출력.
    // 해석 (파싱-Parcing).
    while (index < (int)bytesRead)
    {
        // 한 문자씩 읽기.
        char mapChar = buffer[index++];

        // 개행 문자인 경우 처리.
        if (mapChar == '\n')
        {
            ++yPosition;
            xPosition = 0;
            continue;
        }

        // 맵 문자가 1이면 Wall 액터 생성.
        if (mapChar == '1')
        {
            //std::cout << 'W';
            //AddActor(wall);
            //map.PushBack(wall);
            //AddActor(new Wall(Vector2(xPosition, yPosition)));
            Wall* wall = new Wall(Vector2(xPosition, yPosition));
            actors.PushBack(wall);
            map.PushBack(wall);
        }
        // 맵 문자가 .이면 그라운드 액터 생성.
        else if (mapChar == '.')
        {
            Ground* ground = new Ground(Vector2(xPosition, yPosition));
			actors.PushBack(ground);
            map.PushBack(ground);
        }
        // 맵 문자가 b 이면 박스 액터 생성.
        else if (mapChar == 'b')
        {
            Ground* ground = new Ground(Vector2(xPosition, yPosition));
            actors.PushBack(ground);
            map.PushBack(ground);
            
            Box* box = new Box(Vector2(xPosition, yPosition));
            actors.PushBack(box);
            boxes.PushBack(box);
        }
        // 맵 문자가 t 이면 타겟 액터 생성.
        else if (mapChar == 't')
        {
            Target* target = new Target(Vector2(xPosition, yPosition));
            actors.PushBack(target);
            targets.PushBack(target);
            map.PushBack(target);
        }
        // 맵 문자가 p 이면 플레이어 액터 생성.
        else if (mapChar == 'p')
        {
            Ground* ground = new Ground(Vector2(xPosition, yPosition));
            actors.PushBack(ground);
            map.PushBack(ground);

            player = new Player(Vector2(xPosition, yPosition), this);
            actors.PushBack(player);
        }
        ++xPosition;
        //std::cout << mapChar;
    }

    delete[] buffer;

    // 파일 닫기.
    fclose(file);
}

void GameLevel::Draw()
{
    // 맵 그리기.
    for (auto* actor : map)
    {
        if (actor->Position() == player->Position())
        {
            continue;
        }
        // 박스 위치 확인.
        bool shouldDraw = true;
        for (auto* box : boxes)
        {
            if (actor->Position() == box->Position())
            {
                shouldDraw = false;
                break;
            }
        }
        if (shouldDraw)
        {
            actor->Draw();
        }
    }
    // 타겟 그리기
    //for (auto* actor : targets)
    //{
    //    if (actor->Position() == player->Position())
    //    {
    //        continue;
    //    }
    //    // 박스 위치 확인.
    //    bool shouldDraw = true;
    //    for (auto* box : boxes)
    //    {
    //        if (actor->Position() == box->Position())
    //        {
    //            shouldDraw = false;
    //            break;
    //        }
    //    }
    //    if (shouldDraw)
    //    {
    //        actor->Draw();
    //    }
    //}
    // 박스 그리기.
    for (auto* actor : boxes)
    {
        actor->Draw();
    }
    // 플레이어 그리기.
    player->Draw();
}

void GameLevel::Update(float deltaTime)
{
    Super::Update(deltaTime);
}

bool GameLevel::CanPlayerMove(const Vector2& position)
{
    // 이동하려는 위치에 벽이 있는지 확인.
    DrawableActor* searchedActor = nullptr;
    // 먼저 이동하려는 위치의 액터 찾기.
    for (auto* actor : map)
    {
        if (actor->Position() == position)
        {
            searchedActor = actor;
            break;
        }
    }
    /*for (auto* actor : targets)
    {
        if (actor->Position() == position)
        {
            searchedActor = actor;
            break;
        }
    }*/
    // 검색한 액터가 이동 가능한 액터(땅/타겟)인지 확인.
    if (searchedActor->As<Ground>() || searchedActor->As<Target>())
    {
        return true;
    }
    
    //// 검색한 액터가 벽인지 확인.
    //if (searchedActor->As<Wall>())
    //{
    //    return false;
    //}

    return false;
}
