// LCOJ_52.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <string.h>

int res;
int n;
int board[50][50];

inline bool check(int* row, int* column){

	if (!board[*row][*column]) return true;
	return false;
}
// check this row is available for put a queen now or not
inline bool checkRow(int* row){

	for (int i = 0; i < n; i++){

		if (check(row, &i)) return true;
	}
	return false;
}
// for one direction, set the slot to plus 1 when putting a queen or -1 for taking a queen
inline void searchDirec(int *inc, int row, int column, int rowInc, int colInc){

	while (1){

		if (!((row >= 0) && (row < n))) return;
		if (!((column >= 0) && (column < n))) return;

		board[row][column] += *inc;

		row += rowInc;
		column += colInc;
	}
}
// for putting or taking a queen, set the slot to -1 and add 1 to all slots that could be dominated by this queen
inline void putQueen(bool isPut, int row, int column){

	int inc = isPut ? 1 : -1;
	if (isPut) board[row][column] = -1;
	else board[row][column] = 0;

	searchDirec(&inc, row - 1, column - 1, -1, -1);
	searchDirec(&inc, row - 1, column, -1, 0);
	searchDirec(&inc, row - 1, column + 1, -1, 1);

	searchDirec(&inc, row, column - 1, 0, -1);
	searchDirec(&inc, row, column + 1, 0, 1);

	searchDirec(&inc, row + 1, column - 1, 1, -1);
	searchDirec(&inc, row + 1, column, 1, 0);
	searchDirec(&inc, row + 1, column + 1, 1, 1);
}
// search next row for the slots that worth to try
inline void searchNextRow(int row){

	if (row >= n){

		res++;
		return;
	}

	if (!checkRow(&row)) return;

	for (int i = 0; i < n; i++){

		if (!check(&row, &i)) continue;
		putQueen(true, row, i);
		searchNextRow(row + 1);
		putQueen(false, row, i);
	}
}

int totalNQueens(int m) {
	
	memset(board, 0, 50*50*sizeof(int));
	res = 0;
	n = m;
	if (n < 1) return 0;
	if (n == 1) { return 1; }
	if (n == 2 || n == 3) return 0;

	searchNextRow(0);
	return res;
}

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

