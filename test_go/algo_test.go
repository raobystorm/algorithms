package testgo

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func TestSolution(t *testing.T) {
	assert := assert.New(t)
	// joint := &ListNode{
	// 	8,
	// 	&ListNode{
	// 		4,
	// 		&ListNode{
	// 			5,
	// 			nil,
	// 		},
	// 	},
	// }
	A := &ListNode{
		2,
		&ListNode{
			6,
			&ListNode{
				4,
				nil,
			},
		},
	}
	B := &ListNode{
		1,
		&ListNode{
			5,
			nil,
		},
	}

	assert.Equal(nil, getIntersectionNode(A, B))
}
