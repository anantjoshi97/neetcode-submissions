#include<cstdlib>
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if (stones.size()==0){return 0;}
        if (stones.size()==1){return stones[0];}

        std::priority_queue<int,vector<int>,std::less<int>> q;
        for (int n : stones){
            q.push(n);            
        }
        while(q.size()>=2){
            int x = q.top();
            q.pop();            
            int y = q.top();
            q.pop();
            if (x==y){continue;}
            else{int w = std::abs(x-y); q.push(w);}
        }
        if(q.empty()){return 0;}
        else{return q.top();}
    }
};
