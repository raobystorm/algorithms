package countNonDivisor

// You are given an array A consisting of N integers.

// For each number A[i] such that 0 ≤ i < N, we want to count the number of elements of the array that are not the divisors of A[i]. We say that these elements are non-divisors.

// For example, consider integer N = 5 and array A such that:

//     A[0] = 3
//     A[1] = 1
//     A[2] = 2
//     A[3] = 3
//     A[4] = 6
// For the following elements:

// A[0] = 3, the non-divisors are: 2, 6,
// A[1] = 1, the non-divisors are: 3, 2, 3, 6,
// A[2] = 2, the non-divisors are: 3, 3, 6,
// A[3] = 3, the non-divisors are: 2, 6,
// A[4] = 6, there aren't any non-divisors.
// Write a function:

// func Solution(A []int) []int

// that, given an array A consisting of N integers, returns a sequence of integers representing the amount of non-divisors.

// Result array should be returned as an array of integers.

// For example, given:

//     A[0] = 3
//     A[1] = 1
//     A[2] = 2
//     A[3] = 3
//     A[4] = 6
// the function should return [2, 4, 3, 2, 0], as explained above.

// Write an efficient algorithm for the following assumptions:

// N is an integer within the range [1..50,000];
// each element of array A is an integer within the range [1..2 * N].

func Solution(A []int) []int {

	n := make([]int, len(A)*2+1) // coutn A[i], n[i]: how many times i appeared in A[i]
	for i := range A {
		n[A[i]]++
	}

	div := make([]int, len(n)) // count divisors of i, div[i]: all divisors of i appeared in A[i]
	for i := range n {
		if n[i] == 0 {
			continue
		}
		for k := i; k < len(div); k += i {
			div[k] += n[i]
		}
	}
	res := make([]int, len(A))
	for i := range A {
		if res[i] == 0 {
			res[i] = len(A) - div[A[i]]
		}
	}
	return res
}
