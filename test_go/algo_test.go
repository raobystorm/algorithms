package testgo

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func Test(t *testing.T) {
	assert := assert.New(t)
	stk := NewImmutableStack(1)
	stk = stk.Push(2)
	a := stk.Push(3)
	assert.Equal(stk.PrintAll(), []int{2, 1})
	b := a.Push(4)
	assert.Equal(b.PrintAll(), []int{4, 3, 2, 1})
	c := a.Push(5)
	assert.Equal(c.PrintAll(), []int{5, 3, 2, 1})
	d := b.Push(6)
	assert.Equal(d.PrintAll(), []int{6, 4, 3, 2, 1})
	e := stk.Pop()
	assert.Equal(e.PrintAll(), []int{1})
	assert.Equal(stk.PrintAll(), []int{2, 1})
	assert.Equal(b.PrintAll(), []int{4, 3, 2, 1})
	assert.Equal(c.PrintAll(), []int{5, 3, 2, 1})
	assert.Equal(d.PrintAll(), []int{6, 4, 3, 2, 1})
	f := c.Push(7)
	assert.Equal(f.PrintAll(), []int{7, 5, 3, 2, 1})
}
