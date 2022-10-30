class Solution:
    def sumBase(self, n: int, k: int) -> int:
        digit = []
        while 1:
            a = n // k
            if a == 0:
                digit.append(n)
                break
            digit.append(n - a*k)
            n = a
        return sum(digit)
            
