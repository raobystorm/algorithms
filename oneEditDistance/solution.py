# Given two strings s and t, return true if they are both one edit distance apart, otherwise return false.

# A string s is said to be one distance apart from a string t if you can:

#     Insert exactly one character into s to get t.
#     Delete exactly one character from s to get t.
#     Replace exactly one character of s with a different character to get t.

# Example 1:

# Input: s = "ab", t = "acb"
# Output: true
# Explanation: We can insert 'c' into s to get t.

# Example 2:

# Input: s = "", t = ""
# Output: false
# Explanation: We cannot get t from s by only one step.

# Constraints:

#     0 <= s.length, t.length <= 104
#     s and t consist of lowercase letters, uppercase letters, and digits.


class Solution:
    def isOneEditDistance(self, a: str, b: str) -> bool:
        if a == b or abs(len(a) - len(b)) > 1:
            return False

        if len(a) < len(b):
            short, long = a, b
        else:
            short, long = b, a
        i, j = 0, 0
        edited = False
        while i < len(short) and j < len(long):
            if short[i] != long[j] and edited:
                return False

            if short[i] != long[j]:
                edited = True

            if short[i] == long[j] or len(short) == len(long):
                i += 1
            j += 1

        return True