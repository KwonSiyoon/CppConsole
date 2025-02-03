#include "GameRoomUser.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define DBG_NEW new
#endif


ostream& operator<<(ostream& os, UserInfo& userInfo)
{
    return os << "UserName: " << userInfo.userName
        << ", Level: " << userInfo.level << ", Exp: " << userInfo.exp << endl;
}

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    // 방 생성.
    GameRoomUser gameRoom;

    // 유저 추가.
    UserInfo user1("RonnieJ", 1, 30);
    gameRoom.AddUser(user1);

    UserInfo user2("Hamtol2", 10, 670);
    gameRoom.AddUser(user2);

    UserInfo user3("TaeJun", 5, 250);
    gameRoom.AddUser(user3);

    UserInfo user4("Oops", 32, 1250);
    gameRoom.AddUser(user4);

    UserInfo user5("Gamer", 40, 250);
    gameRoom.AddUser(user5);

    UserInfo user6("GameDev", 80, 3425);
    gameRoom.AddUser(user6);

    UserInfo user7("STL", 23, 890);
    gameRoom.AddUser(user7);

    // 방장 확인.
    UserInfo roomMaster = gameRoom.GetMasterUser();
    if (roomMaster.userName != "")
    {
        cout << "방장은 " << roomMaster.userName << " 입니다.\n";
    }

    // 방장 밴.
    gameRoom.BanUser(1);

    // 3번 밴.
    gameRoom.BanUser(3);

    // GameDev의 레벨 확인.
    UserInfo* userInfo = new UserInfo();
    if (gameRoom.GetUserOfName("TaeJun", *userInfo))
    {
        cout << "[TaeJun의 정보] " << *userInfo;
    }
    else
    {
        cout << "TaeJun의 정보를 찾지 못했습니다\n";
    }

    // 마지막에 방에 들어온 유저 정보.
    cout << "[가장 마지막에 들어온 유저 정보] " << gameRoom.GetUserOfLastOrder();

    // 모든 유저 삭제.
    gameRoom.Clear();

    // 모든 유저 삭제 후 비었는지 확인.
    cout << (gameRoom.IsEmpty() == true ? "방이 비었습니다.\n" : "방이 비어있지 않습니다\n");

    cin.get();
    delete userInfo;
}