package countdigitone

import (
    "math"
    "strconv"
)

func countDigitOne(n int) int {
    // For convinience change to string
    s := strconv.Itoa(n)
    res := 0
    for i := range s {
        // Current digit
        dig := len(s) - i
        // C(i) defines as: For a i digits' number, if all digits are 9, how many 1s are there.
        // E.g. For 1 digit, c = 1 because only one 1 in [0~9]
        // For 2 digit, c = 20 because there are 20 1s in [0~99]
        // Formula for c(i) at ith digit is c(i) = 10^(i-1) * i 
        c := int(math.Pow(10, float64(dig-2))) * (dig-1)
        if i < len(s)-1 {
            if s[i] > '1' {
                // if current digit is larger than 1, we should consider:
                // 1, For every number in 1[0~9]*, there is a 1 at first digit.
                //    So there are 10^(dig-1) 1s in total of this part.
                // 2, For 1s in right part of [0~s[i]-1][0~9]*, because s[i] > 1,
                //    there should be s[i] * C(dig-1) of 1s here. E.g. if s is '234',
                //    when i = 0, s[i] = 2, we should add 1s in right part of 0[00~99], 1[00~99] into result value. Which both are C(2). This part is s[i] * C(i-1)
                // 3, For 1s in s[i][0~9]*, the value will calculated in next iteration.
                //    E.g. 1s in right part "34" of 234, we just calculate 1s in "34", simply i++ and do nothing in loop
                res += int(math.Pow(10, float64(dig-1))) + int(s[i] - '0') * c
            } else if s[i] == '1' {
                // if current digit is equal to 1, E.g. if s is '134' and i = 0
                // From 100~134 we have 35 of 1s in first digit.
                // Then the 2nd part is the same of above as s[i] * C(i-1)
				n, _ := strconv.Atoi(s[i+1:])
                res += n + 1 + int(s[i] - '0') * c
			}
            // if current digit is 0, simply no contribute to result.
        } else {
            // For last digit of string, if larger than 1 then plus result by 1.
			if s[len(s)-1] >= '1' {
				res++
			}
		}
    }
    return res
}