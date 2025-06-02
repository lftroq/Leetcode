class Solution:
    def goodTriplets(self, nums1: List[int], nums2: List[int]) -> int:
        n = len(nums1)
        print(n)
        v = [0 for _ in range(n)]
        for i in range(n):
            v[nums2[i]] = i
        print(v)
        bit = [0 for _ in range(n + 1)]
        ans = bit.copy()
        def update(x: int):
            while(x <= n):
                bit[x] += 1
                x += (x & (-x))
        
        def get(x: int) -> int:
            ans = 0
            while(x):
                ans += bit[x]
                x -= (x & (-x))
            return ans
        for x in nums1:
            ans[v[x]] = get(v[x] + 1)
            update(v[x] + 1)
        for i in range(1, n + 1): 
            bit[i] = 0
        for x in nums1[::-1]:
            ans[v[x]] *= get(n - v[x])
            update(n - v[x])
        return sum(ans)