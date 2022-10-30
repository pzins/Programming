class Solution:
    def replaceElements(self, arr: List[int]) -> List[int]:
        curr = -1
        res = [-1]
        for j in range(len(arr)-1, 0, -1):
            curr = max(curr, arr[j])
            res.append(curr)
        return list(reversed(res))
            
