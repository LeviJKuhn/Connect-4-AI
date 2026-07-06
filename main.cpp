//
// Created by Levi Kuhn on 7/2/2026.
//


#include "Board.h"

int main()
{
    /* Instantiate Machine
     * Begin Playing
     *
     * Test Constructor Injection + Postponed Instantiation
     */

    Board board;
    for (int i = 1; i <= 7; i++)
        board.Move(i);
    board.PrintBoard();

    return 0;
}
