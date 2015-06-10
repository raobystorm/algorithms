

class Solution:
    # @param {integer[]} nums
    # @param {integer} val
    # @return {integer}
   def removeElement(self, A, elem):
        ex = []
        for i in A:
            if i != elem:
                ex.append(i)
        A = ex
        return len(ex)