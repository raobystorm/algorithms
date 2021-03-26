package immutablestack

type ImmutableStack struct {
	Val  int
	Prev *ImmutableStack
}

func NewImmutableStack(val int) ImmutableStack {
	return ImmutableStack{
		val,
		nil,
	}
}

func (stk ImmutableStack) Push(val int) ImmutableStack {
	return ImmutableStack{
		val,
		&stk,
	}
}

func (stk ImmutableStack) Pop() ImmutableStack {
	return *stk.Prev
}

func (stk ImmutableStack) Top() int {
	return stk.Val
}

func (stk *ImmutableStack) PrintAll() []int {
	res := []int{}
	for stk != nil {
		res = append(res, (*stk).Val)
		stk = stk.Prev
	}
	return res
}
