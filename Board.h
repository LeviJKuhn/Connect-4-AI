//
// Created by Levi Kuhn on 7/2/2026.
//

#ifndef CONNECT_4_AI_BOARD_H
#define CONNECT_4_AI_BOARD_H



class Board {
public:
    int** board;
    int turn;

    const int playerOne = 1;
    const int playerTwo = 2;

    Board();
    Board(const Board &rhs);
    Board &operator=(const Board &rhs);
    ~Board();

    void Move(int row);
    bool CheckWin();
    void Reset();

private:
    bool CheckWinHorizontal();
    bool CheckWinVertical();
    bool CheckWinDiags();

};



#endif //CONNECT_4_AI_BOARD_H
