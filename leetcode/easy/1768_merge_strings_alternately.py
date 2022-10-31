class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        left = 0
        right = 0
        res = ""
        cnt = 0
        while left < len(word1) and right < len(word2):
            if cnt % 2 == 0:
                res += word1[left]
                left += 1
            else:
                res += word2[right]
                right += 1
            cnt += 1
        if left >= len(word1):
            res += word2[right:]
        else:
            res += word1[left:]
        return res
