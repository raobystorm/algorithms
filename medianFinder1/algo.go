package medianfinder1

import "container/heap"

type MedianFinder struct {
	max *MaxHeap
	min *MinHeap
}

type MinHeap []int

func (h MinHeap) Len() int           { return len(h) }
func (h MinHeap) Less(i, j int) bool { return h[i] < h[j] }
func (h MinHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *MinHeap) Push(x interface{}) {
	*h = append(*h, x.(int))
}

func (h *MinHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

type MaxHeap []int

func (h MaxHeap) Len() int           { return len(h) }
func (h MaxHeap) Less(i, j int) bool { return h[i] > h[j] }
func (h MaxHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *MaxHeap) Push(x interface{}) {
	*h = append(*h, x.(int))
}

func (h *MaxHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

/** initialize your data structure here. */
func Constructor() MedianFinder {
	max := &MaxHeap{}
	min := &MinHeap{}
	heap.Init(max)
	heap.Init(min)
	return MedianFinder{
		max: max,
		min: min,
	}
}

func (m *MedianFinder) AddNum(num int) {
	if (m.min.Len()+m.max.Len())%2 == 0 {
		heap.Push(m.max, num)
		heap.Push(m.min, heap.Pop(m.max))
	} else {
		heap.Push(m.min, num)
		heap.Push(m.max, heap.Pop(m.min))
	}
}

func (m *MedianFinder) FindMedian() float64 {
	if (m.min.Len()+m.max.Len())%2 == 1 {
		med := heap.Pop(m.min).(int)
		heap.Push(m.min, med)
		return float64(med)
	}
	med1 := heap.Pop(m.min).(int)
	med2 := heap.Pop(m.max).(int)
	heap.Push(m.min, med1)
	heap.Push(m.max, med2)
	return (float64(med1) + float64(med2)) / 2
}
