package majorityelement

// https://leetcode-cn.com/problems/shu-zu-zhong-chu-xian-ci-shu-chao-guo-yi-ban-de-shu-zi-lcof
// Time: O(n), Space: O(1)
func majorityElement(nums []int) int {
	res, cnt := 0, 0
	for i := range nums {
		// Idea: majority element is more than anything else
		if cnt == 0 {
			res = nums[i]
			cnt++
		} else if res == nums[i] {
			cnt++
		} else {
			cnt--
		}
	}
	return res
}
