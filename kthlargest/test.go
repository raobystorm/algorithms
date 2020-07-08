package kthlargest

import (
	"fmt"
	"math/rand"
)

// partition n into 3 parts
func partition(n []int, l int, r int) int {
	p_idx := rand.Intn(r-l+1) + l
	n[r], n[p_idx] = n[p_idx], n[r]
	p := n[r]
	i := l - 1

	for j := l; j <= r-1; j++ {
		// Keep n[:i] >= p && n[i+1:j] < p
		for n[j] >= p && i < j {
			i++
			n[i], n[j] = n[j], n[i]
		}
	}
	n[i+1], n[r] = n[r], n[i+1]
	return i + 1
}

func qsort(n []int, i int, j int) {
	// quicksort main
	if i < j {
		p := partition(n, i, j)
		qsort(n, i, p-1)
		qsort(n, p+1, j)
	}
}

func FindKthLargestQuickSort(nums []int, k int) int {
	qsort(nums, 0, len(nums)-1)
	fmt.Println(nums)
	return nums[k-1]
}

func FindKthLargestHeap(nums []int, k int) int {
	qsort(nums, 0, len(nums)-1)
	fmt.Println(nums)
	return nums[k-1]
}
