package lrucache

import "testing"

func TestSolution(t *testing.T) {
	c := Constructor(2)
	c.Put(2, 1)
	c.Put(3, 2)
	c.Get(3)
	c.Get(2)
	c.Put(4, 3)
	c.Get(2)
	c.Get(3)
	c.Get(4)
}
