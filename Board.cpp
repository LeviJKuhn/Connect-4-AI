//
// Created by Levi Kuhn on 7/2/2026.
//

#include "Board.h"

// Public
Board::Board()
{
    Reset();
}

Board::Board(const Board &rhs)
{
    copyBoard(rhs);
}

Board& Board::operator=(const Board &rhs)
{
    if (this != &rhs) return *this;
    copyBoard(rhs);
    return *this;
}

Board::~Board() = default;



// PRE-CONDITION: Col selected must not be full
bool Board::Move(int col)
{
    if (col < 1 || col > 7) throw invalid_argument("Coloumn does not exist.");
    if (!IsLegalMove(col)) throw invalid_argument("Coloumn is full.");

    col--;
    for (int i = 5; i >= 0 ; i--)
    {
        if (board[i][col] == 0)
        {
            board[i][col] = turn;
            if (turn == playerOne)
                turn = playerTwo;
            else if (turn == playerTwo)
                turn = playerOne;
            return CheckWin(i, col);
        }
    }
    throw out_of_range("The coloumn is full");
}

bool Board::IsLegalMove(int col) const
{
    if (col < 1 || col > 7) throw invalid_argument("Coloumn does not exist");
    col--;
    if (board[0][col] == 0)
        return true;
    return false;
}


bool Board::IsBoardFull() const
{
    for (int i = 0; i < 6; i++)
    {
        if (IsLegalMove(i))
            return false;
    }
    return true;
}

bool Board::CheckWin(int row, int col) const
{
    if (CheckWinHorizontal(row, col) || CheckWinVertical(row, col) || CheckWinDiags(row, col))
        return true;
    return false;
}

void Board::Reset()
{
    turn = playerOne;
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 7; j++)
            board[i][j] = 0;
}

void Board::PrintBoard() const
{
    for (int i = 0; i < 6; i++)
    {
        cout << "|";
        for (int j = 0; j < 7; j++)
        {
            cout << board[i][j] << "|";
        }
        cout << endl;
    }
}


// Private
void Board::copyBoard(const Board &rhs)
{
    turn = rhs.turn;
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 7; j++)
            board[i][j] = rhs.board[i][j];
}

bool Board::CheckWinHorizontal(int row, int col) const
{
    int player = board[row][col];
    int count = 1;
    int index = 1;
    while ((col-index > 0) && (board[row][col-index] == player))
    {
        count++;
        index++;
    }
    index = 1;
    while ((col+index <= 6) && board[row][col+index] == player)
    {
        count++;
        index++;
    }
    if (count >= 4)
        return true;
    return false;
}

bool Board::CheckWinVertical(int row, int col) const
{
    int player = board[row][col];
    int count = 1;
    int index = 1;
    while ((row-index > 0) && board[row-index][col] == player)
    {
        count++;
        index++;
    }
    index = 1;
    while ((row+index <= 6) && board[row+index][col] == player)
    {
        count++;
        index++;
    }
    if (count >= 4)
        return true;
    return false;
}

bool Board::CheckWinDiags(int row, int col) const
{
    int player = board[row][col];
    int count = 1;
    int index = 1;
    while ((col-index > 0) && (row-index > 0) && board[row-index][col-index] == player)
    {
        count++;
        index++;
    }
    index = 1;
    while ((col+index <= 6) && (row+index <= 6) && board[row+index][col+index] == player)
    {
        count++;
        index++;
    }
    if (count >= 4)
        return true;
    return false;
}