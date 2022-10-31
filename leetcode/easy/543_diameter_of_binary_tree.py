# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    
    maxi = 0

    
    def depth(self, node):
        r = 0
        l = 0
        if node.left is not None:
            l = self.depth(node.left) + 1
        if node.right is not None:
            r = self.depth(node.right) + 1
        self.maxi = max(self.maxi, l+r)
        return max(l,r)
        
    
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        res = self.depth(root)
        return self.maxi
