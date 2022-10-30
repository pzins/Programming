class Solution:
    def rangeSum(self, nums: List[int], n: int, left: int, right: int) -> int:
        tmp = []
        for i in range(len(nums)):
            curr = 0
            for j in range(i, len(nums)):
                tmp.append(curr + nums[j])
                curr += nums[j]
        tmp = list(sorted(tmp))
        res = 0
        for i in range(left-1, right):
            res += tmp[i]
        return res % (1000000007)
                
                
