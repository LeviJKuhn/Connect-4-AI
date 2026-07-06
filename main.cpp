//
// Created by Levi Kuhn on 7/2/2026.
//


#include "Board.h"

#include <string>
#include <algorithm>
#include <cctype>

void TestCreation();
void LocalGame();
void PlayAgainstAI();

int main()
{
    // TestCreation();

    LocalGame();

    // PlayAgainstAI();

    return 0;
}


void TestCreation()
{
    Board board;
    for (int i = 1; i <= 7; i++)
        board.Move(i);
    board.PrintBoard();
}

void LocalGame()
{
    Board board;
    bool Playing = true;
    bool GameOver = false;
    bool PlayerOnesTurn = true;
    int PlacedPiece;
    string Response;

    while (Playing)
    {
        if (PlayerOnesTurn)
            cout << "Select a coloumn Player One: ";
        else
            cout << "Select a coloumn Player Two: ";
        cin >> PlacedPiece;
        GameOver = board.Move(PlacedPiece);
        board.PrintBoard();

        if (GameOver)
        {
            cout << "Game Over!" << endl;
            while (Response != "Y" && Response != "YES" && Response != "N" && Response != "NO"){
                cout << "Would you like to play again? (Y/N): ";
                cin >> Response;
                transform(Response.begin(), Response.end(), Response.begin(), ::toupper);
            }
            if (Response == "N" || Response == "NO")
                Playing = false;
            Response = "";
        }

        PlayerOnesTurn = !PlayerOnesTurn;
    }
}

void PlayAgainstAI()
{
    return;
}