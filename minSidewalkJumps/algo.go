package minsidewalkjumps

// There is a 3 lane road of length n that consists of n + 1 points labeled from 0 to n. A frog starts at point 0 in the second lane and wants to jump to point n. However, there could be obstacles along the way.

// You are given an array obstacles of length n + 1 where each obstacles[i] (ranging from 0 to 3) describes an obstacle on the lane obstacles[i] at point i. If obstacles[i] == 0, there are no obstacles at point i. There will be at most one obstacle in the 3 lanes at each point.

//     For example, if obstacles[2] == 1, then there is an obstacle on lane 1 at point 2.

// The frog can only travel from point i to point i + 1 on the same lane if there is not an obstacle on the lane at point i + 1. To avoid obstacles, the frog can also perform a side jump to jump to another lane (even if they are not adjacent) at the same point if there is no obstacle on the new lane.

//     For example, the frog can jump from lane 3 at point 3 to lane 1 at point 3.

// Return the minimum number of side jumps the frog needs to reach any lane at point n starting from lane 2 at point 0.

// Note: There will be no obstacles on points 0 and n.

// Example 1:

// Input: obstacles = [0,1,2,3,0]
// Output: 2
// Explanation: The optimal solution is shown by the arrows above. There are 2 side jumps (red arrows).
// Note that the frog can jump over obstacles only when making side jumps (as shown at point 2).

// Example 2:

// Input: obstacles = [0,1,1,3,3,0]
// Output: 0
// Explanation: There are no obstacles on lane 2. No side jumps are required.

// Example 3:

// Input: obstacles = [0,2,1,0,3,0]
// Output: 2
// Explanation: The optimal solution is shown by the arrows above. There are 2 side jumps.

// Constraints:

//     obstacles.length == n + 1
//     1 <= n <= 5 * 105
//     0 <= obstacles[i] <= 3
//     obstacles[0] == obstacles[n] == 0

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// 使用动态规划，知道上三个格子的状态就能算出当前三个格子的最少跳跃次数
func minSideJumps(obs []int) int {
	dp := []int{1, 0, 1}
	i := 1
	for i < len(obs) {
		if obs[i] == obs[i-1] {
			i++
			continue
		}
		// 此处为难点，要根据上三个格子的障碍物情况和这三个格子有没有障碍物分开计算
		if obs[i] != 0 && obs[i-1] != 0 {
			// 上一列和这一列都有阻挡的情况
			dp[obs[i]-1] = 500001
			for j := range dp {
				if j == obs[i-1]-1 {
					dp[j] = min(min(dp[0], dp[1]), dp[2]) + 1
				}
			}
		} else {
			// 其余的情况可以合并
			minVal := min(min(dp[0], dp[1]), dp[2])
			for j := range dp {
				if dp[j] != minVal {
					dp[j] = minVal + 1
				}
			}
			if obs[i] != 0 {
				dp[obs[i]-1] = 500001
			}
		}
		i++
	}
	return min(min(dp[0], dp[1]), dp[2])
}
