package bytedance

func longestBitonicSubarray(arr []int) int {
	// Write your code here
	if len(arr) == 1 {
		return 1
	}
	res := 0
	dec := make([]int, len(arr))
	inc := make([]int, len(arr))
	for i := range arr {
		if i >= 1 && arr[i] >= arr[i-1] {
			dec[i] = dec[i-1] + 1
		}
	}
	for i := len(arr) - 2; i >= 0; i-- {
		if arr[i] >= arr[i+1] {
			inc[i] = inc[i+1] + 1
		}
	}
	for i := range arr {
		if dec[i]+inc[i]+1 > res {
			res = dec[i] + inc[i] + 1
		}
	}
	return res
}
