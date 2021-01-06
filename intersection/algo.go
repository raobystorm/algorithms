package intersection

type void struct{}

func intersection(nums1 []int, nums2 []int) []int {
    m := make(map[int]void)
    res := make(map[int]void)
    for i := range nums1 {
        m[nums1[i]] = void{}
    }
    for i := range nums2 {
        if _, ok := m[nums2[i]]; ok {
            res[nums2[i]] = void{}
        }
    }
    resSlice := []int{}
    for k := range res {
        resSlice = append(resSlice, k)
    }
    return resSlice
}