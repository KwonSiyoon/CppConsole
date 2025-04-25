#include "GreedyTest.h"

int GreedyTest::JoystickSolution(std::string name)
{
    // abcdefg
    // hijklmn
    // opqrstu
    // vwxyz  26개.
    //                     1                           2
    // A B C D E F G H I J K   L   M   N   O P Q R S T U V W X Y Z
    // 0 1 2 3 4 5 6 7 8 9 0   1   2   3   4 5 6 7 8 9 0 1 2 3 4 5
    // 0 1 2 3 4 5 6 7 8 9 10  11  12  11 10 9 8 7 6 5 4 3 2 1
    // 아스키 65~90
    int length = name.length();
    int answer = 0;

    for (int i = 0; i < length; ++i)
    {
        answer += std::min(name[i] - 'A', 'Z' - name[i] + 1);
    }

    int minMove = length - 1;

    for (int i = 0; i < length; ++i)
    {
        int next = i + 1;

        while (next < length && name[next] == 'A')
        {
            ++next;
        }

        int move = i * 2 + (length - next);
        int reverse = i + (length - next) * 2;

        minMove = std::min({ minMove, move, reverse });

    }

    answer += minMove;

    return answer;
}
