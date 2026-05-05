/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node==nullptr){return nullptr;}
        Node* node1 = new Node();
        node1->val = node->val;
        node1->neighbors = node->neighbors;

        //Node* ptr_node1 = &node1;
        std::unordered_map <int, Node*> history;
        //std::queue<Node*> q;
        //q.push(node1);
        //history.insert({node1->val,node1});
        node1 = dfs_helper(history,node1);
        return node1;
    }

    Node* dfs_helper(std::unordered_map <int, Node*> &history, Node* curr){      
        int val = curr->val;
        if (!history.count(val)){
            Node* n = new Node(val,curr->neighbors);
            curr = n;
            history.insert({val,n});
        }
        else{
            curr = history[val];
            return curr;
        }
        int sz = curr->neighbors.size();
        for (int i=0; i<sz; i++){
            curr->neighbors[i] = dfs_helper(history,curr->neighbors[i]);
        }
        return curr;
        
    }

    Node* cloneGraph1(Node* node) {
        if (node==nullptr){return nullptr;}
        Node* node1 = new Node();
        node1->val = node->val;
        node1->neighbors = node->neighbors;

        //Node* ptr_node1 = &node1;
        std::unordered_map <int, Node*> history;
        std::queue<Node*> q;
        q.push(node1);
        history.insert({node1->val,node1});
        
        while(!q.empty()){
            int sz = q.size();
            for (int i=0; i<sz; i++){
                Node* curr = q.front();
                q.pop();
                int sz2 = curr->neighbors.size();
                for (int j=0; j<sz2; j++){
                    Node* nbr = curr->neighbors[j];
                    if (nbr==nullptr){continue;}
                    if (history.count(nbr->val)){
                        curr->neighbors[j] = history[nbr->val];
                    }
                    else{
                        Node* nbr1 = new Node (nbr->val, nbr->neighbors);
                        curr->neighbors[j] = nbr1;
                        history.insert({nbr1->val,nbr1});
                        q.push(nbr1);
                    }
                }
                
            }

        }

        return node1;
    }
};
