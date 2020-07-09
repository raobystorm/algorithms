package searchmatrix

// SearchMatrix .
func SearchMatrix(mat [][]int, t int) bool {
	res := false
	if len(mat) > 0 && len(mat[0]) > 0 {
		row := 0
		// Count from right upper corner
		col := len(mat[0]) - 1
		for row < len(mat) && col >= 0 {
			if mat[row][col] == t {
				res = true
				break
			} else if mat[row][col] > t {
				// if current is larger, search left part
				col--
			} else {
				// if current is smaller, search lower part
				row++
			}
		}
	}
	return res
}
