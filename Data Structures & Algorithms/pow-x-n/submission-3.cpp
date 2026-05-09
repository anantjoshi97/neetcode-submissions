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


y^(300) = y^(150) y^(150)
y^(150) = y^(75) y^(75)
y^(75) = y^(37) y^(38)

*/

class Solution {
public:

    double myPow(double x, int n){
        if (n==0){return 1.00;}
        if (x==0.00 || x==1.00){return x;}
        return myPow_helper(x,n);
    }

    double myPow_helper(double x, int n){
        if (n==1){return x;}
        else if(n==-1){return 1.00/x;}
        else if (n==2){return x*x;}
        else if (n==-2){return (1.00/(x*x));}
        else{
            int m = n/2;
            int m1 = n - m;
            return myPow(x,m) * myPow(x,m1);
        }
    }


    double myPow1(double x, int n) {
        
        double r = 1;
        double p;
        if (n==0){return r;}
        if (x==0 || x==1){return x;}

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
