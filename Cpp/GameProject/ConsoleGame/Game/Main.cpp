#include <iostream>
#include <vector>
#include <windows.h>

class BoardGames
{
private:
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    void setColor(int color)
    {
        SetConsoleTextAttribute(hConsole, color);
    }

public:
    // 오목 보드 그리기 (15x15)
    void drawOmok()
    {
        std::cout << "\n   O M O K (15 x 15)\n\n";
        std::cout << "     0 1 2 3 4 5 6 7 8 9 a b c d e\n";

        for (int i = 0; i < 15; i++)
        {
            printf("  %2d ", i);  // 행 번호
            for (int j = 0; j < 15; j++)
            {
                if (i == 0)
                {
                    if (j == 0) std::cout << "┌";
                    else if (j == 14) std::cout << "┐";
                    else std::cout << "┬";
                }
                else if (i == 14)
                {
                    if (j == 0) std::cout << "└";
                    else if (j == 14) std::cout << "┘";
                    else std::cout << "┴";
                }
                else
                {
                    if (j == 0) std::cout << "├";
                    else if (j == 14) std::cout << "┤";
                    else std::cout << "┼";
                }
                if (j < 14) std::cout << "─";
            }
            std::cout << std::endl;
        }
    }

    // 오델로 보드 그리기 (8x8)
    void drawOthello()
    {
        std::cout << "\n   O T H E L L O (8 x 8)\n\n";
        std::cout << "     0 1 2 3 4 5 6 7\n";

        for (int i = 0; i < 8; i++)
        {
            printf("  %2d ", i);  // 행 번호
            for (int j = 0; j < 8; j++)
            {
                if (i == 0)
                {
                    if (j == 0) std::cout << "┌";
                    else if (j == 7) std::cout << "┐";
                    else std::cout << "┬";
                }
                else if (i == 7)
                {
                    if (j == 0) std::cout << "└";
                    else if (j == 7) std::cout << "┘";
                    else std::cout << "┴";
                }
                else
                {
                    if (j == 0) std::cout << "├";
                    else if (j == 7) std::cout << "┤";
                    else std::cout << "┼";
                }

                if (j < 7) std::cout << "─";
            }
            std::cout << std::endl;
        }

        // 초기 돌 배치
        std::cout << "\n  Initial stones:\n";
        std::cout << "  (3,3) and (4,4): White (○)\n";
        std::cout << "  (3,4) and (4,3): Black (●)\n";
    }

    // 바둑 보드 그리기 (19x19)
    void drawGo()
    {
        std::cout << "\n   G O (19 x 19)\n\n";
        std::cout << "     0 1 2 3 4 5 6 7 8 9 a b c d e f g h i\n";

        for (int i = 0; i < 19; i++)
        {
            printf("  %2d ", i);  // 행 번호
            for (int j = 0; j < 19; j++)
            {
                if (i == 0)
                {
                    if (j == 0) std::cout << "┌";
                    else if (j == 18) std::cout << "┐";
                    else std::cout << "┬";
                }
                else if (i == 18)
                {
                    if (j == 0) std::cout << "└";
                    else if (j == 18) std::cout << "┘";
                    else std::cout << "┴";
                }
                else
                {
                    if (j == 0) std::cout << "├";
                    else if (j == 18) std::cout << "┤";
                    else std::cout << "┼";
                }
                if (j < 18) std::cout << "─";
            }
            std::cout << std::endl;
        }

        // 화점(星) 표시
        std::cout << "\n  Star points (화점):\n";
        std::cout << "  (3,3), (3,9), (3,15)\n";
        std::cout << "  (9,3), (9,9), (9,15)\n";
        std::cout << "  (15,3), (15,9), (15,15)\n";
    }

    // 보드에 돌 놓기 (공통 함수)
    void placeStone(std::vector<std::vector<char>>& board, int row, int col, char stone)
    {
        if (row >= 0 && row < board.size() &&
            col >= 0 && col < board[0].size() &&
            board[row][col] == ' ')
        {
            board[row][col] = stone;
        }
    }

    // 현재 보드 상태 출력 (디버깅용)
    void printBoard(const std::vector<std::vector<char>>& board)
    {
        for (const auto& row : board)
        {
            for (char cell : row)
            {
                if (cell == ' ') std::cout << "·";
                else std::cout << cell;
                std::cout << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main()
{
    BoardGames games;

    // 오목 보드 출력
    games.drawOmok();
    std::cout << "\nPress Enter for Othello board...";
    std::cin.get();

    // 오델로 보드 출력
    system("cls");
    games.drawOthello();
    std::cout << "\nPress Enter for Go board...";
    std::cin.get();

    // 바둑 보드 출력
    system("cls");
    games.drawGo();

    return 0;
}