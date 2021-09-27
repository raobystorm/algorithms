package maxcompatibilityscore

// There is a survey that consists of n questions where each question's answer is either 0 (no) or 1 (yes).

// The survey was given to m students numbered from 0 to m - 1 and m mentors numbered from 0 to m - 1. The answers of the students are represented by a 2D integer array students where students[i] is an integer array that contains the answers of the ith student (0-indexed). The answers of the mentors are represented by a 2D integer array mentors where mentors[j] is an integer array that contains the answers of the jth mentor (0-indexed).

// Each student will be assigned to one mentor, and each mentor will have one student assigned to them. The compatibility score of a student-mentor pair is the number of answers that are the same for both the student and the mentor.

// For example, if the student's answers were [1, 0, 1] and the mentor's answers were [0, 0, 1], then their compatibility score is 2 because only the second and the third answers are the same.

// You are tasked with finding the optimal student-mentor pairings to maximize the sum of the compatibility scores.

// Given students and mentors, return the maximum compatibility score sum that can be achieved.

// Example 1:

// Input: students = [[1,1,0],[1,0,1],[0,0,1]], mentors = [[1,0,0],[0,0,1],[1,1,0]]
// Output: 8
// Explanation: We assign students to mentors in the following way:
// - student 0 to mentor 2 with a compatibility score of 3.
// - student 1 to mentor 0 with a compatibility score of 2.
// - student 2 to mentor 1 with a compatibility score of 3.
// The compatibility score sum is 3 + 2 + 3 = 8.

// Example 2:

// Input: students = [[0,0],[0,0],[0,0]], mentors = [[1,1],[1,1],[1,1]]
// Output: 0
// Explanation: The compatibility score of any student-mentor pair is 0.

// Constraints:

//     m == students.length == mentors.length
//     n == students[i].length == mentors[j].length
//     1 <= m, n <= 8
//     students[i][k] is either 0 or 1.
//     mentors[j][k] is either 0 or 1.

func calc(s, m []int) int {
	res := 0
	for i := range s {
		if s[i] == m[i] {
			res++
		}
	}
	return res
}

// 使用排列组合找出最优组合，以递归的方式查找
// dist: 距离矩阵，dist[i][j]代表第i学生和第j教授的分数
// mIdx: 当前查找的教授的编号。mIdx之前的教授已经分配了对应的学生
// score: 当前状态的分数
// sMask: 一个bool的数组，记录已经被分配的学生的index
func permute(dists [][]int, mIdx int, score int, sMask []bool) int {
	if mIdx >= len(dists[0]) {
		return score
	}
	res := score
	// 遍历所有还未分配的学生，找到最大分数的组合
	for i := range dists {
		if sMask[i] {
			continue
		}
		// 假设将学生i分配给当前教授，并用本函数递归查找剩下的组合
		sMask[i] = true
		currMax := permute(dists, mIdx+1, score+dists[i][mIdx], sMask)
		// 尝试完成后去除当前分配，循环下一个学生
		sMask[i] = false
		if currMax > res {
			res = currMax
		}
	}
	return res
}

func maxCompatibilitySum(ss [][]int, ms [][]int) int {
	dists := make([][]int, len(ss))
	for i := range ss {
		dists[i] = make([]int, len(ms))
		for j := range ms {
			dists[i][j] = calc(ss[i], ms[j])
		}
	}

	sMask := make([]bool, len(ss))
	res := permute(dists, 0, 0, sMask)
	return res
}
