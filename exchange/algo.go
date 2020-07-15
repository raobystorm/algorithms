package exchange

func Exchange(n []int) []int {
	i := 0
	j := len(n) - 1
	for i < j {
		for i < len(n) && n[i]%2 == 1 {
			i++
		}
		for j >= 0 && n[j]%2 == 0 {
			j--
		}
		if i < j {
			n[i], n[j] = n[j], n[i]
		}
	}
	return n
}
