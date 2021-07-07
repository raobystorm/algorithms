package searchinrotatedarray

// 整数数组 nums 按升序排列，数组中的值 互不相同 。

// 在传递给函数之前，nums 在预先未知的某个下标 k（0 <= k < nums.length）上进行了 旋转，使数组变为 [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]（下标 从 0 开始 计数）。例如， [0,1,2,4,5,6,7] 在下标 3 处经旋转后可能变为 [4,5,6,7,0,1,2] 。

// 给你 旋转后 的数组 nums 和一个整数 target ，如果 nums 中存在这个目标值 target ，则返回它的下标，否则返回 -1 。

// 示例 1：

// 输入：nums = [4,5,6,7,0,1,2], target = 0
// 输出：4
// 示例 2：

// 输入：nums = [4,5,6,7,0,1,2], target = 3
// 输出：-1
// 示例 3：

// 输入：nums = [1], target = 0
// 输出：-1
//

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/search-in-rotated-sorted-array
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

func bsearch(n []int, t int, l int, r int) int {
	// 将该死的edge case全部排除掉
	if l >= r {
		return l
	}
	if n[l] == t {
		return l
	}
	if n[r] == t {
		return r
	}
	piv := (l + r) / 2
	if n[piv] == t {
		return piv
	}
	// 总共8种情况，要分开n是否已经是升序排列
	if n[l] < n[r] {
		// 当n已经升序排列时，只需要看piv和t的大小，普通的二分查找
		if n[piv] > t {
			return bsearch(n, t, l, piv-1)
		}
		return bsearch(n, t, piv+1, r)
	}
	// 下面是当n中间还包括旋转点的情况
	// 当piv大于t时有三种：
	if n[piv] > t {

		// 1. t和p都在旋转点的左侧
		if t > n[l] {
			return bsearch(n, t, l, piv-1)
		}
		// 2. t和p都在旋转点的右侧
		if n[piv] < n[r] {
			return bsearch(n, t, l, piv-1)
		}
		// 3. t在左侧，p在旋转点右侧
		return bsearch(n, t, piv+1, r)
	}
	// 当piv小于t时也有三种：
	// 1. 当t和p都在旋转点左侧
	if n[piv] > n[l] {
		return bsearch(n, t, piv+1, r)
	}
	// 2. 都在右侧
	if t < n[r] {
		return bsearch(n, t, piv+1, r)
	}
	// 3. t在左侧，p在旋转点右侧
	return bsearch(n, t, l, piv-1)
}

func search(nums []int, target int) int {
	idx := bsearch(nums, target, 0, len(nums)-1)
	if nums[idx] == target {
		return idx
	}
	return -1
}
