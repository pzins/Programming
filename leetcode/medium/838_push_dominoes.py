class Solution:
    def pushDominoes(self, dominoes: str) -> str:
        left = list(dominoes)
        right = list(dominoes)
        
        right_ = [-1] * len(dominoes)
        left_ = [-1] * len(dominoes)
        
        i = 0
        while i < len(dominoes):
            if right[i] == 'R':
                a = 1
                while i+a < len(right) and right[i+a] == '.':
                    right[i+a] = 'R'
                    right_[i+a] = a
                    a += 1
                i += a
            else:
                i += 1
        
        i = 0
        n = len(dominoes) - 1
        while i <= len(dominoes):
            if left[n-i] == 'L':
                a = 1
                while n-i-a >= 0 and left[n-i-a] == '.':
                    left[n-i-a] = 'L'
                    left_[n-i-a] = a
                    a += 1
                i += a
            else:
                i += 1
        
        print(left)
        print(right)

        res = ""
        
        for i in range(len(dominoes)):
            if left[i] == 'L' and (right[i] == '.' or right[i] == 'L'):
                res += 'L'
            elif right[i] == 'R' and (left[i] == '.' or left[i] == 'R'):
                res += 'R'
            elif right[i] == '.' and left[i] == '.':
                res += '.'
            elif left[i] == 'L' and right[i] == 'R':
                if left_[i] < right_[i]:
                    res += 'L'
                elif left_[i] > right_[i]:
                    res += 'R'
                else:
                    res += '.'
        #     print(left[i], right[i], res[-1])
        # print(res)
        return res
                
            

        
