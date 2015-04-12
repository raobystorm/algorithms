
void dfs(char** grid, int row, int column, int numRows, int numColumns){

	if (grid[row][column] == '0' || grid[row][column] == -1) return;

	grid[row][column] = -1;

	if (row > 0) dfs(grid, row - 1, column, numRows, numColumns);
	if (row < numRows - 1) dfs(grid, row + 1, column, numRows, numColumns);
	if (column > 0) dfs(grid, row, column - 1, numRows, numColumns);
	if (column < numColumns - 1) dfs(grid, row, column + 1, numRows, numColumns);
}

int numIslands(char **grid, int numRows, int numColumns) {

	if (!numRows || !numColumns) return 0;

	int n = 0;

	for (int i = 0; i < numRows; i++){

		for (int j = 0; j < numColumns; j++){

			if (grid[i][j] == -1) continue;
			else if (grid[i][j] == '0') {

				grid[i][j] = -1;
				continue;
			}
			else{

				n++;
				dfs(grid, i, j, numRows, numColumns);
			}
		}
	}

	return n;
}
