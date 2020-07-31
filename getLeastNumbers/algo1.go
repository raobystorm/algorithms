import "math/rand"

func partition(n []int, l int, r int) int {
	p_idx := rand.Intn(r-l+1) + l
	n[r], n[p_idx] = n[p_idx], n[r]
	p := n[r]
	i := l - 1
	for j := l; j <= r-1; j++ {
		// Keep n[:i] <= p && n[i+1:j] < p
		for n[j] <= p && i < j {
			i++
			n[i], n[j] = n[j], n[i]
		}
	}
	n[i+1], n[r] = n[r], n[i+1]
	return i + 1
}

func getLeastNumbers(arr []int, k int) []int {
	if len(arr) <= 0 || k > len(arr) || k <= 0 {
        return []int{}
    }
    start := 0
    end := len(arr) - 1
    idx := partition(arr, start, end)
    for idx != k - 1 {
        if idx > k - 1 {
            end = idx - 1
            idx = partition(arr, start, end)
        } else {
            start = idx + 1
            idx = partition(arr, start, end)
        }
    }
	return arr[:k]
}