package ladderlength

import (
	"container/heap"
)

type node struct {
    word string
	dis int
	neibrs []*node
}

type Heap []*node

func (h Heap) Len() int           { return len(h) }
func (h Heap) Less(i, j int) bool { return h[i].dis < h[j].dis }
func (h Heap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *Heap) Push(x interface{}) {
	// Push and Pop use pointer receivers because they modify the slice's length,
	// not just its contents.
	*h = append(*h, x.(*node))
}

func (h *Heap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

func isAdjacent(w1 string, w2 string) bool {
    if len(w1) != len(w2) {
        return false
    }
    
    diff := 0
    for i := range w1 {
        if w1[i] != w2[i] {
            diff++
        }
        if diff > 1 {
            return false
        }
    }
    return diff == 1
}

func ladderLength(bw string, ew string, wlist []string) int {
	wlist = append(wlist, bw)
	nodes := make([]*node, len(wlist))
	var res *node
	h := &Heap{}
    for i := range wlist {
		if i != len(wlist)-1 {
			nodes[i] = &node{wlist[i], 999999999, []*node{}}
		} else {
			nodes[i] = &node{wlist[i], 0, []*node{}}	
		}
		if wlist[i] == ew {
			res = nodes[i]
		}
		heap.Push(h, nodes[i])
	}

	if res == nil {
		return 0
	}

	for i := range nodes {
		for j := i+1; j < len(nodes); j++ {
			if isAdjacent(nodes[i].word, nodes[j].word) {
				nodes[i].neibrs = append(nodes[i].neibrs, nodes[j])
				nodes[j].neibrs = append(nodes[j].neibrs, nodes[i])	
			}
		}
	}

	
	var curr *node
	var alt int
    for h.Len() > 0 {
		curr = heap.Pop(h).(*node)
        for i := range curr.neibrs {
            alt = curr.dis + 1
            if alt < curr.neibrs[i].dis {
				curr.neibrs[i].dis = alt
				for j := range *h {
					if (*h)[j].word == curr.neibrs[i].word {
						heap.Fix(h, j)
						break
					}
				}
            }
        }
	}

	if res.dis >= 999999999 {
		return 0
	}
	return res.dis+1
}

/*

build adjacent matrix M

    
*/