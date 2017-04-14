#include <iostream>
#include "SudokuSolver.h"

using namespace std;

int main()
{
    int Grid[9][9] =
    {
        { 7, 0, 6, 0, 3, 0, 0, 9, 0 },
        { 4, 2, 0, 0, 7, 0, 0, 3, 0 },
        { 0, 0, 3, 0, 0, 0, 0, 4, 8 },
        { 0, 5, 0, 0, 4, 9, 0, 2, 7 },
        { 0, 9, 0, 2, 0, 6, 0, 5, 0 },
        { 1, 4, 0, 3, 5, 0, 0, 8, 0 },
        { 5, 3, 0, 0, 0, 0, 8, 0, 0 },
        { 0, 6, 0, 0, 9, 0, 0, 7, 3 },
        { 0, 7, 0, 0, 1, 0, 9, 0, 2 }
    };

    SudokuSolver *sudoku = new SudokuSolver(Grid);
    //SudokuSolver *sudoku = new SudokuSolver("Example1.txt"); // Or load from file

    if (sudoku->Solve())
    {
        sudoku->WriteToScreen();
        sudoku->WriteToFile("Example1_Solution.txt");
    }
    else {
        cout << "Unable to solve this sudoku puzzle!" << endl;
    }

    delete sudoku;

    return 0;
}