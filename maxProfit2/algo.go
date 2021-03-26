package maxprofit2

func maxProfit(p []int) int {
	if len(p) <= 1 {
		return 0
	}
	sum := 0
	asc := true
	prev := p[0]
	for i := range p {
		if i == 0 {
			continue
		}
		if p[i] < p[i-1] {
			if asc {
				sum += p[i-1] - prev
			}
			prev = p[i]
			asc = false
		} else {
			asc = true
		}
	}
	if asc {
		sum += p[len(p)-1] - prev
	}
	return sum
}
