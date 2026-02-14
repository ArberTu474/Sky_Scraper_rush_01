#include "rush01.h"

int is_valid_placement(int grid[4][4], int row, int col, int num)
{
  int c;
  int r;

  c = 0;
  while (c < col)
  {
    if (grid[row][c] == num)
      return (0);
    c++;
  }
  r = 0;
  while (r < row)
  {
    if (grid[r][col] == num)
      return (0);
    r++;
  }
  return (1);
}

void reverse_array(int *arr, int size)
{
  int i;
  int temp;

  i = 0;
  while (i < size / 2)
  {
    temp = arr[i];
    arr[i] = arr[size - 1 - i];
    arr[size - 1 - i] = temp;
    i++;
  }
}

void extract_column(int grid[4][4], int col, int *temp)
{
  int i;

  i = 0;
  while (i < 4)
  {
    temp[i] = grid[i][col];
    i++;
  }
}

int validate_row(int grid[4][4], int *clues, int row)
{
  int temp[4];
  int i;

  i = 0;
  while (i < 4)
  {
    temp[i] = grid[row][i];
    i++;
  }
  if (count_visible(temp, 4) != clues[8 + row])
    return (0);
  reverse_array(temp, 4);
  if (count_visible(temp, 4) != clues[12 + row])
    return (0);
  return (1);
}

int validate_column(int grid[4][4], int *clues, int col)
{
  int temp[4];

  extract_column(grid, col, temp);
  if (count_visible(temp, 4) != clues[col])
    return (0);
  reverse_array(temp, 4);
  if (count_visible(temp, 4) != clues[4 + col])
    return (0);
  return (1);
}

int validate_constraints(int grid[4][4], int *clues, int row, int col)
{
  if (col == 3)
  {
    if (!validate_row(grid, clues, row))
      return (0);
  }
  if (row == 3)
  {
    if (!validate_column(grid, clues, col))
      return (0);
  }
  return (1);
}
