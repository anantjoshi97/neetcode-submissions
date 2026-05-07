//mishal

/*

Within a binary tree, a node x is considered good 
if the path from the root of the tree to the node x 
contains no nodes with a value greater than the value of node x
Given the root of a binary tree root, 
return the number of good nodes within the tree

   100 - > good
  1 -> bad
101 -> good
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
    void dfs_helper(TreeNode* root, int max_so_far, int & good_nodes){
        if (root==nullptr){return;}
        int val = root->val;
        if (val < max_so_far){
            ;
        }
        else{
            good_nodes++;
            max_so_far = val;
        }
        dfs_helper(root->left, max_so_far, good_nodes);
        dfs_helper(root->right, max_so_far, good_nodes);
        return;
    }
    int goodNodes(TreeNode* root) {
        if (root==nullptr){return 0;}
        int max_so_far = root->val;
        int good_nodes = 1;
        dfs_helper(root->left, max_so_far, good_nodes);
        dfs_helper(root->right, max_so_far, good_nodes);
        return good_nodes;
    }
};
