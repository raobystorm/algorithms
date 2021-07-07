package flags

import (
	"math"
)

// A non-empty array A consisting of N integers is given.

// A peak is an array element which is larger than its neighbours. More precisely, it is an index P such that 0 < P < N − 1 and A[P − 1] < A[P] > A[P + 1].

// For example, the following array A:

//     A[0] = 1
//     A[1] = 5
//     A[2] = 3
//     A[3] = 4
//     A[4] = 3
//     A[5] = 4
//     A[6] = 1
//     A[7] = 2
//     A[8] = 3
//     A[9] = 4
//     A[10] = 6
//     A[11] = 2
// has exactly four peaks: elements 1, 3, 5 and 10.

// You are going on a trip to a range of mountains whose relative heights are represented by array A, as shown in a figure below. You have to choose how many flags you should take with you. The goal is to set the maximum number of flags on the peaks, according to certain rules.

// Flags can only be set on peaks. What's more, if you take K flags, then the distance between any two flags should be greater than or equal to K. The distance between indices P and Q is the absolute value |P − Q|.

// For example, given the mountain range represented by array A, above, with N = 12, if you take:

// two flags, you can set them on peaks 1 and 5;
// three flags, you can set them on peaks 1, 5 and 10;
// four flags, you can set only three flags, on peaks 1, 5 and 10.
// You can therefore set a maximum of three flags in this case.

// Write a function:

// func Solution(A []int) int

// that, given a non-empty array A of N integers, returns the maximum number of flags that can be set on the peaks of the array.

// For example, the following array A:

//     A[0] = 1
//     A[1] = 5
//     A[2] = 3
//     A[3] = 4
//     A[4] = 3
//     A[5] = 4
//     A[6] = 1
//     A[7] = 2
//     A[8] = 3
//     A[9] = 4
//     A[10] = 6
//     A[11] = 2
// the function should return 3, as explained above.

// Write an efficient algorithm for the following assumptions:

// N is an integer within the range [1..400,000];
// each element of array A is an integer within the range [0..1,000,000,000].

func min(a int, b int) int {
	if a < b {
		return a
	}
	return b
}

func Solution(A []int) int {
	if len(A) <= 2 {
		return 0
	}
	N := len(A)
	pCnt := 0
	// Count peaks first
	peaks := make([]bool, N)
	for i := 1; i+1 < N; i++ {
		if A[i-1] < A[i] && A[i] > A[i+1] {
			peaks[i] = true
			pCnt++
		}
	}
	if pCnt < 2 {
		return pCnt
	}
	// make an array to store next peak pos at location i
	next := make([]int, N)
	for i := N - 2; i >= 0; i-- {
		if peaks[i] {
			next[i] = i
		} else {
			next[i] = next[i+1]
		}
	}

	for i := min(int(math.Sqrt(float64(N)))+1, pCnt); i >= 2; i-- {
		// because we have next arr, find next peak after pos i+j will be constant
		// every time we find next peak after pos j + i, and set j to that pos.
		// If all flags could be placed then it is a solution
		leftCnt := i - 1
		j := next[0]
		for j < N {
			if j+i >= N || next[j+i] == 0 {
				break
			}
			j = next[j+i]
			leftCnt--
			if leftCnt == 0 {
				return i
			}
		}
	}
	return 0
}
