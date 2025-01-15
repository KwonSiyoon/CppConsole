#include "TestLevel.h"
#include "Engine/Engine.h"
#include "Actor/Player.h"
#include "Actor/PlayerBullet.h"
#include "Actor/Enemy.h"
#include "Actor/EnemyBullet.h"

#include <Windows.h>

struct EnemyType
{
    EnemyType(const char* image, const char* bulletImage, int score);

    char* image = nullptr;
    char* bulletImage = nullptr;
    int score = 0;
};


// 적 캐릭터 종류.
static const char* enemyType[]
{
    ";(^);",
    "zZTZz",
    "oO&Oo",
    "<=-=>",
    ")~O~(",
    "[[0]]"
};

TestLevel::TestLevel()
{
	AddActor(new Player("<A>"));
}

TestLevel::~TestLevel()
{
}

void TestLevel::Update(float deltaTime)
{
	Super::Update(deltaTime);			// 커스텀 RTTI 사용시 Level 대신 Super를 통해 호출 가능.

    // 예외 처리
    if (deltaTime > 1.0f)
    {
        return;
    }

	if (Engine::Get().GetKeyDown(VK_ESCAPE))
	{
		Engine::Get().QuitGame();
	}

    // 점수 출력.
    //SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
    //SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (int)Color::Purple);
    SetColor(Color::Purple);
    Engine::Get().SetCursorPosition(0, Engine::Get().ScreenSize().y + 1);
    Log("Score: %d", score);
    //SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    //SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (int)Color::White);
    SetColor(Color::White);

    // 적 생성.
    SpawnEnemy(deltaTime);

    // 플레이어 탄약과 적의 충돌 처리.
    ProcessCollisionPlayerBulletAndEnemy();
    // 플레이어와 적 탄약 충돌처리.
    ProcessCollisionPlayerAndEnemyBullet();
}



void TestLevel::SpawnEnemy(float deltaTime)
{
    // 적 생성.
    static float elapsedTime = 0.0f;
    static float spawnTime = RandomPercent(1.0f, 3.0f);

    // 타이머.
    elapsedTime += deltaTime;
    if (elapsedTime < spawnTime)
    {
        return;
    }

    // 타이머 리셋.
    elapsedTime = 0.0f;
    spawnTime = RandomPercent(1.0f, 3.0f);

    //static int length = sizeof(enemyType) / sizeof(enemyType[0]);
    static int length = _countof(enemyType);
    int index = Random(0, length - 1);
    AddActor(new Enemy(enemyType[index], Random(1, 10)));


    // 적생성.
    //AddActor(new Enemy("[[0]]", Random(1, 10)));
}

void TestLevel::ProcessCollisionPlayerBulletAndEnemy()
{
    // 탄약 및 적 캐릭터 배열 선언.
    List<PlayerBullet*> bullets;
    List<Enemy*> enemies;

    // 레벨에 배치된 액터를 순회하면서 리스트 채우기.
    for (Actor* actor : actors)
    {
        // 탄약으로 형변환 후 확인해서 리스트 채우기.
        PlayerBullet* bullet = actor->As<PlayerBullet>();
        if (bullet)
        {
            bullets.PushBack(bullet);
            continue;
        }
        // 적으로 형변환 후 확인해서 리스트 채우기.
        Enemy* enemy = actor->As<Enemy>();
        if (enemy)
        {
            enemies.PushBack(enemy);
        }
    }

    // 예외 처리.
    if (bullets.Size() == 0 || enemies.Size() == 0)
    {
        return;
    }

    // 두 배열을 순회하면서 충돌 처리.
    for (PlayerBullet* bullet : bullets)
    {
        for (Enemy* enemy : enemies)
        {
            // 적이 비활성화 상태라면 건너뛰기.
            if (!enemy->IsActive())
            {
                continue;
            }
            // 충돌 처리.
            if (enemy->Intersect(*bullet))
            {
                // 충돌했으면 적 제거.
                enemy->Destroy();

                // 탄약도 제거.
                bullet->Destroy();

                // 점수 추가.
                score += 10;
            }
        }
    }
}

void TestLevel::ProcessCollisionPlayerAndEnemyBullet()
{
    Player* player = nullptr;
    List<EnemyBullet*> bullets;

    //// 레벨에 배치된 액터를 순회하면서 리스트 채우기.
    //for (Actor* actor : actors)
    //{
    //    // 탄약으로 형변환 후 확인해서 리스트 채우기.
    //    EnemyBullet* bullet = actor->As<EnemyBullet>();
    //    if (bullet)
    //    {
    //        bullets.PushBack(bullet);
    //        continue;
    //    }
    //    // 적으로 형변환 후 확인해서 리스트 채우기.
    //    Player* playerTemp = actor->As<Player>();
    //    if (playerTemp)
    //    {
    //        player = playerTemp;
    //    }
    //}
    for (Actor* actor : actors)
    {
        if (!player)
        {
            player = actor->As<Player>();
            continue;
        }
        // 탄약으로 형변환 후 확인해서 리스트 채우기.
        EnemyBullet* bullet = actor->As<EnemyBullet>();
        if (bullet)
        {
            bullets.PushBack(bullet);
            continue;
        }
        
    }


    // 예외 처리.
    if (bullets.Size() == 0 || player == nullptr)
    {
        return;
    }

    // 두 배열을 순회하면서 충돌 처리.
    for (EnemyBullet* bullet : bullets)
    {
        // 플레이어가 비활성화 상태라면 건너뛰기.
        if (!player->IsActive())
        {
            continue;
        }
        // 충돌 처리.
        if (player->Intersect(*bullet))
        {
            // 충돌했으면 플레이어 제거.
            player->Destroy();

            int y = Engine::Get().ScreenSize().y;
            Engine::Get().SetCursorPosition(
                player->Position().x - player->Width() / 2, y - 1
            );
            Log("  .  ");
            Engine::Get().SetCursorPosition(
                player->Position().x - player->Width() / 2, y);
            Log(".:V:.");
            Engine::Get().SetCursorPosition(
                player->Position().x - player->Width() / 2, y + 1);
            Log("GameOver!\n");

            // 탄약도 제거.
            bullet->Destroy();

            // 약 2초간 정지.
            Sleep(2000);

            // 게임 종료.
            Engine::Get().QuitGame();
        }
    }

}
