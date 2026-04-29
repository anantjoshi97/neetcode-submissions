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
    int get_min (TreeNode* root){
        if (root->left==nullptr){return root->val;}
        int min = get_min(root->left);
        return min;
    }

    void in_order_general(TreeNode* root, int &l, const int &k, int & prev_val, int &output){
        if (root == nullptr){return;}
        in_order_general(root->left,l,k,prev_val,output);        
        prev_val = root->val;
        l++;
        if (l==k){output = root->val; return;}
        if (l> k){return;}
        in_order_general(root->right,l,k,prev_val,output);
        return;
    }

    void in_order_distinct(TreeNode* root, int &l, const int &k, int &output){
        //if (l>=k){return;}
        if(root==nullptr || l >=k){return;}
        in_order_distinct(root->left,l,k,output);        
        l++;
        if (l==k){output = root->val; return;}
        if (l > k){return;}
        in_order_distinct(root->right,l,k,output);
        return;
    }

    int kthSmallest(TreeNode* root, int k) {
        if (root==nullptr){return -1;}
        int l=0;
        int output = root->val;
        //int prev_val = get_min(root);
        in_order_distinct(root,l,k,output);
        //in_order_general(root,l,k,prev_val,output);

        return output;
    }
};
