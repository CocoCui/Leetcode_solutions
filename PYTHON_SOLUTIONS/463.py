class Solution(object):
    def count(self, w, h, x, y, grid):
        if (x < 0 or y < 0 or y >= h or x >= w):
            return 0
        else:
            return grid[y][x]

    def islandPerimeter(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        res = 0
        h = len(grid)
        if h == 0:
            return 0
        w = len(grid[0])
        for y in range(0, h):
            for x in range(0, w):
                if grid[y][x]:
                    res += 4 - self.count(w, h, x-1, y, grid) - self.count(w, h, x, y - 1, grid) - self.count(w, h, x + 1, y, grid) - self.count(w, h, x, y + 1, grid)
        return res
        
