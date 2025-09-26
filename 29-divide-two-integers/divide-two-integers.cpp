class Solution {
public:
    int divide(int dividendx, int divisorx) {
        if(dividendx == INT_MIN && divisorx == -1){
            return INT_MAX;
        }

        bool ans_pos_sign = true;
        if(dividendx > 0 && divisorx < 0)
        ans_pos_sign = false;
        if(dividendx < 0 && divisorx > 0)
        ans_pos_sign = false;

        long long  dividend = abs((long long )dividendx);
        long long  divisor = abs((long long)divisorx);
        long long s = 0, e = dividend;
        long long ans = -1;

        while(s <= e){
            long long mid = s+((e-s)>>1);
            if( divisor * mid <= dividend){
                ans = mid;
                s = mid+1;
            }
            else{
                e = mid - 1;
            }
        }
        if(ans_pos_sign == false)
        return -ans;
        return ans;
    }
};
