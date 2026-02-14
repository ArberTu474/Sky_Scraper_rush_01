#include "rush01.h"

int count_visible(int *line, int size)
{
  int visible;
  int max_height;
  int i;

  visible = 0;
  max_height = 0;
  i = 0;
  while (i < size)
  {
    if (line[i] > max_height)
    {
      visible++;
      max_height = line[i];
    }
    i++;
  }
  return (visible);
}
