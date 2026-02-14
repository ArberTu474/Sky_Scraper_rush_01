#ifndef RUSH01_H
# define RUSH01_H

# include <unistd.h>
# include <stdlib.h>

int		solve(int grid[4][4], int *clues, int row, int col);
int		is_valid_placement(int grid[4][4], int row, int col, int num);
int		validate_constraints(int grid[4][4], int *clues, int row, int col);
int		count_visible(int *line, int size);
int		parse_input(char *str, int *clues);
void	print_grid(int grid[4][4]);
void	ft_putchar(char c);
void	ft_putstr(char *str);

#endif
