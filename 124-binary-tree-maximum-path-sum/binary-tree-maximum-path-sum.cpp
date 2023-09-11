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
    //Function to return maximum path sum from any node in a tree.
      int maxPathSum(TreeNode* root, int &mxSum) {
        if(root == NULL) return 0;

        int leftSum = max(0,maxPathSum(root->left,mxSum));
        int rightSum = max(0,maxPathSum(root->right,mxSum));
        
        mxSum = max(mxSum,(root->val)+leftSum+rightSum);
        
        return (root->val) + max(leftSum,rightSum);
    }
    int maxPathSum(TreeNode* root) {
        int mxSum = INT_MIN;
        maxPathSum(root,mxSum);
        return mxSum;
    }
};