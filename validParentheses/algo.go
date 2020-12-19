package validparentheses

func isValid(s string) bool {
    stk := []byte{}
    for i := range s {
        switch s[i] {
            case '(', '[', '{':
                stk = append(stk, s[i])
            case ')':
            if len(stk) == 0 || stk[len(stk)-1] != '(' {
                    return false
                }
                stk = stk[:len(stk)-1]
            case ']':
                if len(stk) == 0 || stk[len(stk)-1] != '[' {
                    return false
                }
                stk = stk[:len(stk)-1]
            case '}':
                if len(stk) == 0 || stk[len(stk)-1] != '{' {
                    return false
                }
                stk = stk[:len(stk)-1]
        }
    }
    return len(stk) == 0
}