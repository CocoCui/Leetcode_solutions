class Solution(object):
    def validWordAbbreviation(self, word, abbr):
        """
        :type word: str
        :type abbr: str
        :rtype: bool
        """
        l, r, wl = 0, 0, 0
        while l < len(abbr) and wl < len(word):
            if abbr[l].isalpha() or abbr[l] == "0":
                if abbr[l] == word[wl]:
                    l += 1
                    wl += 1
                else:
                    return False
            else:
                r = l + 1
                while r < len(abbr) and abbr[r].isdigit():
                    r += 1
                num = int(abbr[l:r]) 
                wl += num
                l = r
        return l == len(abbr) and wl == len(word)
        
