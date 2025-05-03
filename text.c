#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
void menu()
{
	printf("#################################\n");
	printf("#################################\n");
	printf("###                           ###\n");
	printf("### the game 'mine clearance' ###\n");
	printf("###                           ###\n");
	printf("#################################\n");
	printf("#################################\n");
	printf("######        1.play        #####\n");
	printf("######        0.exit        #####\n");
	printf("#################################\n");
	printf("#################################\n");
	printf("\n");

}
void game()
{
	char mine_board[ROWS][COLS] = {0};
	char find_board[ROWS][COLS] = {0};
	Init_board(mine_board, ROWS, COLS,'0');
	Init_board(find_board, ROWS, COLS,'*');
	//Display_board(mine_board, ROW, COL);
	
	Set_mine(mine_board, ROW, COL);
	//Display_board(mine_board, ROW, COL);

	Display_board(find_board, ROW, COL);
	Find_mine(mine_board, find_board, ROW, COL);

	
}
	
int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("\n");
		printf(" make a choise\n ");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("exit");
			break;
		default:
			printf("You make a wrrong choise\n");
			printf("\n");
			printf("try again\n");
			break;
		}
	} while (input);
	
	
	return 0;
}
