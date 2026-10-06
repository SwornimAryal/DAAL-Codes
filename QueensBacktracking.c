#include <stdio.h>
#include <stdlib.h>

// Check whether a queen can be placed at (row, col)
int is_safe(int row, int col, int queens[])
{
    int previous_row;

    for (previous_row = 0; previous_row < row; previous_row++)
    {
        int previous_col = queens[previous_row];

        // Same column
        if (previous_col == col)
            return 0;

        // Same diagonal
        if (abs(previous_row - row) == abs(previous_col - col))
            return 0;
    }

    return 1;
}

// Backtracking function
int solve_n_queens(int row, int n, int queens[])
{
    int col;

    // All queens have been placed
    if (row == n)
        return 1;

    // Try every column in the current row
    for (col = 0; col < n; col++)
    {
        if (is_safe(row, col, queens))
        {
            // Place queen
            queens[row] = col;

            // Move to next row
            if (solve_n_queens(row + 1, n, queens))
                return 1;

            // Backtrack
            queens[row] = -1;
        }
    }

    return 0;
}

// Print the chessboard
void print_board(int queens[], int n)
{
    int row, col;

    for (row = 0; row < n; row++)
    {
        for (col = 0; col < n; col++)
        {
            if (queens[row] == col)
                printf("Q ");
            else
                printf(". ");
        }

        printf("\n");
    }
}

int main()
{
    int n, i;

    printf("Enter number of queens: ");
    scanf("%d", &n);

    int queens[n];

    // Initialize all positions to -1
    for (i = 0; i < n; i++)
        queens[i] = -1;

    if (solve_n_queens(0, n, queens))
    {
        printf("\nSolution:\n");
        print_board(queens, n);
    }
    else
    {
        printf("\nNo solution exists.");
    }

    return 0;
}