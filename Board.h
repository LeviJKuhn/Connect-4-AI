//
// Created by Levi Kuhn on 7/2/2026.
//

#ifndef CONNECT_4_AI_BOARD_H
#define CONNECT_4_AI_BOARD_H

#include <stdexcept>
#include <iostream>

using namespace std;

class Board {
public:
    int board[6][7];
    int turn;
    const int playerOne = 1;
    const int playerTwo = 2;

    Board();
    Board(const Board &rhs);
    Board& operator=(const Board &rhs);
    ~Board();
    void copyBoard(const Board &rhs);

    bool Move(int col);
    bool CheckWin(int row, int col);
    void Reset();
    void PrintBoard();

private:
    bool CheckWinHorizontal(int row, int col);
    bool CheckWinVertical(int row, int col);
    bool CheckWinDiags(int row, int col);
};



#endif //CONNECT_4_AI_BOARD_H
