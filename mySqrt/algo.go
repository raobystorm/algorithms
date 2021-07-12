package mysqrt

// 实现 int sqrt(int x) 函数。

// 计算并返回 x 的平方根，其中 x 是非负整数。

// 由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。

// 示例 1:

// 输入: 4
// 输出: 2
// 示例 2:

// 输入: 8
// 输出: 2
// 说明: 8 的平方根是 2.82842...,
//      由于返回类型是整数，小数部分将被舍去。

// 使用二分查找来寻找x的根
func mySqrt(x int) int {
	if x == 0 || x == 1 {
		return x
	}
	i, j := 1, x
	res := 0
	// 查找目标是 v*v <= x
	for i <= j {
		piv := (i + j) / 2
		if piv*piv == x {
			return piv
		} else if piv*piv < x {
			i = piv + 1
			res = piv
		} else {
			j = piv - 1
		}
	}
	return res
}
