#include "game.h"
 
int NumberMine(char mine[ROWS][COLS], int x, int y)
{
	int i, j, count = 0;
	for (i = x - 1; i <= x + 1; i++)
	{
		for (j = y - 1; j <= y + 1; j++)
		{
			if (mine[i][j] == '#')
			{
				count++;
			}
		}
	}
	return count;
}
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i, j;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}
 
void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i, j;
	printf("----------扫雷游戏----------\n");
	for (i = 0; i <= row; i++)
	{
		printf("%-2d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%-2d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c  ", board[i][j]);
		}
		printf("\n");
	}
	printf("----------扫雷游戏----------\n");
}
 
void SetMine(char board[ROWS][COLS], int row, int col)
{
	int x, y, count = 0, i, j, l, k;
	while (count != EASY)
	{
		x = rand() % ROW + 1;
		y = rand() % COL + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '#';
			count++;
		}
	}
}
 
void SearchBlank(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y)
{
	if (x >= 1 && x <= ROW && y >= 1 && y <= COL)
	{
		if (show[x][y] != '*')
			return;
		int count = NumberMine(mine, x, y);
		if (count != 0)
		{
			show[x][y] = count + '0';
			return;
		}
		if (count == 0)
		{
			show[x][y] = '0';
			SearchBlank(mine, show, x - 1, y - 1);
			SearchBlank(mine, show, x - 1, y);
			SearchBlank(mine, show, x - 1, y + 1);
			SearchBlank(mine, show, x, y - 1);
			SearchBlank(mine, show, x, y + 1);
			SearchBlank(mine, show, x + 1, y - 1);
			SearchBlank(mine, show, x + 1, y);
			SearchBlank(mine, show, x + 1, y + 1);
		}
	}
}
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x, y, count = 0, i, j;
	while (1)
	{
		printf("请下棋:");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (show[x][y] != '*')
			{
				printf("该坐标已经下过了，请重新输入\n");
				continue;
			}
			else if (mine[x][y] == '#')
			{
				printf("很遗憾，你被炸死了\n");
				DisplayBoard(mine, ROW, COL);
				break;
			}
			else
			{
				SearchBlank(mine, show, x, y);
				DisplayBoard(show, ROW, COL);
			}
		}
		else
		{
			printf("坐标非法，请重新输入\n");
			continue;
		}
		count = 0;
		for (i = 1; i <= row; i++)
		{
			for (j = 1; j <= col; j++)
			{
				if (show[i][j] != '*')
				{
					count++;
				}
			}
		}
		if (count == ROW * COL - EASY)
		{
			printf("恭喜你，你排出了所有的雷\n");
			DisplayBoard(mine, ROW, COL);
			break;
		}
	}
}