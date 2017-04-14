#include "SudokuSolver.h"

SudokuSolver::SudokuSolver(int _Grid[N][N])
{
    memcpy(Grid, _Grid, sizeof(Grid));
}

SudokuSolver::SudokuSolver(string fileName)
{
    // 1. Open puzzle file
    ifstream inputFile(fileName);

    if (!inputFile.is_open())
    {
		cerr << "Error: Unable to open file" << endl;
        exit(0);
    }

    // 2. Parse puzzle data
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            inputFile >> Grid[i][j];

            if (Grid[i][j] < 0 || Grid[i][j] > 9)
            {
                cerr << "This is not valid puzzle data!" << endl;
                exit(1);
            }
        }
    }

    // 3. Close file
    inputFile.close();
}

SudokuSolver::~SudokuSolver()
{

}

Cell* SudokuSolver::GetEmptyCell()
{
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            if (Grid[i][j] == 0)
                return new Cell{ i, j };
        }
    }

    return nullptr;
}

bool SudokuSolver::IsValid(int row, int col, int num)
{
    // Check Rows and Columns
    for (size_t i = 0; i < 9; i++)
    {
        if (Grid[row][i] == num)
            return false;

        if (Grid[i][col] == num)
            return false;
    }

    // Check within 3x3 Block
    int x1 = row - row % 3;
    int x2 = col - col % 3;
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            if (Grid[i + x1][j + x2] == num)
                return false;
        }
    }

    return true;
}

bool SudokuSolver::Solve()
{
    Cell *cell = GetEmptyCell();

    if (cell == nullptr)
        return true;

    for (size_t num = 1; num <= N; num++)
    {
        if (IsValid(cell->X, cell->Y, num))
        {
            Grid[cell->X][cell->Y] = num;

            if (Solve())
                return true;

            Grid[cell->X][cell->Y] = 0;
        }
    }

    return false;
}

void SudokuSolver::WriteToScreen()
{
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            cout << Grid[i][j] << " ";

            if (j % 3 == 2)
                cout << "| ";
        }
        if (i % 3 == 2)
            cout << "\n-----------------------";
        cout << endl;
    }
}

bool SudokuSolver::WriteToFile(string fileName)
{
    ofstream outputFile(fileName);

    if (!outputFile.is_open())
        return false;

    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            outputFile << Grid[i][j];

            if (j < N - 1)
                outputFile << " ";
        }

        if (i < (N - 1))
            outputFile << "\n";
    }

    outputFile.close();
    return true;
}