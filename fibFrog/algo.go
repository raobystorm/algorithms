package fibfrog

// The Fibonacci sequence is defined using the following recursive formula:

//     F(0) = 0
//     F(1) = 1
//     F(M) = F(M - 1) + F(M - 2) if M >= 2
// A small frog wants to get to the other side of a river. The frog is initially located at one bank of the river (position −1) and wants to get to the other bank (position N). The frog can jump over any distance F(K), where F(K) is the K-th Fibonacci number. Luckily, there are many leaves on the river, and the frog can jump between the leaves, but only in the direction of the bank at position N.

// The leaves on the river are represented in an array A consisting of N integers. Consecutive elements of array A represent consecutive positions from 0 to N − 1 on the river. Array A contains only 0s and/or 1s:

// 0 represents a position without a leaf;
// 1 represents a position containing a leaf.
// The goal is to count the minimum number of jumps in which the frog can get to the other side of the river (from position −1 to position N). The frog can jump between positions −1 and N (the banks of the river) and every position containing a leaf.

// For example, consider array A such that:

//     A[0] = 0
//     A[1] = 0
//     A[2] = 0
//     A[3] = 1
//     A[4] = 1
//     A[5] = 0
//     A[6] = 1
//     A[7] = 0
//     A[8] = 0
//     A[9] = 0
//     A[10] = 0
// The frog can make three jumps of length F(5) = 5, F(3) = 2 and F(5) = 5.

// Write a function:

// func Solution(A []int) int

// that, given an array A consisting of N integers, returns the minimum number of jumps by which the frog can get to the other side of the river. If the frog cannot reach the other side of the river, the function should return −1.

// For example, given:

//     A[0] = 0
//     A[1] = 0
//     A[2] = 0
//     A[3] = 1
//     A[4] = 1
//     A[5] = 0
//     A[6] = 1
//     A[7] = 0
//     A[8] = 0
//     A[9] = 0
//     A[10] = 0
// the function should return 3, as explained above.

// Write an efficient algorithm for the following assumptions:

// N is an integer within the range [0..100,000];
// each element of array A is an integer that can have one of the following values: 0, 1.

func min(a int, b int) int {
	if a < b {
		return a
	}
	return b
}

func Solution(A []int) int {
	// For 100000 we need 27 fib numbers
	fibs := make([]int, 27)
	fibs[1] = 1
	for i := 2; i < len(fibs); i++ {
		fibs[i] = fibs[i-1] + fibs[i-2]
	}

	dp := make([]int, len(A))
	for i := range dp {
		dp[i] = 999999
	}
	for i := len(A) - 1; i >= 0; i-- {
		if A[i] == 0 {
			continue
		}
		// dp[i] = min(dp[i], dp[i+fibs[j]] + 1) for all j in fibs
		for j := range fibs {
			if i+fibs[j] > len(A) {
				break
			}
			if i+fibs[j] == len(A) {
				// Those place could reach end bank
				if A[i] == 1 {
					dp[i] = 1
				}
				break
			}
			if A[i+fibs[j]] == 1 {
				dp[i] = min(dp[i], dp[i+fibs[j]]+1)
			}
		}
	}
	res := 999999
	// Now from start bank find where can jump to
	for i := 0; i < len(fibs); i++ {
		if fibs[i] == len(A)+1 {
			// For case we can directly jump from start to end
			return 1
		}
		if fibs[i] >= 1 && fibs[i]-1 < len(dp) {
			res = min(res, dp[fibs[i]-1]+1)
		}
	}
	if res != 999999 {
		return res
	}
	return -1


func min(a int, b int) int {
	if a < b {
		return a
	}
	return b
}

func Solution(A []int) int {
	fibs := make([]int, 27)
	fibs[1] = 1
	for i := 2; i < len(fibs); i++ {
		fibs[i] = fibs[i-1] + fibs[i-2]
	}

	dp := make([]int, len(A))
	for i := range dp {
		dp[i] = 999999
	}
	for i := len(A) - 1; i >= 0; i-- {
		if A[i] == 0 {
			continue
		}
		// dp[i] = min(dp[i], dp[i+fibs[j]]) for all j in fibs
		for j := range fibs {
			if i+fibs[j] > len(A) {
				break
			}
			if i+fibs[j] == len(A) {
				if A[i] == 1 {
					dp[i] = 1
				}
				break
			}
			if A[i+fibs[j]] == 1 {
				dp[i] = min(dp[i], dp[i+fibs[j]]+1)
			}
		}
	}
	res := 999999
	for i := 0; i < len(fibs); i++ {
		if fibs[i] == len(A)+1 {
			return 1
		}
		if fibs[i] >= 1 && fibs[i]-1 < len(dp) {
			res = min(res, dp[fibs[i]-1]+1)
		}
	}
	if res != 999999 {
		return res
	}
	return -1
}
