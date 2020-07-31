package permutation

type void struct{}

func Permutation(s string) []string {
	res := make([]string, 0)
	dfs([]byte(s), 0, &res)

	return res
}

func dfs(str []byte, start int, res *[]string) {
	if start == len(str) {
		*res = append(*res, string(str))
	}
	m := make(map[byte]void)
	for i := start; i < len(str); i++ {
		if _, ok := m[str[i]]; ok {
			continue
		}
		m[str[i]] = void{}
		str[start], str[i] = str[i], str[start]
		dfs(str, start+1, res)
		// 交换回来，用于判断后面是否重复
		str[start], str[i] = str[i], str[start]
	}
}
