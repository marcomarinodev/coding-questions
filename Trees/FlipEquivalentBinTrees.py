from typing import Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        
class Solution:
    def flipEquiv(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:
        if root1 is root2:
            return True
        
        if not root1 or not root2 or root1.val != root2.val:
            return False

        return (
            self.flipEquiv(root1.left, root2.left) and self.flipEquiv(root1.right, root2.right) or 
            self.flipEquiv(root1.left, root2.right) and self.flipEquiv(root1.right, root2.left)
        )

sol = Solution()

tree1 = TreeNode(1,
    TreeNode(2, 
        TreeNode(4),
        TreeNode(5, TreeNode(7), TreeNode(8))    
    ),
    TreeNode(3, TreeNode(6))
)

tree2 = TreeNode(1,
    TreeNode(3, None, TreeNode(6)),
    TreeNode(2, 
        TreeNode(4),
        TreeNode(5, TreeNode(8), TreeNode(7))    
    )
)

print(sol.flipEquiv(tree1, tree2))