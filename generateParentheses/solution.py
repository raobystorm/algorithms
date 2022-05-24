# Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses

# Example 1:
# Input: n = 3
# Output: ["((()))","(()())","(())()","()(())","()()()"]

# Example 2:
# Input: n = 1
# Output: ["()"]

# Constraints:
#     1 <= n <= 8
from typing import List


class Solution:
    def gen_paren(self, prefix: str):
        if self.parens["("] == 0 and self.parens[")"] == 0:
            self.res.append(prefix)
            return

        if self.parens["("] > 0:
            self.parens["("] -= 1
            self.gen_paren(prefix + "(")
            self.parens["("] += 1

        if self.parens[")"] > self.parens["("]:
            self.parens[")"] -= 1
            self.gen_paren(prefix + ")")
            self.parens[")"] += 1

    def generateParenthesis(self, n: int) -> List[str]:
        self.parens = {"(": n, ")": n}
        self.res: List[str] = []
        self.gen_paren("")
        return self.res
