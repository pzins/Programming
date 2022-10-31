class Solution:
    def movesToMakeZigzag(self, nums: List[int]) -> int:
        tot = 0
        for i in range(len(nums)):
            if i % 2 == 0:
                # neighbour left
                tmp = 0
                if i != 0:
                    tmp = max(0, nums[i] - nums[i-1] + 1)
                if i < len(nums)-1:
                    tmp = max(tmp, nums[i] - nums[i+1] + 1)
                tot += tmp
        
        res1 = tot
        
        
        tot = 0
        for i in range(len(nums)):
            if i % 2 == 1:
                # neighbour right
                tmp = 0
                if i != 0:
                    tmp = max(0, nums[i] - nums[i-1] + 1)
                if i < len(nums)-1:
                    tmp = max(tmp, nums[i] - nums[i+1] + 1)
                tot += tmp
        
        return min(res1, tot)
