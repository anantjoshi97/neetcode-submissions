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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> output;
        if (root==nullptr){return output;}

        int level = 0;
        std::queue<TreeNode*> q;
        q.push(root);
        TreeNode* current;

        while(!q.empty()){
            int sz = q.size();
            for(int i=0; i<sz; i++){
                current = q.front();
                q.pop();
                if (current->left!=nullptr){
                    q.push(current->left);
                }
                if (current->right!=nullptr){
                    q.push(current->right);
                }
            }
            output.push_back(current->val);
        }

        return output;

    }
};
