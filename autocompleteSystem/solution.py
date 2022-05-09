from functools import cmp_to_key
from typing import List

# Design a search autocomplete system for a search engine. Users may input a sentence (at least one word and end with a special character '#').

# You are given a string array sentences and an integer array times both of length n where sentences[i] is a previously typed sentence and times[i] is the corresponding number of times the sentence was typed. For each input character except '#', return the top 3 historical hot sentences that have the same prefix as the part of the sentence already typed.

# Here are the specific rules:

#     The hot degree for a sentence is defined as the number of times a user typed the exactly same sentence before.
#     The returned top 3 hot sentences should be sorted by hot degree (The first is the hottest one). If several sentences have the same hot degree, use ASCII-code order (smaller one appears first).
#     If less than 3 hot sentences exist, return as many as you can.
#     When the input is a special character, it means the sentence ends, and in this case, you need to return an empty list.

# Implement the AutocompleteSystem class:

#     AutocompleteSystem(String[] sentences, int[] times) Initializes the object with the sentences and times arrays.
#     List<String> input(char c) This indicates that the user typed the character c.
#         Returns an empty array [] if c == '#' and stores the inputted sentence in the system.
#         Returns the top 3 historical hot sentences that have the same prefix as the part of the sentence already typed. If there are fewer than 3 matches, return them all.

# Example 1:

# Input
# ["AutocompleteSystem", "input", "input", "input", "input"]
# [[["i love you", "island", "iroman", "i love leetcode"], [5, 3, 2, 2]], ["i"], [" "], ["a"], ["#"]]
# Output
# [null, ["i love you", "island", "i love leetcode"], ["i love you", "i love leetcode"], [], []]

# Explanation
# AutocompleteSystem obj = new AutocompleteSystem(["i love you", "island", "iroman", "i love leetcode"], [5, 3, 2, 2]);
# obj.input("i"); // return ["i love you", "island", "i love leetcode"]. There are four sentences that have prefix "i". Among them, "ironman" and "i love leetcode" have same hot degree. Since ' ' has ASCII code 32 and 'r' has ASCII code 114, "i love leetcode" should be in front of "ironman". Also we only need to output top 3 hot sentences, so "ironman" will be ignored.
# obj.input(" "); // return ["i love you", "i love leetcode"]. There are only two sentences that have prefix "i ".
# obj.input("a"); // return []. There are no sentences that have prefix "i a".
# obj.input("#"); // return []. The user finished the input, the sentence "i a" should be saved as a historical sentence in system. And the following input will be counted as a new search.


# Constraints:

#     n == sentences.length
#     n == times.length
#     1 <= n <= 100
#     1 <= sentences[i].length <= 100
#     1 <= times[i] <= 50
#     c is a lowercase English letter, a hash '#', or space ' '.
#     Each tested sentence will be a sequence of characters c that end with the character '#'.
#     Each tested sentence will have a length in the range [1, 200].
#     The words in each input sentence are separated by single spaces.
#     At most 5000 calls will be made to input.


def cmp(x, y):
    if x[1] != y[1]:
        return x[1] - y[1]
    if x[0] < y[0]:
        return 1
    return -1


class TrieNode:
    def __init__(self):
        self.next = {chr(i): None for i in range(97, 123)}
        self.next[" "] = None
        self.most = []

    def update_most(self, word: str, times: int):
        if word not in list(map(lambda x: x[0], self.most)):
            self.most.append((word, times))
        else:
            new_most = []
            for w, t in self.most:
                if w != word:
                    new_most.append((w, t))
                else:
                    new_most.append((w, times))
            self.most = new_most
        self.most = list(sorted(self.most, key=cmp_to_key(cmp), reverse=True))
        self.most = self.most[:3]


class AutocompleteSystem:
    def insert(self, word: str, times: int):
        loc = self.root
        original_word = word
        while len(word) > 0:
            c = word[0]
            if loc.next[c] == None:
                loc.next[c] = TrieNode()
            loc.next[c].update_most(original_word, times)
            loc = loc.next[c]
            word = word[1:]

    def __init__(self, sentences: List[str], times: List[int]):
        self.root = TrieNode()
        self.loc = self.root
        self.times = {}
        self.curr_input = ""
        for i, s in enumerate(sentences):
            self.times[s] = times[i]
            self.insert(s, times[i])

    def input(self, c: str) -> List[str]:
        if c != "#":
            self.curr_input += c
            if self.loc.next[c] == None:
                self.loc.next[c] = TrieNode()
            self.loc = self.loc.next[c]
        else:
            if self.curr_input in self.times.keys():
                self.times[self.curr_input] += 1
            else:
                self.times[self.curr_input] = 1
            self.insert(self.curr_input, self.times[self.curr_input])
            self.curr_input = ""
            self.loc = self.root

        if self.loc != None:
            return list(map(lambda x: x[0], self.loc.most))
        return []
