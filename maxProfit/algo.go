package maxprofit

func maxProfit(p []int) int {
	if len(p) <= 1 {
		return 0
	}

	min := p[0]
	res := 0
	for i := range p {
		if p[i] < min {
			min = p[i]
		}
		if p[i]-min > res {
			res = p[i] - min
		}
	}
	return res
}
