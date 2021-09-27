package removekdigits

// Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.

// Example 1:

// Input: num = "1432219", k = 3
// Output: "1219"
// Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.

// Example 2:

// Input: num = "10200", k = 1
// Output: "200"
// Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.

// Example 3:

// Input: num = "10", k = 2
// Output: "0"
// Explanation: Remove all the digits from the number and it is left with nothing which is 0.

// Constraints:

//     1 <= k <= num.length <= 105
//     num consists of only digits.
//     num does not have any leading zeros except for the zero itself.

func removeKdigits(num string, k int) string {
	if len(num) == k {
		return "0"
	}
	stk := []byte{}
	for i := range num {
		// 使用一个stack保存当前字串，当新输入字符比当前最后的元素大，并且k大于0的时候持续弹出栈尾，再将新字符添加到栈尾
		for k > 0 && len(stk) != 0 && stk[len(stk)-1] > num[i] {
			k--
			stk = stk[:len(stk)-1]
		}
		stk = append(stk, num[i])
	}
	for k > 0 {
		stk = stk[:len(stk)-1]
		k--
	}
	for len(stk) > 1 && stk[0] == '0' {
		stk = stk[1:]
	}
	return string(stk)
}
