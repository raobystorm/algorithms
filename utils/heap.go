package utils

// Here is an example of MIN heap, with max capacity
type Heap struct {
	less func(int, int) bool
	arr  []int
}

func parent(i int) int { return (i - 1) / 2 }
func right(i int) int  { return (i + 1) * 2 }
func left(i int) int   { return i*2 + 1 }

func (h *Heap) Up(i int) {
	for i > 0 && h.less(h.arr[i], h.arr[parent(i)]) {
		h.arr[parent(i)], h.arr[i] = h.arr[i], h.arr[parent(i)]
		i = parent(i)
	}
}

// The same as heapify
func (h *Heap) Down(i int) {
	for left(i) < len(h.arr) || right(i) < len(h.arr) {
		idx := -1
		if right(i) < len(h.arr) && h.less(h.arr[right(i)], h.arr[left(i)]) {
			idx = right(i)
		} else {
			idx = left(i)
		}
		if h.less(h.arr[idx], h.arr[i]) {
			h.arr[idx], h.arr[i] = h.arr[i], h.arr[idx]
			i = idx
		} else {
			break
		}
	}
}

func (h *Heap) Top() int {
	return h.arr[0]
}
