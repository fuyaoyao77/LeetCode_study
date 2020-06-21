//124. 二叉树中的最大路径和
/*
递归的思路

给定一个非空二叉树，返回其最大路径和。

本题中，路径被定义为一条从树中任意节点出发，达到任意节点的序列。该路径至少包含一个节点，且不一定经过根节点。

示例 1:

输入: [1,2,3]

       1
      / \
     2   3

输出: 6
示例 2:

输入: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

输出: 42


*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    int maxpath = INT_MIN;
public:
    int maxsubpath(TreeNode* root){
        if(root == nullptr) return 0;

        int leftmax = max(maxsubpath(root->left),0);
        int rightmax = max(maxsubpath(root->right),0);

        maxpath = max(maxpath, root->val + leftmax + rightmax);

        return root->val + max(leftmax,rightmax);
    }

public:
    int maxPathSum(TreeNode* root) {
        maxsubpath(root);
        return maxpath;
    }
};

