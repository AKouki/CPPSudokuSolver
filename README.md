# CPPSudokuSolver
A Sudoku Solver using [Backtracking Algorithm](https://en.wikipedia.org/wiki/Sudoku_solving_algorithms#Brute_Force_Algorithm_.28Backtracking.29)

## Usage

Example 1: Load sudoku puzzle from file and solve it
```c++
    SudokuSolver *sudoku = new SudokuSolver("Example1.txt");
    if (sudoku->Solve())
    {
        sudoku->WriteToScreen();
        sudoku->WriteToFile("Example1_Solution.txt");
    }
    else {
        cout << "Unable to solve this sudoku puzzle!" << endl;
    }
    delete sudoku;
```
Example 2: Solve sudoku puzzle from Array
```c++
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
    if (sudoku->Solve())
    {
        sudoku->WriteToScreen();
        sudoku->WriteToFile("Example1_Solution.txt");
    }
    else {
        cout << "Unable to solve this sudoku puzzle!" << endl;
    }
    delete sudoku;
```
