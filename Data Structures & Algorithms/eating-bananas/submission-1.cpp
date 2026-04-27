class Solution {
public:
    int minEatingSpeed(std::vector<int>& piles, int h) {
        auto can_eat = [&](int rate){
            int t=0;
            for (int stk : piles){
                t+=stk/rate;
                if (stk%rate>0){t++;}
                if(t > h){return 1;}
            }
            if (t==h){return 0;}
            else {return -1;}
        };

        
        int l=1;
        int r = *std::max_element(piles.begin(),piles.end());
        if (r==0){return 0;}
        //cout << r << endl;
        // std::vector<int> rates(l,r);
        // cout << rates[0] << endl;
        int output;

        while (l <=r){
            int mid = l + (r-l)/2;
            int dec = can_eat(mid);
            cout << "mid=" << mid << " " 
                << "dec=" << dec << endl;
            if (dec==0){output = mid; r = mid - 1;}
            else if (dec == -1){output = mid; r = mid - 1;}
            else if (dec == 1){l = mid + 1;}
        }

        return output;
    }
};
