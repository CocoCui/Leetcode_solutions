class Solution(object):
    def shortestDistance(self, words, word1, word2):
        """
        :type words: List[str]
        :type word1: str
        :type word2: str
        :rtype: int
        """
        res = len(words)
        w1 = -res
        w2 = -res
        for idx, w in enumerate(words):
            if w == word1:
                res = min(idx - w2, res)
                w1 = idx
            if w == word2:
                res = min(idx - w1, res)
                w2 = idx
        return res
