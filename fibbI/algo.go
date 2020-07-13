func fib(n int) int {
    fibb := make([]int, 101)
    fibb[0], fibb[1] = 0, 1
    for i := 2; i < len(fibb); i++ {
        fibb[i] = (fibb[i-1] + fibb[i-2]) % 1000000007
    }

    return fibb[n]
}