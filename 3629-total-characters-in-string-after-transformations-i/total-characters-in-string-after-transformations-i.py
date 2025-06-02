class Solution:
    def lengthAfterTransformations(self, s: str, t: int) -> int:
        MOD = 10 ** 9 + 7
        cn = [0 for _ in range(26)]
        ans = len(s)
        z = 25
        for c in s:
            cn[ord(c) - 97] += 1
        for _ in range(t):
            ans = (ans + cn[z]) % MOD
            cn[(z + 1) % 26] = (cn[(z + 1) % 26] + cn[z]) % MOD
            z = (z + 25) % 26
        return ans