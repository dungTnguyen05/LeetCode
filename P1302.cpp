/*
1302. Deepest Leaves Sum
Given the root of a binary tree, return the sum of values of its deepest leaves.

Example 1:
https://assets.leetcode.com/uploads/2019/07/31/1483_ex1.png
Input: root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
Output: 15

Example 2:
Input: root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
Output: 19

Constraints:
The number of nodes in the tree is in the range [1, 10^4].
1 <= Node.val <= 100
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        int depth = treeDepth(root);
        
        if (depth == 0) {
            return 0;
        }

        return sumDeepestLeaves(root, depth, 1);
    }

    int treeDepth(TreeNode* node) {
        if (!node) {
            return 0;
        }

        int leftDepth = treeDepth(node -> left);
        int rightDepth = treeDepth(node -> right);

        return max(leftDepth, rightDepth) + 1; 
    }

    int sumDeepestLeaves(TreeNode* node, int depth, int currDepth) {
        if (!node) {
            return 0;
        }

        if (currDepth == depth) {
            return node -> val;
        }

        int leftSum = sumDeepestLeaves(node -> left, depth, currDepth + 1);
        int rightSum = sumDeepestLeaves(node -> right, depth, currDepth + 1);

        return leftSum + rightSum;
    }
};