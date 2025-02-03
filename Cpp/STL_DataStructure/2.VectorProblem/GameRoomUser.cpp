#include "GameRoomUser.h"



GameRoomUser::GameRoomUser()
{
}

GameRoomUser::~GameRoomUser()
{
}

bool GameRoomUser::AddUser(UserInfo& userInfo)
{
    if (IsFull())
    {
        cout << "방이 가득차서 입장하지 못했습니다.\n";
        return false;
    }
    if (IsEmpty())
    {
        masterUserName = userInfo.userName;
    }
    users.emplace_back(userInfo);

    return true;
}

bool GameRoomUser::DeleteUser(string userName)
{
    if (IsEmpty())
    {
        cout << "Error: 방이 비었습니다.\n";
        return false;
    }
    for (auto iter = users.begin(); iter != users.end(); ++iter)
    {
        if (iter->userName == userName)
        {
            users.erase(iter);
            return true;
        }
    }
    cout << "Error: 삭제하려는 유저를 찾지 못했습니다.\n";
    return false;
}

bool GameRoomUser::IsEmpty()
{
    return users.empty();
    /*if (users.empty())
    {
        return true;
    }
    return false;*/
}

bool GameRoomUser::IsFull()
{
    return users.size() >= maxUserCount;
    /*if (users.size() == maxUserCount)
    {
        return true;
    }
    return false;*/
}

bool GameRoomUser::GetUserOfName(string userName, UserInfo& userInfo)
{
    /*for (auto iter = users.begin(); iter != users.end(); ++iter)
    {
        if (iter->userName == userName)
        {
            userInfo = *iter;
            return true;
        }
    }*/
    for (auto& iter : users)
    {
        if (iter.userName == userName)
        {
            userInfo = iter;
            return true;
        }
    }
    cout << "Error: 유저를 찾지 못했습니다.\n";
    return false;
    // 밑의 경우 값복사만 일어나기 때문에 원본에 대해 접근 불가.
    /*for (auto iter : users)
    {
        if (iter.userName == userName)
        {
            return iter;
        }
    }*/
    
}

UserInfo& GameRoomUser::GetMasterUser()
{
    if (IsEmpty())
    {
        cout << "방이 비어있습니다.\n";
    }
    return users[0];
}

UserInfo& GameRoomUser::GetUserOfLastOrder()
{
    return users[users.size() - 1];
}

bool GameRoomUser::BanUser(int orderNum)
{
    if (IsEmpty())
    {
        cout << "방이 비어있습니다.\n";
        return false;
    }
    if (orderNum <= 0 || orderNum > users.size())
    {
        cout << "인덱스 계산이 잘못되었습니다.\n";
        return false;
    }
    users.erase(users.begin() + orderNum-1);
    if (orderNum == 1 && users.size() > 0)
    {
        masterUserName = users[0].userName;
        cout << "새로운 방장의 이름은 " << masterUserName << " 입니다.\n";
    }
    return true;
}

void GameRoomUser::Clear()
{
    /*for (auto iter = users.begin(); iter != users.end();)
    {
        iter = users.erase(iter);
    }*/
    users.clear();
    masterUserName = "";
}
