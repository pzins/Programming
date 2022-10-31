class Solution:
    
    def can_be_simplified(self, a, b):
        for i in range(2,min(a,b)+1):
            if a%i == 0 and b%i == 0:
                return True
        return False
    
    def simplifiedFractions(self, n: int) -> List[str]:
        res = []
        for i in range(2, n+1):
            for j in range(1, i):
                if not self.can_be_simplified(j, i):
                    res.append("%d/%d" % (j,i))
        return res
                
