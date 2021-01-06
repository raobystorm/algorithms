package groupanagrams

import (
	"strconv"
	"strings"
)

var chars = [...]byte{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x','y', 'z'}

func getFeatureStr(s string) string {
    cnts := make(map[byte]int)
    var sb strings.Builder
    for i := range s {
        _, ok := cnts[s[i]]
        if !ok {
            cnts[s[i]] = 1            
        } else {
            cnts[s[i]]++
        }
    }
    for i := range chars {
        n, ok := cnts[chars[i]]
        if !ok {
            continue
        }
        sb.WriteString(string(chars[i]))
        sb.WriteString(strconv.Itoa(n))
    }
    return sb.String()
}

func groupAnagrams(strs []string) [][]string {
    ana := make(map[string][]string)
    for i := range strs {
        feaStr := getFeatureStr(strs[i])
        if _, ok := ana[feaStr]; !ok {
            ana[feaStr] = []string{strs[i]}
        } else {
            ana[feaStr] = append(ana[feaStr], strs[i])
        }
    }
    res := make([][]string, len(ana))
    i := 0
    for _, v := range ana {
        res[i] = v
        i++
    }
    return res
}