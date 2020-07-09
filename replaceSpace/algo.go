package replacespace

import "strings"

// ReplaceSpace Refer to strings.Replace
func ReplaceSpace(s string) string {
	// Compute number of replacements.
	m := strings.Count(s, " ")

	// Apply replacements to buffer.
	t := make([]byte, len(s)+m*2)
	w := 0
	start := 0
	for i := 0; i < m; i++ {
		j := start
		j += strings.Index(s[start:], " ")
		w += copy(t[w:], s[start:j])
		w += copy(t[w:], "%20")
		start = j + len(" ")
	}
	w += copy(t[w:], s[start:])
	return string(t[0:w])
}
