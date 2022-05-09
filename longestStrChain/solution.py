from typing import Set, Dict, List


class Solution:
    words: Set[str] = set()
    checked: Dict[str, int] = dict()

    def dfs(self, word: str) -> int:
        if len(word) == 1:
            return 1
        if word in self.checked.keys():
            return self.checked[word]

        curr_len = 1
        for i, c in enumerate(word):
            new_word = word[:i] + word[i + 1 :]
            if new_word in self.words:
                curr_len = max(curr_len, self.dfs(new_word) + 1)

        self.checked[word] = curr_len
        return curr_len

    def longestStrChain(self, words: List[str]) -> int:
        self.words = set(words)
        words = sorted(words, key=len, reverse=True)
        max_len = 1
        for word in words:
            curr_len = self.dfs(word)
            max_len = max(max_len, curr_len)
        return max_len