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
    bool helper(TreeNode* root, int sum, int target) {
        if (root==nullptr){return false;}
        int s2 = sum + root-> val;
        if (s2==target && 
            root->left==nullptr && root->right==nullptr)
            {return true;}
        if(helper(root->left,s2,target)){return true;}
        if(helper(root->right,s2,target)){return true;}
        return false;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        return helper(root,0,targetSum);
    }
};