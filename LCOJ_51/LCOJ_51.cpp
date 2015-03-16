// LCOJ_51.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <string>
#include <bitset>


using namespace std;

#define MAX			30

int board[MAX][MAX] = {0};
int n;

class Solution {
public:
	// check this slot is available for put a queen now or not
	inline bool check(int& row, int& column){
	
		if (!board[row][column]) return true;
		return false;
	}
	// check this row is available for put a queen now or not
	inline bool checkRow(int& row){
	
		for (int i = 0; i < n; i++){
		
			if (check(row, i)) return true;
		}
		return false;
	}
	// for one direction, set the slot to plus 1 when putting a queen or -1 for taking a queen
	inline void searchDirec(int &inc, int row, int column, int rowInc, int colInc){
	
		while (1){
		
			if (!((row >= 0) && (row < n))) return;
			if (!((column >= 0) && (column < n))) return;

			board[row][column] += inc;

			row += rowInc;
			column += colInc;
		}
	}
	// for putting or taking a queen, set the slot to -1 and add 1 to all slots that could be dominated by this queen
	inline void putQueen(bool isPut, int row, int column){

		int inc = isPut ? 1 : -1;
		if(isPut) board[row][column] = -1;
		else board[row][column] = 0;

		searchDirec(inc, row - 1, column - 1, -1, -1 );
		searchDirec(inc, row - 1, column , -1, 0 );
		searchDirec(inc, row - 1, column + 1, -1, 1 );

		searchDirec(inc, row, column - 1, 0, -1 );
		searchDirec(inc, row, column + 1, 0, 1 );

		searchDirec(inc, row + 1, column - 1, 1, -1);
		searchDirec(inc, row + 1, column, 1, 0);
		searchDirec(inc, row + 1, column + 1, 1, 1);
	}
	// when find a solution, print the board and save
	inline void addSolution(vector<vector<string>>& res){
	
		vector<string> resTmp;
		for (int i = 0; i < n; i++){
		
			char printrow[MAX] = { '\0' };
			for (int j = 0; j < n; j++){
			
				if (board[i][j] == -1) printrow[j] = 'Q';
				else printrow[j] = '.';
			}
			resTmp.push_back(string(printrow));
		}
		res.push_back(resTmp);
	}
	// search next row for the slots that worth to try
	inline void searchNextRow(int row, vector<vector<string>>& res){
	
		if (row >= n){
		
			addSolution(res);
			return;
		}

		if (!checkRow(row)) return;

		for (int i = 0; i < n; i++){
		
			if (!check(row, i)) continue;
			putQueen(true, row, i);
			searchNextRow(row + 1, res);
			putQueen(false, row, i);
		}
	}

	vector<vector<string> > solveNQueens(int m) {
		
		vector<string> srow;
		vector<vector<string>> res;
		n = m;

		if (n < 1) return res;
		if (n == 1) { srow.push_back("Q"); res.push_back(srow); return res; }
		if (n == 2 || n == 3) return res;
	
		searchNextRow(0, res);

		return res;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	n = 4;
	Solution s;
	vector<vector<string>> res = s.solveNQueens(n);
	return 0;
}

