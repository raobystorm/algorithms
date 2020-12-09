package minnumber

import (
	"sort"
	"strconv"
	"strings"
)

type Nums []string

func (n Nums) Len() int      { return len(n) }
func (n Nums) Swap(i, j int) { n[i], n[j] = n[j], n[i] }
func (n Nums) Less(i, j int) bool {
	return n[i]+n[j] < n[j]+n[i]
}

func minNumber(nums []int) string {
	strs := Nums{}
	for i := range nums {
		strs = append(strs, strconv.Itoa(nums[i]))
	}
	sort.Sort(strs)
	return strings.Join(strs, "")
}
