# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    
    data = []
    result = []
    result_node = None
    
    def dfs(self, r, curr):
        if r.left is not None:
            self.dfs(r.left, curr + [r.left.val])
        if r.right is not None:
            self.dfs(r.right, curr + [r.right.val])
        if r.left is None and r.right is None:
            self.data.append(curr)
    
    def dfs_search(self, r, search):
        if r.val == search:
            self.result_node = r
        if r.left is not None:
            self.dfs_search(r.left, search)
        if r.right is not None:
            self.dfs_search(r.right, search)
            
            
    def to_list(self, root):
        if root is not None:
            self.result.append(root.val)
        
            if root.left is not None:
                self.to_list(root.left)
            if root.right is not None:
                self.to_list(root.right)
    
    
    def lcaDeepestLeaves(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        self.dfs(root, [root.val])
        if len(self.data) == 1:
            lca = self.data[0][len(self.data[0])-1]
        else:
            self.data.sort(key = len, reverse=True)
            size = len(self.data[0])
            path = []
            for i in self.data:
                if len(i) == size:
                    path.append([*reversed(i)])
                else:
                    break
            # print(path)
            lca = -1
            for j in range(len(path[0])):
                tmp = []
                for k in range(len(path)):
                    tmp.append(path[k][j])

                if tmp.count(tmp[0]) == len(tmp): 
                    lca = tmp[0]
                    break
        # print(lca)
        self.dfs_search(root, lca)
        # print(self.result_node)
        self.to_list(self.result_node)
        # print(self.result)
        return self.result_node
        

