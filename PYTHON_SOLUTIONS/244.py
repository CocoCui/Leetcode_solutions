class WordDistance(object):
    dic = {}
    
    def findMin(self, l1, l2):
        res =  2 << 30
        for i1 in l1:
            for i2 in l2:
                res = min(abs(i1 - i2), res)
        return res
        
    def __init__(self, words):
        """
        :type words: List[str]
        """
        self.dic = {}
        for idx, w in enumerate(words):
            if w in self.dic:
                self.dic[w].append(idx)
            else:
                self.dic[w] = [idx]

    def shortest(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: int
        """
        return self.findMin(self.dic[word1], self.dic[word2])
        


# Your WordDistance object will be instantiated and called as such:
# obj = WordDistance(words)
# param_1 = obj.shortest(word1,word2)
