package twosum

func twoSum(n []int, t int) []int {
    first, second := 0, len(n)-1
    sum := 0
    for first < second {
        sum = n[first] + n[second]
        if t == sum {
            return []int{n[first], n[second]}
        } else if sum > t {
            second--
        } else {
            first++
        }
    }
    return []int{}
}