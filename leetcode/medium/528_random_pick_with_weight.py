import random

class Solution:
    

    def __init__(self, w: List[int]):
        tot = 0
        for i in w:
            tot += i
        self.cumu = []
        curr = 0
        for j in w:
            curr += j / tot
            self.cumu.append(curr)
            
        
            

    def pickIndex(self) -> int:
        nb = random.random()
        for i in range(len(self.cumu)):
            if self.cumu[i] > nb:
                return i
        


# Your Solution object will be instantiated and called as such:
# obj = Solution(w)
# param_1 = obj.pickIndex()
