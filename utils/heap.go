package utils

// Here is an example of MIN heap, with max capacity
type Heap struct {
	max_len int
	arr     []int
}

func parent(i int) int { return (i - 1) / 2 }
func right(i int) int  { return (i + 1) * 2 }
func left(i int) int   { return i*2 + 1 }

func (h *Heap) Up(i int) {
	for i > 0 && h.arr[parent(i)] > h.arr[i] {
		h.arr[parent(i)], h.arr[i] = h.arr[i], h.arr[parent(i)]
		i = parent(i)
	}
}

// The same as heapify
func (h *Heap) Down(i int) {
	for left(i) < len(h.arr) || right(i) < len(h.arr) {
		idx := -1
		if right(i) < len(h.arr) && h.arr[right(i)] < h.arr[left(i)] {
			idx = right(i)
		} else {
			idx = left(i)
		}
		if h.arr[idx] < h.arr[i] {
			h.arr[idx], h.arr[i] = h.arr[i], h.arr[idx]
			i = idx
		} else {
			break
		}
	}
}

func (h *Heap) Insert(n int) {
	if len(h.arr) == h.max_len-1 && n < h.arr[0] {
		return
	}
	if len(h.arr) < h.max_len {
		h.arr = append(h.arr, n)
		h.Up(len(h.arr) - 1)
	} else if n > h.arr[0] {
		h.arr[0] = n
		h.Down(0)
	}
}

func (h *Heap) Top() int {
	return h.arr[0]
}

func NewHeap(arr []int, max_len int) *Heap {
	h := Heap{
		arr:     arr[:max_len],
		max_len: max_len,
	}
	for i := parent(len(h.arr) - 1); i >= 0; i-- {
		h.Down(i)
	}
	for i := len(h.arr); i < len(arr); i++ {
		h.Insert(arr[i])
	}
	return &h
}
