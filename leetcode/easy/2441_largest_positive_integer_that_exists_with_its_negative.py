class Solution:
    def findMaxK(self, nums: List[int]) -> int:
        data_pos = [0] * 1010
        data_neg = [0] * 1010
        for i in nums:
            if i > 0:
                data_pos[i] = 1
            else:
                data_neg[abs(i)] = 1
            
        for j in range(1010-1,0,-1):
            if data_pos[j] == 1 and data_neg[j] == 1:
                return j
        return -1
            
