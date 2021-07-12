package nextpermutation

// 实现获取 下一个排列 的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。

// 如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。

// 必须 原地 修改，只允许使用额外常数空间。

// 示例 1：

// 输入：nums = [1,2,3]
// 输出：[1,3,2]
// 示例 2：

// 输入：nums = [3,2,1]
// 输出：[1,2,3]
// 示例 3：

// 输入：nums = [1,1,5]
// 输出：[1,5,1]
// 示例 4：

// 输入：nums = [1]
// 输出：[1]

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/next-permutation
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

func reverse(n *[]int, l int, r int) {
	for i, j := l, r; i < j; i, j = i+1, j-1 {
		(*n)[i], (*n)[j] = (*n)[j], (*n)[i]
	}
}

func nextPermutation(nums []int) {
	if len(nums) <= 1 {
		return
	}

	i := len(nums) - 2
	// 只需要找到第一个顺序对(i, j)，然后将较小的i和从尾部往前，第一个比i大的元素对调
	// 最后将i+1之后的元素全部反转即可（i为最接近末尾的顺序对，因此i+1到尾部都是逆序）
	for i >= 0 {
		if nums[i] < nums[i+1] {
			break
		}
		if i == 0 {
			reverse(&nums, 0, len(nums)-1)
			return
		}
		i--
	}
	j := len(nums) - 1
	for ; j > i; j-- {
		if nums[j] > nums[i] {
			break
		}
	}
	nums[i], nums[j] = nums[j], nums[i]
	reverse(&nums, i+1, len(nums)-1)
}
