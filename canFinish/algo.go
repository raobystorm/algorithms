package canfinish

// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

// For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.

// Return true if you can finish all courses. Otherwise, return false.

// Example 1:

// Input: numCourses = 2, prerequisites = [[1,0]]
// Output: true
// Explanation: There are a total of 2 courses to take.
// To take course 1 you should have finished course 0. So it is possible.

// Example 2:

// Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
// Output: false
// Explanation: There are a total of 2 courses to take.
// To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

// Constraints:

//     1 <= numCourses <= 105
//     0 <= prerequisites.length <= 5000
//     prerequisites[i].length == 2
//     0 <= ai, bi < numCourses
//     All the pairs prerequisites[i] are unique.

// Use Kahn's algorithm for topological sorting to detect cycles in DAG
func canFinish(numCourses int, pres [][]int) bool {
	graph := make([][]int, numCourses)
	inDeg := make([]int, numCourses)
	// Build graph
	for i := range pres {
		graph[pres[i][1]] = append(graph[pres[i][1]], pres[i][0])
		inDeg[pres[i][0]]++
	}
	// Use an array to store current 0 in degree nodes
	// These nodes are clear and could be seen as start points
	q := []int{}
	for i := range inDeg {
		if inDeg[i] == 0 {
			q = append(q, i)
		}
	}
	cnt, idx := 0, 0
	for len(q) > 0 {
		idx, q = q[len(q)-1], q[:len(q)-1]
		cnt++
		// Find all adjecents for current node, decrease their in degree by 1
		// If their in degree becomes 0 then add to the array
		for i := range graph[idx] {
			inDeg[graph[idx][i]]--
			if inDeg[graph[idx][i]] == 0 {
				q = append(q, graph[idx][i])
			}
		}
	}
	// If all nodes are only stored in queue exactly once, then there is no cycle
	return numCourses == cnt
}
