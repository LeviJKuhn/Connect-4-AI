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
    Board();
    Board(const Board &rhs);
    Board& operator=(const Board &rhs);
    ~Board();

    bool Move(int col);
    bool IsLegalMove(int col) const;

    bool IsBoardFull() const;
    bool CheckWin(int row, int col) const;

    void Reset();
    void PrintBoard() const;

private:
    int board[6][7];
    int turn;
    const int playerOne = 1;
    const int playerTwo = 2;

    void copyBoard(const Board &rhs);

    bool CheckWinHorizontal(int row, int col) const;
    bool CheckWinVertical(int row, int col) const;
    bool CheckWinDiags(int row, int col) const;
};



#endif //CONNECT_4_AI_BOARD_H
