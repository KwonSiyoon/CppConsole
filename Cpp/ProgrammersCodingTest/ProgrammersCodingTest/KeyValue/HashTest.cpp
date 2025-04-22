#include "HashTest.h"

std::string HashTest::UncompletedPlayerSolution(std::vector<std::string> participant, std::vector<std::string> completion)
{
    std::unordered_map<std::string, int> playerList{};
    for (auto& player : participant)
    {
        if (playerList.find(player) == playerList.end())
        {
            playerList.insert(std::pair<std::string, int>(player, 1));
        }
        else
        {
            ++playerList[player];
        }
    }
    for (auto& player : completion)
    {
        if (playerList.find(player) == playerList.end())
        {
            playerList.insert(std::pair<std::string, int>(player, 1));
        }
        else
        {
            --playerList[player];
        }
    }
    for (auto& player : playerList)
    {
        if (player.second == 1)
        {
            return player.first;
        }
    }

    return "";
}
