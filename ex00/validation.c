#include "rush01.h"

/* 
Checks if a number can be placed in a grid cell.
For this we check if there are duplicate numbers in a row or col
*/
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

/* 
It reverses an array in place.
This function is used to count the visibility from 
the left adn the right 
*/
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

/* 
It takes a specific column and saves it at temp, 
so later we can check visibility of that col
*/
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

/* 
Checks if a row meets the visibility for the left and the right
clues when the row is filled.
- Left clues are stored in indexes 8, 9, 10, 11
- Right clues are stored in indexes 12, 13, 14, 15  
*/
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

/* 
Checks if a col meets the visibility for the top and the bottom
clues when the col is filled.
- Top clues are stored in indexes 0, 1, 2, 3
- Bottom clues are stored in indexes 4, 5, 6, 7  
*/
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

/* 
It cheks if row or col are filled with valid numbers.
*/
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
