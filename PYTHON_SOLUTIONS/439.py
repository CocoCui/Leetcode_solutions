class Solution(object):
    def parseTernary(self, expression):
        """
        :type expression: str
        :rtype: str
        """
        def dfs(exp, idx):
            #print("exp", exp)
            if idx < len(exp) - 1 and exp[idx + 1] != "?":
                    return idx + 2, exp[idx]
            elif len(exp) == 1 + idx:
                return idx,exp[idx]
            
            c = exp[idx]
            #print("all:", exp[2:])
            idxl,l = dfs(exp, idx + 2)
            #print("l:", exp, l)
            idxr,r = dfs(exp, idxl)
            #print("r:", exp, r)
            if c == 'T':
                return idxr, l
            else:
                return idxr, r
        
        v, i = dfs(expression, 0)
        return i
