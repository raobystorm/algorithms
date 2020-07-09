package minimumswap

// MinimumSwaps The arr[i] is consecutive! That means in sorted array, arr[i] = i+1
func MinimumSwaps(arr []int) int {
	cnt := 0
	for i := 0; i < len(arr); i++ {
		if arr[i] != i+1 {
			// As long as arr[i] is not in correct pos, swap arr[i], arr[arr[i]-1]
			// arr[i]-1 is the correct pos of arr[i]
			for arr[i] != i+1 {
				arr[i], arr[arr[i]-1] = arr[arr[i]-1], arr[i]
				cnt++
			}
		}
	}
	return cnt
}
