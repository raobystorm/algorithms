package ismatch

func IsMatch(s string, p string) bool {
	if s == "" && p == "" {
		return true
	}

	if s != "" && p == "" {
		return false
	}

	if len(p) > 1 && p[1] == '*' {
		if len(p) > 0 && len(s) > 0 && (p[0] == s[0] || (p[0] == '.' && s != "")) {
			return IsMatch(s[1:], p[2:]) || IsMatch(s[1:], p) || IsMatch(s, p[2:])
		} else {
			return IsMatch(s, p[2:])
		}
	}

	if len(s) > 0 && len(p) > 0 {
		if s[0] == p[0] || (p[0] == '.' && s != "") {
			return IsMatch(s[1:], p[1:])
		}
	}

	return false
}
