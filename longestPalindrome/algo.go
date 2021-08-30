package longestpalindrome

// 给你一个字符串 s，找到 s 中最长的回文子串。

// 示例 1：
// 输入：s = "babad"
// 输出："bab"
// 解释："aba" 同样是符合题意的答案。

// 示例 2：
// 输入：s = "cbbd"
// 输出："bb"

// 示例 3：
// 输入：s = "a"
// 输出："a"

// 示例 4：
// 输入：s = "ac"
// 输出："a"
//

// 提示：
// 1 <= s.length <= 1000
// s 仅由数字和英文字母（大写和/或小写）组成

func min(a int, b int) int {
	if a > b {
		return b
	}
	return a
}

// 经典的回文串问题，最快速的解法是Manacher算法。O(N)
func longestPalindrome(s string) string {
	// 首先扩展原字符串，填入间隔字符和开始字符，这样可以简化条件判断
	ss := make([]byte, len(s)*2+2)
	i, j := 0, 2
	for i < len(s) {
		ss[j] = s[i]
		i++
		j += 2
	}
	ss[0] = '$' // "abcdefg" => "$0a0b0c0d0e0f0g0"
	// max:
	max, id := 0, 0
	// n[i]: 在ss中以i为中心的最长回文串的长度
	n := make([]int, len(ss)+1)
	i = 1
	for i <= len(ss) {
		if max > i {
			n[i] = min(n[2*id-i], max-i)
		} else {
			n[i] = 1
		}
		for i+n[i] < len(ss) && i-n[i] >= 0 && ss[i+n[i]] == ss[i-n[i]] {
			n[i]++
		}
		if i+n[i] > max {
			max = i + n[i]
			id = i
		}
		i++
	}
	resLen, resIdx := 0, 0
	for i := range n {
		if n[i] > resLen {
			resLen = n[i]
			resIdx = i
		}
	}

	res := []byte{}
	i, j, idx := 0, 0, 0
	for i < resLen-1 {
		idx = resIdx - resLen + 1 + j
		if ss[idx] != byte(0) && ss[idx] != '$' {
			res = append(res, ss[idx])
			i++
		}
		j++
	}
	return string(res)
}
