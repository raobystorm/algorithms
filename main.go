package main

import (
	"fmt"
	tst "gotest/maxarraysum"
)

func main() {
	fmt.Println(tst.MaxSubsetSum([]int{3, 7, 4, 6, 5}))
	fmt.Println(tst.MaxSubsetSum([]int{2, 1, 5, 8, 4}))
	fmt.Println(tst.MaxSubsetSum([]int{3, 5, -7, 8, 10}))
	fmt.Println(tst.MaxSubsetSum([]int{7, 2, 4, 5, -1, 0, -6, -3, 4, -5, 6}))
}
