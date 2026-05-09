/*

int r = 1;

n > 0
for 
    y x y x y ... y
n = 0
1
n < 1
1/(y x y x y ... y)

return r;


*/

class Solution {
public:
    double myPow(double x, int n) {
        
        double r = 1;
        double p;
        if (n==0){return r;}

        if (n>0){
            p = x;
        }
        else{
            p = (1.00/x);
        }

        for (int i=1; i<= std::abs(n); i++){
            r = r*p;
        }
        return r;

    }
};
