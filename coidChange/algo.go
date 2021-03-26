package coinchange

func coinChange(coins []int, amount int) int {
	if amount == 0 {
		return 0
	}
	dp := make([]int, amount+1)
	for i := range dp {
		dp[i] = 99999
	}
	cc := []int{}
	for i := range coins {
		if coins[i] <= amount {
			cc = append(cc, coins[i])
			dp[coins[i]] = 1
		}
	}

	for i := range dp {
		min := 10001
		// State transform equation:
		// dp[n] = min(dp[n - coins[i]] for i in coins)
		for j := range cc {
			if i-cc[j] >= 1 && dp[i-cc[j]] != 99999 && dp[i-cc[j]]+1 < min {
				min = dp[i-cc[j]] + 1
			}
		}
		if min != 10001 && min < dp[i] {
			dp[i] = min
		}
	}
	if dp[amount] == 99999 {
		return -1
	}
	return dp[amount]
}
