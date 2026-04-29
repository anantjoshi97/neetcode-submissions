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

    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> output;
        if (root==nullptr){return output;}
        //output.push_back({});

        int level = 0;
        std::queue<TreeNode*> q;

        q.push(root);
        
        while(!q.empty()){
            output.push_back({});
            int sz = q.size();
            for (int i=0; i<sz; i++){
                TreeNode* current = q.front();
                q.pop();
                output[level].push_back(current->val);
                if (current->left!=nullptr){
                    q.push(current->left);
                }
                if(current->right!=nullptr){
                    q.push(current->right);
                }            
            }
            level++;
            
        }

        return output;
    }

    std::vector<std::vector<int>> levelOrder2(TreeNode* root) {
		//std::cout << "trial" <<std::endl;
		int level = 0;
		int nodes_on_current_level = 0;
		int nodes_on_next_level = 0;
		std::vector<std::vector<int>> output;
		if (root==nullptr){return output;}
		output.push_back({});
		std::queue <TreeNode*> q;
		q.push(root);
		nodes_on_current_level++;
		//output[level].push_back(root->val);
		//level++;
		while(!q.empty()){
			TreeNode* current = q.front();
			//std::cout << "front" <<std::endl;
			q.pop();
			//std::cout<<"pop" <<std::endl;
			output[level].push_back(current->val);
			//std::cout<<"current->val"<<std::endl;
			nodes_on_current_level--;
			//if (current == nullptr){continue;}
			if (current->left != nullptr){
				q.push(current->left);
				nodes_on_next_level++;
			}
			if (current->right!=nullptr){
				q.push(current->right);
				nodes_on_next_level++;
			}
			//q.pop();
			if (nodes_on_current_level==0) {
				if(nodes_on_next_level > 0){
				nodes_on_current_level = nodes_on_next_level;
				nodes_on_next_level = 0;
				level++;
				output.push_back({});
				}
				else{break;}
			}
		}
		return output;
	}
};
