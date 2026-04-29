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
    //int get_min (TreeNode* root){
//
   // }
    void in_order_distinct(TreeNode* root, int &l, const int &k, int &output){
        if(root==nullptr){return;}
        in_order_distinct(root->left,l,k,output);        
        l++;
        if (l==k){output = root->val; return;}
        in_order_distinct(root->right,l,k,output);
        return;
    }

    int kthSmallest(TreeNode* root, int k) {
        if (root==nullptr){return -1;}
        int l=0;
        int output = 0;
        in_order_distinct(root,l,k,output);

        return output;
    }
};
