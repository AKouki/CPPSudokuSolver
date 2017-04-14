#ifndef SUDOKUSOLVER_H
#define SUDOKUSOLVER_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

typedef struct Cell{
	int X, Y;
}Cell;

class SudokuSolver
{
private:
	static const int N = 9;
	int Grid[N][N];
	Cell* GetEmptyCell();                     // Get next empty cell in Grid
	bool IsValid(int row, int col, int num);  // Check if it is valid to assign num to row,col
public:
	SudokuSolver();
	SudokuSolver(int Grid[N][N]);             // Initializes Grid with local data
	SudokuSolver(string fileName);            // Initializes Grid from file
	bool Solve();                             // Solves Sudoku
	bool WriteToFile(string fileName);        // Writes solution to file
	void WriteToScreen();                     // Writes solution to screen
	~SudokuSolver();
};

#endif