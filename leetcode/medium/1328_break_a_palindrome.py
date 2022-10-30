class Solution:
    def breakPalindrome(self, palindrome: str) -> str:
        if len(palindrome) == 1:
            return ""
        res = []
        for i in palindrome:
            res.append(i)
        
        ok = False
        for i in range(len(palindrome) // 2):
            if res[i] != 'a':
                ok = True
                res[i] = 'a'
                break
        if not ok:
            res[-1] = 'b'
            
        
        st = ''.join(res)
        return st
            
            
