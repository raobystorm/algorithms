package threesum

import (
	"sort"
	"strconv"
)

// This solution is not AC

func abs(a int) int {
	if a < 0 {
		return -1 * a
	}
	return a
}

func recur(nums []int, hash map[int]int, res *[][]int, check map[string]struct{}, i int, j int) {
	if i >= j {
		return
	}
	if v, ok := hash[(nums[i]+nums[j])*-1]; ok && v > 0 {
		str := strconv.Itoa(nums[i]) + "," + strconv.Itoa(nums[j])
		if _, ok := check[str]; !ok {
			*res = append(*res, []int{nums[i], (nums[i] + nums[j]) * -1, nums[j]})
			check[str] = struct{}{}
		}
	}
	if abs(nums[i]) > abs(nums[j]) {
		hash[nums[i]]--
		recur(nums, hash, res, check, i+1, j)
		hash[nums[i]]++
	} else if abs(nums[i]) < abs(nums[j]) {
		hash[nums[j]]--
		recur(nums, hash, res, check, i, j-1)
		hash[nums[j]]++
	} else {
		hash[nums[i]]--
		recur(nums, hash, res, check, i+1, j)
		hash[nums[i]]++
		hash[nums[j]]--
		recur(nums, hash, res, check, i, j-1)
		hash[nums[j]]++
	}
}

func threeSum(nums []int) [][]int {
	if len(nums) < 3 {
		return [][]int{}
	}
	sort.Ints(nums)
	hash := map[int]int{}
	for i := range nums {
		if _, ok := hash[nums[i]]; !ok {
			hash[nums[i]] = 1
		} else {
			hash[nums[i]]++
		}
	}

	res := [][]int{}
	check := map[string]struct{}{}
	hash[nums[0]]--
	hash[nums[len(nums)-1]]--
	recur(nums, hash, &res, check, 0, len(nums)-1)
	return res
}
