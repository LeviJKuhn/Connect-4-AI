//
// Created by Levi Kuhn on 7/2/2026.
//

#ifndef CONNECT_4_AI_MACHINE_H
#define CONNECT_4_AI_MACHINE_H
#include "Board.h"


class Machine {
public:
    Machine(Board &board);
    ~Machine();

    void Move(int row);
private:
    void MiniMax();
};



#endif //CONNECT_4_AI_MACHINE_H
