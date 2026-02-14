#include "rush01.h"

/* 
Takes a string of arguments as input for the clues of the gird
It validates if the characters are only numbers betwenn 1 and 4
There should be only 16 clues
*/
int parse_input(char *str, int *clues)
{
  int i;
  int j;

  i = 0;
  j = 0;
  while (str[j] != '\0')
  {
    if (str[j] == ' ')
    {
      j++;
      continue;
    }
    if (str[j] >= '1' && str[j] <= '4')
    {
      clues[i] = str[j] - '0';
      i++;
      j++;
      if (str[j] >= '0' && str[j] <= '9')
        return (0);
      continue;
    }
    return (0);
  }
  if (i == 16)
    return (1);
  return (0);
}

/* 
Fills a 4 by 4 2D array with 0
*/
void init_grid(int grid[4][4])
{
  int row;
  int col;

  row = 0;
  while (row < 4)
  {
    col = 0;
    while (col < 4)
    {
      grid[row][col] = 0;
      col++;
    }
    row++;
  }
}

int main(int argc, char **argv)
{
  int clues[16];
  int grid[4][4];

  if (argc != 2)
  {
    ft_putstr("Error\n");
    return (1);
  }
  if (!parse_input(argv[1], clues))
  {
    ft_putstr("Error\n");
    return (1);
  }
  init_grid(grid);
  if (solve(grid, clues, 0, 0))
  {
    print_grid(grid);
    return (0);
  }
  ft_putstr("Error\n");
  return (1);
}
