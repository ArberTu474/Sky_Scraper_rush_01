#include "rush01.h"

/* 
We iterate from the top to the bottom and left to right.

In the currect well we try to pace a number from 1 to 4.
When we try to place the number we validate if it is 
unique in that row and col.

When a row or a col is filled we validate it by checking 
the side views. if the side views don't match with the clues 
we try to place another number in that grid cell.

We check for the next cell
*/
int solve(int grid[4][4], int *clues, int row, int col)
{
  int next_row;
  int next_col;
  int height;

  if (row == 4)
    return (1);
  next_row = row;
  next_col = col + 1;
  if (next_col == 4)
  {
    next_col = 0;
    next_row = row + 1;
  }
  height = 1;
  while (height <= 4)
  {
    if (is_valid_placement(grid, row, col, height))
    {
      grid[row][col] = height;
      if ((col == 3 || row == 3))
      {
        if (!validate_constraints(grid, clues, row, col))
        {
          grid[row][col] = 0;
          height++;
          continue;
        }
      }
      if (solve(grid, clues, next_row, next_col))
        return (1);
      grid[row][col] = 0;
    }
    height++;
  }
  return (0);
}
