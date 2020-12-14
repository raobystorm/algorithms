package decodestring

import (
	"strconv"
	"strings"
)

func decodeString(s string) string {
    var sb strings.Builder
    i := 0
    for i < len(s) {
        if s[i] >= 'a' && s[i] <= 'z' {
            sb.WriteString(string(s[i]))
        } else if s[i] >= '0' && s[i] <= '9' {
            j := i+1
            for s[j] >= '0' && s[j] <= '9' {
                j++
            }
            rep, _ := strconv.Atoi(s[i:j])
            c := s[j]
            if c == '[' {
				k := j
				t := 1
                for t > 0 {
					if s[k+1] == ']' {
						t--
					} else if s[k+1] == '[' {
						t++
					}
                    k++
                }
                subs := decodeString(s[j+1:k])
                for r := 0; r < rep; r++ {
                    sb.WriteString(subs)
				}
				i = k
            } else {
                for r := 0; r < rep; r++ {
                    sb.WriteString(string(c))
				}
				i = j
            }
        }
        i++
    }
    return sb.String()
}