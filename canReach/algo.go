package canreach

func dfs(arr []int, checked []bool, idx int) bool {
	if idx < 0 || idx >= len(arr) || checked[idx] {
		return false
	}
	if !checked[idx] && arr[idx] == 0 {
		return true
	}
	checked[idx] = true
	if dfs(arr, checked, idx+arr[idx]) || dfs(arr, checked, idx-arr[idx]) {
		return true
	}
	return false
}

func canReach(arr []int, start int) bool {
	checked := make([]bool, len(arr))
	return dfs(arr, checked, start)
}
