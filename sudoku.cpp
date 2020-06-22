#include <iostream>
#include <algorithm>
#include <vector>

bool boxCheck(int board[][9], int startRow, int startCol)
{
    std::vector<int> box;

    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            int pointer = board[row + startRow][col + startCol];
            box.push_back(pointer);
        }
    }
    std::unique(box.begin(), box.end());
    if (box.size() < 9)
    {
        return false;
    }
    else
        return true;
}

bool validSolution(int board[][9], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // checking if there are zeroes
            if (board[i][j] == 0)
            {
                return false;
            }
            for (int z = 0; z < n; z++)
            {
                int countrow = 0;
                if (board[i][j] == board[i][z])
                {
                    countrow++;
                    if (countrow > 1)
                        return false;
                }
                int countcolumn = 0;
                if (board[j][i] == board[z][i])
                {
                    countcolumn++;
                    if (countcolumn > 1)
                        return false;
                }
            }
            //checking if there are duplicates in box
            if (boxCheck(board, i - i % 3, j - j % 3) == false)
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    //returns valid
    int trueboard[9][9] = {
        {5, 3, 4, 6, 7, 8, 9, 1, 2},
        {6, 7, 2, 1, 9, 5, 3, 4, 8},
        {1, 9, 8, 3, 4, 2, 5, 6, 7},
        {8, 5, 9, 7, 6, 1, 4, 2, 3},
        {4, 2, 6, 8, 5, 3, 7, 9, 1},
        {7, 1, 3, 9, 2, 4, 8, 5, 6},
        {9, 6, 1, 5, 3, 7, 2, 8, 4},
        {2, 8, 7, 4, 1, 9, 6, 3, 5},
        {3, 4, 5, 2, 8, 6, 1, 7, 9}};
    //returns not valid
    int falseboard[9][9] = {
        {5, 3, 4, 6, 7, 8, 9, 1, 2},
        {6, 7, 2, 1, 9, 0, 3, 4, 8},
        {1, 0, 0, 3, 4, 2, 5, 6, 0},
        {8, 5, 9, 7, 6, 1, 0, 2, 0},
        {4, 2, 6, 8, 5, 3, 7, 9, 1},
        {7, 1, 3, 9, 2, 4, 8, 5, 6},
        {9, 0, 1, 5, 3, 7, 2, 1, 4},
        {2, 8, 7, 4, 1, 9, 6, 3, 5},
        {3, 0, 0, 4, 8, 1, 1, 7, 9}};

    std::cout << (validSolution(falseboard, 9) ? "valid" : "not valid");
    return 0;
}