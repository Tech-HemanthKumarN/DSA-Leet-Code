class Solution {
public:
    int mySqrt(int x) {
        int s = 0;
        int e = x;
        long long int mid = s + (e-s)/2;
        int ans = -1;

        while(s<=e){
            long long  int product = mid*mid;
            //happy case
            if(product== x){
                return mid;
            }
            if(product < x){
                //may or may not be
                //do store and compute
                ans = mid;// store
                //go to right to find orjada pass ka answer
                s = mid+1;//compute
            }
            else{
                //if mid*mid > x --> go to left
                e =mid - 1;
            }
            mid = s+(e-s)/2;
        }
        return ans;
        
    }
};