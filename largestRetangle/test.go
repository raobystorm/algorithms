// Package largestretangle sss
package largestretangle

// LargestRectArea test
func LargestRectArea(arr []int) int {
	// stk is the stack to store current increasing indexs
	stk := []int{-1}
	maxArea := 0

	var idx int
	for i := range arr {
		for stk[len(stk)-1] != -1 && arr[stk[len(stk)-1]] >= arr[i] {
			// when arr[i] < arr[j] for j in stk && !stk.empty()
			// check rectangle from arr[j] to arr[i], for j in stk
			idx, stk = stk[len(stk)-1], stk[:len(stk)-1]
			area := arr[idx] * (i - stk[len(stk)-1] - 1)
			if area > maxArea {
				maxArea = area
			}
		}
		// current arr[i] is in increasing series, push into stk
		stk = append(stk, i)
	}

	// when stk is not empty, also check the rectangle for j in stk
	for stk[len(stk)-1] != -1 {
		idx, stk = stk[len(stk)-1], stk[:len(stk)-1]
		area := arr[idx] * (len(arr) - stk[len(stk)-1] - 1)
		if area > maxArea {
			maxArea = area
		}
	}

	return maxArea
}
