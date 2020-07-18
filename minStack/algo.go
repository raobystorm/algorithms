package minstack

type MinStack struct {
	stk [20000]int
	min [20000]int
	idx int
}

/** initialize your data structure here. */
func Constructor() MinStack {
	return MinStack{
		stk: [20000]int{},
		min: [20000]int{},
		idx: -1,
	}
}

func (s *MinStack) Push(x int) {
	s.idx++
	s.stk[s.idx] = x
	if s.idx != 0 && s.min[s.idx-1] < x {
		s.min[s.idx] = s.min[s.idx-1]
	} else {
		s.min[s.idx] = x
	}
}

func (s *MinStack) Pop() {
	s.idx--
}

func (s *MinStack) Top() int {
	return s.stk[s.idx]
}

func (s *MinStack) Min() int {
	return s.min[s.idx]
}
