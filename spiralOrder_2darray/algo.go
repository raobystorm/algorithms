package spiralorder

// 给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。
// 示例 1：

// 输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
// 输出：[1,2,3,6,9,8,7,4,5]
// 示例 2：

// 输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
// 输出：[1,2,3,4,8,12,11,10,9,5,6,7]

// 提示：
// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 10
// -100 <= matrix[i][j] <= 100

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/spiral-matrix
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

func spiralOrder(m [][]int) []int {
	res := []int{}
	row, col := 0, 0
	status := 0 // Use a var to store current status
	for i := 0; i < len(m)*len(m[0]); i++ {
		res = append(res, m[row][col])
		m[row][col] = -1001 // Flag the cell accessed
		// Status machine here. 4 status in total
		if status == 0 { // Go right
			if col == len(m[0])-1 || m[row][col+1] == -1001 { // Turn down if next is border or visited cell
				status = 1
				row++
			} else {
				col++
			}
		} else if status == 1 { // Go down
			if row == len(m)-1 || m[row+1][col] == -1001 {
				status = 2
				col--
			} else {
				row++
			}
		} else if status == 2 { // Go left
			if col == 0 || m[row][col-1] == -1001 {
				status = 3
				row--
			} else {
				col--
			}
		} else if status == 3 { // Go up
			if m[row-1][col] == -1001 {
				status = 0
				col++
			} else {
				row--
			}
		}
	}
	return res
}
