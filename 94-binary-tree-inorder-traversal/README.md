# 94: Binary Tree Inorder Traversal

Given the `root` of a binary tree, return the inorder traversal of its nodes' values.


This solution is trivial with recursion, however recursion will yield a worse-case `O(n)` space complexity because there are worst-case `O(n)` recursive function calls, given a skewed binary tree.

In order to complete this solution with `O(1)` space, we will need to use the **Morris Traversal**, which finds inorder predecessors on its way to the leftmost node and creates **inorder links** in order to backtrack upwards through the tree.

This is how **Morris Traversal** works:

1. If `curr->left` exists:
    a. Get the inorder predecessor `prev`, defined as *the rightmost node in the left subtree*.
    b. If `prev->right` does not exist:
        - Make an **inorder link**, which links the inorder predecessor to its next inorder node. (We do this by setting `prev->right` to `curr`)
        - Move `curr` to the left. (by setting `curr` to `curr->left`)
    c. If `prev->right` *DOES* exist:
        - We have found a previously created **inorder link** that points to the current node, we means we must have visited the inorder predecessor already. Thus, this node is the next inorder node.
        - Print `curr`.
        - `curr->right` will contain the next inorder successor to `curr`. **NOTE: This `right` could be an inorder link.**
        - Move `curr` to the right. (by setting `curr` to `curr->right`)
2. If `curr->left` does not exist:
    - We have reached the leftmost node in the subtree. It is the inorder successor to the previous printed node.
    - `curr->right` will contain the next inorder successor to `curr`. **NOTE: This `right` could be an inorder link.**
    - Move `curr` to the right.

By the end of the iteration, `curr` will be unconditionally set to the right, which will be `NULL` after the last inorder node. We replace "print" with pushing the value to a dynamic array and we have solved this problem.

The time complexity is `O(n)`, and the space complexity is `O(1)`.
