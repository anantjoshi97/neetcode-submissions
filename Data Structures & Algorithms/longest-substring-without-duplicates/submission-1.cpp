class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size()<=1){return s.size();}
        int l=0;
        //int r = 0;
        std::unordered_map<char,int> freq;
        freq[s[l]]++;
        int max_length = 1;

        for (int r=1; r<s.size(); r++){
            while (freq[s[r]]>0){
                freq[s[l]]--;
                l++;
            }
            freq[s[r]]++;
            max_length = std::max(r-l+1,max_length);
        }

        return max_length;


    }
};
