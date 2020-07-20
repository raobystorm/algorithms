package validatestacksequences

// https://leetcode-cn.com/problems/zhan-de-ya-ru-dan-chu-xu-lie-lcof/
func validateStackSequences(push []int, pop []int) bool {
	idx := 0
	// when pop is not empty continue check
	for len(pop) > 0 {
		// if next to pop is not at stack top
		if pop[0] != push[idx] {
			// if there is element could be pushed, then push
			if idx < len(push)-1 {
				idx++
			} else {
				// if no elem left to push, then it is not possible to pop like this
				return false
			}
		} else {
			// if next to pop elem is at top
			// then pop that out
			pop = pop[1:]
			if idx < len(push)-1 {
				push = append(push[:idx], push[idx+1:]...)
			}
			// edge case if no elem left in push stack, do nothing
			if idx > 0 {
				idx--
			}
		}
	}
	return true
}
