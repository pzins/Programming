class Solution:
    data = []  
    def build(self, curr, n, k):
        if len(curr) == n:
            if curr not in self.data:
                self.data.append(curr)
        else:
            for i in [k, -k]:
                if curr[-1] + i <= 9 and curr[-1] + i >= 0:
                    self.build(curr + [curr[-1] + i], n, k)
                
    def numsSameConsecDiff(self, n: int, k: int) -> List[int]:
        res = []
        self.data = []

        for i in range(1,10):
            self.build([i], n, k)
        
        
        for i in self.data:
            res.append(int("".join([str(j) for j in i])))
        return res
