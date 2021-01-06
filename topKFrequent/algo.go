package topkfrequent

import (
	"container/heap"
)

type Pair struct {
    n int
    cnt int
}

// Use a heap of pair ints to calc frequent nums
type Heap []Pair

func (h Heap) Len() int           { return len(h) }
func (h Heap) Less(i, j int) bool { return h[i].cnt < h[j].cnt }
func (h Heap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *Heap) Push(x interface{}) {
	*h = append(*h, x.(Pair))
}

func (h *Heap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

func (h Heap) Top() Pair {
    return h[0]
}

func topKFrequent(nums []int, k int) []int {
    m := make(map[int]int)
    // Count frequency
    for i := range nums {
        if _, ok := m[nums[i]]; !ok {
            m[nums[i]] = 1
            continue
        }
        m[nums[i]]++
    }

    // Use min heap to keep k frequent elems
    h := Heap{}
    heap.Init(&h)
    for kk, v := range m {
        p := Pair{n: kk, cnt: v}
        if h.Len() < k {
            heap.Push(&h, p)
        } else if v > h.Top().cnt {
            heap.Push(&h, p)
            heap.Pop(&h)
        }
    }

    // Format to output
    res := make([]int, h.Len())
    for i := range h {
        res[i] = h[i].n
    }
    return res
}