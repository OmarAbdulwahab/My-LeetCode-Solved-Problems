# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        # BFS: just add the last node in the level to the answer
        ans = []
        q = deque([root])
        
        while q:
            last_node = None
            
            for i in range(len(q)):
                node = q.popleft()
                if node:
                    q.append(node.left)
                    q.append(node.right)
                    last_node = node
            if last_node:
                ans.append(last_node.val)
                
        return ans