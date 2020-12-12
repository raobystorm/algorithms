package nthuglynumber

func min(i int, j int) int {
    if i < j {
        return i
    }
    return j
}

// 题解的思路是三指针
// 任何一个丑数都是之前的丑数乘以2/3/5得出的
// 于是下一个丑数，是从以下三个新丑数中选出最小的一个数：
// 第一个数是以前的某一个丑数 x2 得到的新丑数，第二个是 x3 得到的，第三个是 x5 得到的
// 分别用三个指针来代表 x2, x3, x5 得到的丑数的原丑数下标
// 当得到一个新丑数之后，把对应的下标前进一位再进行循环就好ß
func nthUglyNumber(n int) int {
    u := make([]int, 1690)
    u[0] = 1
    i, j, k := 0, 0, 0
    for idx := 1; idx < n; idx++ {
        tmp := min(u[i]*2, min(u[j]*3, u[k]*5))
        if tmp == u[i]*2 {
            i++
        }
        if tmp == u[j]*3 {
            j++
        }
        if tmp == u[k]*5 {
            k++
        }
        u[idx] = tmp
    }
    return u[n-1]
}