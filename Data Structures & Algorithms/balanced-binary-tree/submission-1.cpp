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
    int get_ht (TreeNode* root){
        if (root==nullptr){return -1;}
        int ht_left = get_ht(root->left);
        int ht_right = get_ht(root->right);
        int ht = 
            std::max(ht_left,ht_right) + 1;
        return ht;
    }
    bool isBalanced(TreeNode* root) {
        if (root==nullptr){return true;}
        int ht_left = get_ht(root->left);
        int ht_right = get_ht(root->right);
        bool b1 = (std::abs(ht_left - ht_right)<=1);
        if (b1 && isBalanced(root->left) && isBalanced(root->right)){
            return true;
        }
        return false;
    }
};
