package kthlargestheap

import (
	"container/heap"
)

// An IntHeap is a min-heap of ints.
type IntHeap []int

func (h IntHeap) Len() int           { return len(h) }
func (h IntHeap) Less(i, j int) bool { return h[i] < h[j] }
func (h IntHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *IntHeap) Push(x interface{}) {
	// Push and Pop use pointer receivers because they modify the slice's length,
	// not just its contents.
	*h = append(*h, x.(int))
}

func (h *IntHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

func (h *IntHeap) Top() int {
    return (*h)[0]
}

type KthLargest struct {
    h *IntHeap
    k int
}

func Constructor(k int, nums []int) KthLargest {
    kk := KthLargest{
        h: &IntHeap{},
        k: k,
    }
    heap.Init(kk.h)
    for i := range nums {
        kk.Add(nums[i])
    }
    return kk
}


func (kk *KthLargest) Add(val int) int {
    if kk.h.Len() < kk.k {
        heap.Push(kk.h, val)
        return kk.h.Top()
    }
    if val < kk.h.Top() {
        return kk.h.Top()
    }
    heap.Push(kk.h, val)
    heap.Pop(kk.h)
    return kk.h.Top()
}