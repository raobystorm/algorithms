package permute

// 给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。

// 示例 1：

// 输入：nums = [1,2,3]
// 输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
// 示例 2：

// 输入：nums = [0,1]
// 输出：[[0,1],[1,0]]
// 示例 3：

// 输入：nums = [1]
// 输出：[[1]]
//

func permute(nums []int) [][]int {
	if len(nums) == 1 {
		return [][]int{{nums[0]}}
	}

	res := [][]int{}
	curr := permute(nums[1:])
	for i := 0; i <= len(curr[0]); i++ {
		for j := range curr {
			currRes := make([]int, len(curr[j])+1)
			idx := 0
			for idx < i {
				currRes[idx] = curr[j][idx]
				idx++
			}
			currRes[idx] = nums[0]
			for idx < len(curr[j]) {
				currRes[idx+1] = curr[j][idx]
				idx++
			}
			res = append(res, currRes)
		}
	}
	return res
}
