//class Solution {
//public:
    // bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    //     if (numCourses==1){return true;}
    //     //std::vector<bool> courses;
    //     std::unordered_map<int,vector<int>> in, out;
    //     std::unordered_set<int> history;
    //     std::queue<int> q;

    //     for (int i=0; i<numCourses; i++){
    //         history.insert(i);
    //     }

    //     for (vector<int> p : prerequisites){
    //         int c = p[0];
    //         history.erase(c);
    //         q.push(c);
    //         int pr = p[1];
    //         in[c].push_back(pr);
    //         out[pr].push_back(c);
    //     }

    //     //if (history.empty()){return false;}
    //     //else if(history.size()==numCourses){return true;}

    //     // for (int pre : history){
    //     //     q.push(pre);
    //     // }
    //     int new_sz = 0;
    //     int sz = q.size();
    //     while(!q.empty() && new_sz < sz){
    //         sz = q.size();
    //         for (int i=0; i<sz; i++){
    //             int c = q.front();
    //             q.pop();
    //             bool can_do = true;
    //             for (int pre : in[c]){
    //                 can_do = history.count(pre);
    //                 if (!can_do){break;}
    //             }
    //             if (can_do){history.insert(c);}
    //             else{q.push(c);}
    //         }
    //         new_sz = q.size();
    //     }
        
    //     return(history.size()==numCourses);



    // }
//};

    class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);

        for (auto& pre : prerequisites) {
            indegree[pre[0]]++;
            adj[pre[1]].push_back(pre[0]);
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int finish = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            finish++;
            for (int nei : adj[node]) {
                indegree[nei]--;
                if (indegree[nei] == 0) {
                    q.push(nei);
                }
            }
        }

        return finish == numCourses;
    }
};

