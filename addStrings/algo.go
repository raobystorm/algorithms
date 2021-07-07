package addstrings

// 给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。
// 提示：

// num1 和num2 的长度都小于 5100
// num1 和num2 都只包含数字 0-9
// num1 和num2 都不包含任何前导零
// 你不能使用任何內建 BigInteger 库， 也不能直接将输入的字符串转换为整数形式

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/add-strings
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

func longerStr(s1 string, s2 string) string {
	if len(s1) > len(s2) {
		return s1
	}
	return s2
}

func addStrings(num1 string, num2 string) string {
	i := 0
	flag, curr := 0, 0
	res := []byte{}
	for len(num1)-i >= 1 && len(num2)-i >= 1 {
		curr = int(num1[len(num1)-i-1]-'0'+num2[len(num2)-i-1]-'0') + flag
		flag = curr / 10
		curr = curr % 10
		res = append([]byte{byte(curr) + '0'}, res...)
		i++
	}
	next := longerStr(num1, num2)
	for i <= len(next)-1 {
		curr = int(next[len(next)-i-1]-'0') + flag
		flag = curr / 10
		curr = curr % 10
		res = append([]byte{byte(curr) + '0'}, res...)
		i++
	}
	if flag == 1 {
		return "1" + string(res)
	}
	return string(res)
}
