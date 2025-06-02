class Solution:
    def maxTaskAssign(self, tasks: List[int], workers: List[int], pills: int, strength: int) -> int:
        n = len(tasks)
        m = len(workers)
        tasks.sort()
        workers.sort()
        ans, l, r = 0, 0, min(m, n)
        while l <= r:
            mid = (l + r) // 2
            def check(mid: int) -> bool:
                cn = 0
                dq = deque()
                j = m - 1
                for i in range(mid - 1, -1, -1):
                    x = tasks[i]
                    if dq and dq[0] >= x:
                        dq.popleft()
                    elif j >= m - mid and workers[j] >= x:
                        j -= 1
                    else:
                        while j >= m - mid and workers[j] + strength >= x:
                            dq.append(workers[j])
                            j -= 1
                        if not dq:
                            return False
                        dq.pop()
                        cn += 1
                return cn <= pills
            if check(mid):
                ans = mid
                l = mid + 1
            else:
                r = mid - 1
        return ans