class Solution:
    def numWays(self, steps: int, arrLen: int) -> int:
        self.cache = collections.defaultdict(int)   
        x = self.dp(steps, steps, 0, arrLen)
        return x % (10 ** 9 + 7)
        
        
    def dp(self, steps, remains, idx, arrLen):
        if (remains, idx) in self.cache:
            return self.cache[(remains, idx)]
        if idx < 0 or idx > remains or idx >= arrLen:
            return 0
        if remains == 0 and idx == 0:
            return 1
        total = 0
        total += self.dp(steps, remains - 1, idx - 1, arrLen)
        total += self.dp(steps, remains - 1, idx + 1, arrLen)
        total += self.dp(steps, remains - 1, idx, arrLen)
        self.cache[(remains, idx)] = total
        return total 
