package isnumber

func checkUint(s string) bool {
	i := 0
	for i < len(s) && s[i] >= '0' && s[i] <= '9' {
		i++
	}
	return (i != 0)
}

func checkInt(s string) bool {
	if s[0] == '+' || s[0] == '-' {
		return checkUint(s[1:])
	}
	return checkUint(s)
}

func IsNumber(s string) bool {
	if len(s) == 0 {
		return false
	}
	numeric := checkInt(s)
	if s[0] == '.' {
		s = s[1:]
		numeric = checkUint(s) || numeric
	}

	if s[0] == 'e' || s[0] == 'E' {
		s = s[1:]
		numeric = numeric && checkInt(s)
	}

	return numeric && len(s) == 0
}
