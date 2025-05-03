#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
void Init_board(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols ;j++)
 			board[i][j] =set;
	}
}
void Display_board(char board[ROWS][COLS], int row, int col)
{
	/*int i = 0;
	int j = 0;
	for (i = 1; i <= row; i++)
	{
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);

		}
		printf("\n");
	}*/
	system("cls");
	int i = 0;
	int j = 0;
	for (i = 0; i <= col; i++)
	{
		printf("  %d ", i);
	}
	printf("\n");
	printf("    ");
	printf("┼");
	for (i = 0; i < col; i++)
		printf("───┼" );
	printf("\n");

	for (i = 1; i <= row; i++)
	{
		printf("  %d |", i);
		for (j = 1; j <= col; j++)
		{
			printf(" %c |", board[i][j]);
		}
		printf("\n");
		printf("    ┼");
		for (j = 0; j < col; j++)
		{
			printf("───┼");
		}
		printf("\n");
	}

}

	//system("cls");
	/*int i = 0;
	int j = 0;
	for (i = 0; i <= row; i++)
	{
		printf(" %d |", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf(" %d |", i);
		for (j = 1; j <= col; j++)
			printf(" %c |", board[i][j]);
		printf("\n");
	}
	printf("   ");
	for (int j = 0; j < SIZE; j++) {
		printf("%2d ", j + 1);
	}
	printf("\n");*/

	// 打印棋盘内容



//    for (int i = 0; i < row; i++) {
//        for (int j = 0; j < col; j++)
//        {
//
//            printf("───");
//            if (j < col)
//                printf("┼");
//        }
//        printf("\n");
//        printf("%2d ", i + 1); // 行号
//        for (int j = 0; j < col; j++) 
//        {
//            printf("│");
//            printf(" %c ", board[i][j]);
//            if (j < col )
//                printf("│"); // 列分隔线
//        }
//        printf("\n");
//
//        // 打印行分隔线
//        if (i < row ) 
//        {
//            //printf("   ");
//            for (int j = 0; j < col; j++) 
//            {
//               
//                printf("───");
//                if (j < col )
//                    printf("┼");
//            }
//            printf("\n");
//        }
//    }
	//int i = 0;
	//int j = 0;
	//for (i = 1; i < row; i++)
	//{
	//	//if (i < row)
	//	//{
	//	printf("   ");
	//	printf("┼");
	//		 for (int j = 1; j < col; j++) 
	//		 {
	//		               
	//		      printf("───");
	//		      if (j < col )
	//		           printf("┼");
	//		 }
	//	printf("\n");
	//	//}

	//	printf("%2d ", i );
	//	printf("│");// 行号
	//	for (int j = 1; j <= col; j++)
	//	{

	//		printf(" %c ", board[i][j]);
	//		if (j <= col)
	//			printf("│"); // 列分隔线
	//	}
	//	printf("\n");

	//	
	//}
	//printf("   ");
	//printf("┼");
	//for (int j = 0; j < col; j++)
	//{

	//	printf("───");
	//	if (j < col)
	//		printf("┼");
	//}
	//printf("\n");
	//printf(" %d ", 0);
	//for (j = 0; j < col; j++)
	//{
	//	printf(" %2d ", j+1 );
	//}
	//printf("\n");



void Set_mine(char mineboard[ROWS][COLS], int row, int col)
{
	int count = SETMINE;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (mineboard[x][y] == '0')
		{
			mineboard[x][y] = '1';
			count--;
		}
	}
}
void Find_mine(char mine_board[ROWS][COLS], char find_board[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	while(1)
	{
		int num = Is_win2(find_board, ROW, COL);
		printf("共有10个雷\n");
		printf("还有%d个位置没有确定\n", num);

		printf("输入确定的坐标，如‘1 1’");

	    scanf("%d%d", &x, &y);
	    if (x >= 1 && x <= row && y >= 1 && y <= col)
	    {
			if (mine_board[x][y] == '1')
			{
				printf("      #################################\n");
				printf("      #################################\n");
				printf("      #####                       #####\n");
				printf("      #####   很遗憾，你被炸死了  #####\n");
				printf("      #####                       #####\n");
				printf("      #################################\n");
				printf("      #################################\n");
				Display_board(mine_board, ROW, COL);
				break;
			}
			else
			{
				int s = (count_mine(mine_board,find_board, x, y));
				if (s != 0)
				{
					find_board[x][y] = s + '0';
					Display_board(find_board, ROW, COL);
					
				}
				else
				{
					find_board[x][y] = ' ';
					around_mine(mine_board,find_board, x, y);
					
				}
				if (Is_win(find_board, ROW, COL))
				{
					break;
				}
			}	
	    }
	    else
	    {
		printf("坐标不合法，请重新");
	    }
	}
	if (Is_win(find_board, ROW, COL))
	{
		printf("      #################################\n");
		printf("      #################################\n");
		printf("      #####                       #####\n");
		printf("      #####   恭喜你，你排完雷了  #####\n");
		printf("      #####                       #####\n");
		printf("      #################################\n");
		printf("      #################################\n");
	}

	
}
int count_mine(char mine_board[ROWS][COLS],char find_board[ROWS][COLS], int x, int y)
{
	return(
		mine_board[x - 1][y - 1] +
		mine_board[x - 1][y] +
		mine_board[x - 1][y + 1] +
		mine_board[x][y - 1] +
		mine_board[x][y + 1] +
		mine_board[x + 1][y - 1] +
		mine_board[x + 1][y] +
		mine_board[x + 1][y + 1] - 8 * '0'

		);
}
void around_mine(char mine_board[ROWS][COLS],char find_board[ROWS][COLS], int x, int y)
{
	int i = 0;
	int j = 0;
	for (i = -1; i <= 1; i++)
	{
		for (j = -1; j <= 1; j++)
		{
			if (find_board[x + i][y + j] == '*' && x+i>=1 && x+i<=9 && y+j<=9 && y+j>=1)
			{
				int s = (count_mine(mine_board, find_board, x + i, y + j));
				if (s != 0)
				{
					find_board[x+i][y+j] = s + '0';
					Display_board(find_board, ROW, COL);
					break;
				}
				else
				{
					find_board[x+i][y+j] = ' ';
					around_mine(mine_board, find_board, x+i, y+j);
					break;
				}
			}
		}
	}


}
int Is_win(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	int count = 0;
	for (i = 1; i <= row; i++)
	{
		for (j = 1; j <= col; j++)
		{
			if (board[i][j] == '*')
			{
				count++;
			}
		}
	}
	if (count > 10)
		return 0;
	else
		return 1;
}
int Is_win2(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	int count = 0;
	for (i = 1; i <= row; i++)
	{
		for (j = 1; j <= col; j++)
		{
			if (board[i][j] == '*')
			{
				count++;
			}
		}
	}
	
		return count;
	
}