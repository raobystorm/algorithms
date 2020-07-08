// Package hourglasssum test.
package hourglasssum

func calcSum(arr [][]int32, i int, j int) int32 {
	return arr[i-1][j-1] + arr[i-1][j] + arr[i-1][j+1] + arr[i][j] + arr[i+1][j-1] + arr[i+1][j] + arr[i+1][j+1]
}

// HourglassSum test.
func HourglassSum(arr [][]int32) int32 {
	max := int32(-100)
	sum := int32(0)
	for i := 1; i <= 4; i++ {
		for j := 1; j <= 4; j++ {
			sum = calcSum(arr, i, j)
			if sum > max {
				max = sum
			}
		}
	}
	return max
}