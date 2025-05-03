#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define SETMINE 10
void Init_board(char board[ROWS][COLS], int rows, int cols, char set);
void Display_board(char board[ROWS][COLS], int row, int col);
void Set_mine(char mineboard[ROWS][COLS], int row, int col);
void Find_mine(char mine_board[ROWS][COLS], char find_board[ROWS][COLS], int row, int col);
int count_mine(char mine_board[ROWS][COLS],char find_board[ROWS][COLS], int x, int y);
void around_mine(char mine_board[ROWS][COLS], char find_board[ROWS][COLS], int x, int y);
int Is_win(char board[ROWS][COLS], int row, int col);