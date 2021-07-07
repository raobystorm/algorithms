package mergetwoarrays

// Bug in leetcode golang for this question
func merge(nums1 []int, m int, nums2 []int, n int) []int {
	if n == 0 {
		return nums1
	}
	nums1 = append(nums1[m:], nums1[0:m]...)

	i, j := 0, 0
	for j < n {
		if i == m || nums1[i+m] > nums2[j] {
			nums1[i+j] = nums2[j]
			j++
			continue
		}
		nums1[i+j] = nums1[i+m]
		i++
	}
	return nums1
}
