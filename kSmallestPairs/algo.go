package ksmallestpairs

import (
	"container/heap"
)

type Pair struct {
	n int
	m int
}

type PairHeap []Pair

func (h PairHeap) Len() int           { return len(h) }
func (h PairHeap) Less(i, j int) bool { return h[i].m + h[i].n > h[j].m + h[j].n }
func (h PairHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *PairHeap) Push(x interface{}) {
	*h = append(*h, x.(Pair))
}

func (h *PairHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

func (h PairHeap) Top() int {
    return h[0].m + h[0].n
}

func (h PairHeap) GetRes() [][]int{
	res := make([][]int, len(h))
	for i := range h {
		p := heap.Pop(&h).(Pair)
		res[len(res) - 1 - i] = []int{p.n, p.m}
	}
	return res
}

func kSmallestPairs(nums1 []int, nums2 []int, k int) [][]int {
	h := &PairHeap{}
	heap.Init(h) 
	for i := range nums1 {
		for j := range nums2 {
			if h.Len() < k {
				heap.Push(h, Pair{nums1[i], nums2[j]})
				continue
			}
			if h.Top() < nums1[i] + nums2[j] {
				continue
			}
			heap.Push(h, Pair{nums1[i], nums2[j]})
			heap.Pop(h)
		}
	}
	return h.GetRes()
}