package nestedstring

import "testing"

func TestNested(test *testing.T) {
	S := "()()"
	if nestedString(S) != 1 {
		panic("")
	}
}
