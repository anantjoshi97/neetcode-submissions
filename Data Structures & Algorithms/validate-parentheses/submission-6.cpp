class Solution {
public:
    bool isValid(string s) {
        if (s.length()<=1){return !s.length();}
        std::stack<char> stk;
        std::unordered_map <char,char> pairs = {
        {')' , '('},
        {']' , '['},
        {'}' , '{'},
        };

        for (char &c : s){
            if (!pairs.count(c)){
                stk.push(c);
            }
            else{
                if (stk.empty()){return false;}
                if (stk.top()==pairs[c]){
                    stk.pop();
                }
                else{return false;}
            }

        }
        if (stk.empty()){return true;}
        else {return false;}
    }
};
