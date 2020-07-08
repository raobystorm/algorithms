// Package largestretangle sss
package largestretangle

// LargestRectArea test
func LargestRectArea(arr []int) int {
	stk := []int{-1}
	maxArea := 0

	var idx int
	for i := range arr {
		for stk[len(stk)-1] != -1 && arr[stk[len(stk)-1]] >= arr[i] {
			idx, stk = stk[len(stk)-1], stk[:len(stk)-1]
			area := arr[idx] * (i - stk[len(stk)-1] - 1)
			if area > maxArea {
				maxArea = area
			}
		}
		stk = append(stk, i)
	}

	for stk[len(stk)-1] != -1 {
		idx, stk = stk[len(stk)-1], stk[:len(stk)-1]
		area := arr[idx] * (len(arr) - stk[len(stk)-1] - 1)
		if area > maxArea {
			maxArea = area
		}
	}

	return maxArea
}
