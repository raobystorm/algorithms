package isaliensorted

// In an alien language, surprisingly, they also use English lowercase letters, but possibly in a different order. The order of the alphabet is some permutation of lowercase letters.

// Given a sequence of words written in the alien language, and the order of the alphabet, return true if and only if the given words are sorted lexicographically in this alien language.

// Example 1:

// Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
// Output: true
// Explanation: As 'h' comes before 'l' in this language, then the sequence is sorted.

// Example 2:

// Input: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
// Output: false
// Explanation: As 'd' comes after 'l' in this language, then words[0] > words[1], hence the sequence is unsorted.

// Example 3:

// Input: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
// Output: false
// Explanation: The first three characters "app" match, and the second string is shorter (in size.) According to lexicographical rules "apple" > "app", because 'l' > '∅', where '∅' is defined as the blank character which is less than any other character (More info).

// Constraints:

//     1 <= words.length <= 100
//     1 <= words[i].length <= 20
//     order.length == 26
//     All characters in words[i] and order are English lowercase letters.

func compare(dict map[byte]int, s1, s2 string) int {
	k := 0
	for k < len(s1) && k < len(s2) {
		if dict[s1[k]] < dict[s2[k]] {
			return -1
		}
		if dict[s1[k]] > dict[s2[k]] {
			return 1
		}
		k++
	}
	if len(s1) > k {
		return 1
	}
	if len(s2) > k {
		return -1
	}
	return 0
}

func isAlienSorted(words []string, order string) bool {
	dict := map[byte]int{}
	for i := range order {
		dict[order[i]] = i
	}
	i := 0
	for i < len(words)-1 {
		if compare(dict, words[i], words[i+1]) > 0 {
			return false
		}
		i++
	}
	return true
}
