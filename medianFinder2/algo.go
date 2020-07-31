package medianfinder2

import "math/rand"

type MedianFinder struct {
	arr    []int
	medIdx int
}

/** initialize your data structure here. */
func Constructor() MedianFinder {
	return MedianFinder{
		arr:    []int{},
		medIdx: -1,
	}
}

func (m *MedianFinder) AddNum(n int) {
	if len(m.arr) == 0 {
		m.arr = append(m.arr, n)
		m.medIdx = 0
		return
	}
	if n > m.arr[m.medIdx] {
		m.arr = append(m.arr, n)
		return
	}
	m.arr = append([]int{n}, m.arr...)
}

func partition(n []int, l int, r int) int {
	pIdx := rand.Intn(r-l+1) + l
	n[l], n[pIdx] = n[pIdx], n[l]
	p := n[l]
	i := l
	for j := l + 1; j <= r; j++ {
		for i < j && n[j] <= p {
			i++
			n[i], n[j] = n[j], n[i]
		}
	}
	n[i], n[l] = n[l], n[i]
	return i
}

func findMed(arr []int) int {
	l := partition(arr, 0, len(arr)-1)
	for l != (len(arr)-1)/2 {
		if l < (len(arr)-1)/2 {
			l = partition(arr, l, len(arr)-1)
		} else {
			l = partition(arr, 0, l)
		}
	}
	return l
}

func (m *MedianFinder) FindMedian() float64 {
	if len(m.arr)%2 == 1 {
		idx := findMed(m.arr)
		return float64(m.arr[idx])
	}
	idx := findMed(m.arr)
	first := m.arr[idx]
	newArr := make([]int, len(m.arr))
	copy(newArr, m.arr)
	newArr[idx], newArr[0] = newArr[0], newArr[idx]
	newArr = newArr[1:]
	idx = findMed(newArr)
	second := newArr[idx]
	return (float64(first) + float64(second)) / 2
}
