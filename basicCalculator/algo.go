package basiccalculator

/*

Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, '+', '-', '*', '/' operators, and open '(' and closing parentheses ')'. The integer division should truncate toward zero.

You may assume that the given expression is always valid. All intermediate results will be in the range of [-231, 231 - 1].

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

Example 1:

Input: s = "1+1"
Output: 2

Example 2:

Input: s = "6-4/2"
Output: 4

Example 3:

Input: s = "2*(5+5*2)/3+(6/2+8)"
Output: 21

Constraints:

    1 <= s <= 104
    s consists of digits, '+', '-', '*', '/', '(', and ')'.
    s is a valid expression.

*/

func calculate(s string) int {
	i := 0
	ops := []byte{}
	nums := []int{}
	for i < len(s) {
		if s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' {
			// if is operator store it in ops
			ops = append(ops, s[i])
			i++
		} else if s[i] == '(' {
			// if is left parenthesis, evaluate the expression inside it
			j := i + 1
			subStr := []byte{}
			stk := 1
			for j < len(s) {
				if s[j] == ')' && stk == 1 {
					break
				}
				if s[j] == '(' {
					stk++
				}
				if s[j] == ')' {
					stk--
				}
				subStr = append(subStr, s[j])
				j++
			}
			nums = append(nums, calculate(string(subStr)))
			i = j + 1
		} else {
			// if is number, store it in nums
			num := 0
			for i < len(s) && s[i] <= '9' && s[i] >= '0' {
				num *= 10
				num += int(s[i] - '0')
				i++
			}
			nums = append(nums, num)
		}
	}

	i = 0
	for i < len(ops) {
		// because multiplication and division has high priority, eval them first.
		// because division has precision problem, so keep from left to right order
		if ops[i] == '*' {
			nums[i] = nums[i] * nums[i+1]
			nums = append(nums[:i+1], nums[i+2:]...)
			ops = append(ops[:i], ops[i+1:]...)
		} else if ops[i] == '/' {
			nums[i] = nums[i] / nums[i+1]
			nums = append(nums[:i+1], nums[i+2:]...)
			ops = append(ops[:i], ops[i+1:]...)
		} else {
			i++
		}
	}
	i = 0
	for i < len(ops) {
		// because there is minus number, keep left to right order for substract
		if ops[i] == '+' {
			nums[i] = nums[i] + nums[i+1]
			nums = append(nums[:i+1], nums[i+2:]...)
			ops = append(ops[:i], ops[i+1:]...)
		} else if ops[i] == '-' {
			nums[i] = nums[i] - nums[i+1]
			nums = append(nums[:i+1], nums[i+2:]...)
			ops = append(ops[:i], ops[i+1:]...)
		} else {
			i++
		}
	}
	return nums[0]
}
