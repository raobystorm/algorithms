class Solution:

    def checkEqual(self, c1, c2):
        if c1.capitalize() == c2.capitalize(): return True
        return False

    # @param {string} s
    # @return {boolean}
    def isPalindrome(self, s):
        if len(s) is 0:
            return True

        j = len(s) - 1
        i = 0
        while i <= j:
            while i < len(s) and not s[i].isalnum(): i = i + 1
            while j >= 0 and not s[j].isalnum(): j = j - 1
            if i < len(s) and j >= 0 and not s[i].capitalize() == s[j].capitalize(): return False
            i = i + 1;
            j = j - 1;
        return True

Solution().isPalindrome('ab')