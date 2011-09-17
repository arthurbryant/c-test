#include <stdio.h>

int n, m, i, j;
int f[1000][2050];

void
dfs (int z, int s)		//搜到第z位，此时状态为 s
{
  if (z == m + 1)		// 该行搜完，状态累加
  {
    f[i + 1][s] += f[i][j];	// 此时该状态s即由初始状态 j 可变到
    return;
    }
else
{
  if ((j >> (z - 1) & 1) == 0)	//第z位为0
    {
      if (z <= m - 1 && (j >> z & 1) == 0)	//第z+1位为0
	{
	  dfs (z + 2, s);	//如果第z+1位也为0，则搜索z+2位
	}

      dfs (z + 1, s | (1 << (z - 1)));	//将第z位变为1，并右移1位搜索
    }
  else				//第z位为1时
    {
      dfs (z + 1, s);
    }
}
}
int
main ()
{
  while (scanf ("%d %d", &n, &m) != EOF)
    {
      if (n * m % 2)
	{
	  printf ("0n");
	  continue;
	}
      else if (n + m == 0)
	{
	  break;
	}
    else
        dfs(n, m);
        }
        }
