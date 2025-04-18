#include <stdio.h>

int max(int a, int b)
{
  if (a > b)
    return a;
  else
    return b;
}

int main()
{
  int M = 8, n = 4, W[4] = {3, 4, 6, 5}, P[4] = {2, 3, 1, 4}, profit = 0, table[5][9];
  for (int j = 0; j <= 4; j++)
  {
    for (int i = 0; i <= 8; i++)
    {
      if (i == 0 || j == 0)
      {
        table[j][i] = 0;
      }
      else if (W[j - 1] <= i)
      {
        table[j][i] = max(P[j - 1] + table[j - 1][i - W[j - 1]], table[j - 1][i]);
      }
      else
      {
        table[j][i] = table[j - 1][i];
      }
    }
  }
  profit = table[n][M];
  printf("Max profit: %d\n", profit);

  for (int i = 0; i <= 4; i++)
  {
    for (int j = 0; j <= 8; j++)
    {
      printf("%d ", table[i][j]);
    }
    printf("\n");
  }

  return 0;
}
