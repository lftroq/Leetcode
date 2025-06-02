class Solution:
    cn = 0
    def specialGrid(self, N: int) -> List[List[int]]:
        ans = [[0 for x in range(2 ** N)] for y in range(2 ** N)]
        def fillGrid(xl, yl, xr, yr: int) -> None:
            if(xl == xr and yl == yr):
                ans[xl][yl] = self.cn
                self.cn += 1
            else:
                xmid = (xl + xr) // 2
                ymid = (yl + yr) // 2
                fillGrid(xl, ymid + 1, xmid, yr)
                fillGrid(xmid + 1, ymid + 1, xr, yr)
                fillGrid(xmid + 1, yl, xr, ymid)
                fillGrid(xl, yl, xmid, ymid)
        fillGrid(0, 0, 2 ** N - 1, 2 ** N - 1)
        return ans
                