#include "rush01.h"

void ft_putchar(char c)
{
  write(1, &c, 1);
}

void ft_putstr(char *str)
{
  int i;

  i = 0;
  while (str[i] != '\0')
  {
    ft_putchar(str[i]);
    i++;
  }
}

void print_grid(int grid[4][4])
{
  int row;
  int col;

  row = 0;
  while (row < 4)
  {
    col = 0;
    while (col < 4)
    {
      ft_putchar(grid[row][col] + '0');
      if (col < 3)
        ft_putchar(' ');
      col++;
    }
    ft_putchar('\n');
    row++;
  }
}
