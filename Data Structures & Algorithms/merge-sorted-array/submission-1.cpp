class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n==0){
            return;
        }
        else if (m==0){
            nums1 = nums2;
            return;
        }
        int p1 = m-1;
        int p2 = n-1;
        //int p0 = m+n-1;

        for (int p0 = m+n-1; p0 > -1; p0--){
            if (p1 < 0){
                nums1[p0] = nums2[p2];
                p2--;
                continue;
            }
            else if(p2 < 0){
                return;
            }
            
            int n1 = nums1[p1];
            int n2 = nums2[p2];
            if (n1 > n2){
                nums1[p0] = n1;
                p1--;
            }
            else{
                nums1[p0] = n2;
                p2--;
            }
            
        }
        return;

    }
};