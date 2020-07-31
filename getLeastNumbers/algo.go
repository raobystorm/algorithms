package getleastnumbers

type Heap struct {
	arr []int
}

func parent(i int) int { return (i - 1) / 2 }
func right(i int) int  { return (i + 1) * 2 }
func left(i int) int   { return i*2 + 1 }

func (h *Heap) Up(i int) {
	for i > 0 && h.arr[i] > h.arr[parent(i)] {
		h.arr[parent(i)], h.arr[i] = h.arr[i], h.arr[parent(i)]
		i = parent(i)
	}
}

// The same as heapify
func (h *Heap) Down(i int) {
	for left(i) < len(h.arr) || right(i) < len(h.arr) {
		idx := -1
		if right(i) < len(h.arr) && h.arr[right(i)] > h.arr[left(i)] {
			idx = right(i)
		} else {
			idx = left(i)
		}
		if h.arr[idx] > h.arr[i] {
			h.arr[idx], h.arr[i] = h.arr[i], h.arr[idx]
			i = idx
		} else {
			break
		}
	}
}

func (h *Heap) Insert(i int, k int) {
	if len(h.arr) == k && i > h.arr[0] {
		return
	}
	if len(h.arr) < k {
		h.arr = append(h.arr, i)
		h.Up(len(h.arr) - 1)
	} else {
		h.arr[0] = i
		h.Down(0)
	}
}

func (h *Heap) GetArr() []int {
	return h.arr
}

func GetLeastNumbers(arr []int, k int) []int {
	if k == 0 {
		return []int{}
	}
	h := Heap{
		arr: []int{},
	}
	for i := 0; i < len(arr); i++ {
		h.Insert(arr[i], k)
	}
	return h.GetArr()
}
