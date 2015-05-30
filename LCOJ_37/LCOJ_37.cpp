// LCOJ_37.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <stack>
#include <unordered_set>
using namespace std;

class Solution {
public:

	// Check the available position for current digit
	bool check(vector<vector<char>>& board, int row, int col, char c){

		for (int i = 0; i < 9; i++)
			if (board[i][col] == c) return false;

		for (int i = 0; i < 9; i++)
			if (board[row][i] == c) return false;

		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				if (board[row / 3 * 3 + i][col / 3 * 3 + j] == c) return false;

		return true;
	}

	bool solve(vector<vector<char>>& board, int row, int col){
		
		if (row == board.size()) return true;

		if (board[row][col] != '.')
			if (col == board[row].size() - 1) return solve(board, row + 1, 0);
			else return solve(board, row, col + 1);

		for (int i = 0; i < 9; i++){

			if (check(board, row, col, i + '1')){
				board[row][col] = i + '1';
				if (col == (board.size()-1) && solve(board, row+1, 0)) return true;
				else if (col != (board.size() - 1) && solve(board, row, col + 1)) return true;
				board[row][col] = '.';
			}
		}
		return false;
	}

	void solveSudoku(vector<vector<char>>& board) {

		solve(board, 0, 0);
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	vector<vector<char>> boardd(9);
	for (int i = 0; i < 9; i++)
		boardd[i] = vector<char>(9, '.');

	printf("The sudoku is:\n");

	string s[9] = { "..9748...", "7........", ".2.1.9...", "..7...24.", ".64.1.59.", ".98...3..", "...8.3.2.", "........6", "...2759.." };
	for (int i = 0; i < 9; i++){

		for (int j = 0; j < 9; j++){
			boardd[i][j] = s[i][j];
			printf("%c", boardd[i][j]);
		}
		printf("\n");
	}
	printf("\n");
		
	Solution().solveSudoku(boardd);

	printf("The solution is:\n");
	
	for (int i = 0; i < 9; i++){

		for (int j = 0; j < 9; j++){

			printf("%c", boardd[i][j]);
		}
		printf("\n");
	}
	return 0;
}