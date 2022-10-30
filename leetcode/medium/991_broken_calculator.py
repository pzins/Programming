class Solution:
    def brokenCalc(self, startValue: int, target: int) -> int:
        res = 0
        while startValue != target:
            if target % 2 == 0 and target > startValue:
                target /= 2
            elif target > startValue:
                target += 1
            else:
                res += startValue - target - 1
                startValue = target
                
            res += 1
        return int(res)
                
