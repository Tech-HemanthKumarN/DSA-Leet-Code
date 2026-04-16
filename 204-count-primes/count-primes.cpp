class Solution {
public:
    int countPrimes(int n) {
        if(n == 0) return 0; //If n is 0, there are no primes to count, return immediately.

        // Create a "Prime Tracker" Array

        // Creates a boolean array of size n, every slot starts as true (assume all are prime)
        //0 and 1 are not prime by definition, so mark them false
        vector<bool> prime(n, true);
        prime[0] = prime[1] = false;

        int ans = 0;

        for(int i = 2; i < n; i ++){
            if(prime[i]){
                ans++;

                int j = 2 * i ;
                while(j < n ){
                    prime[j] = false;
                    j += i;
                }
            }
        }
        return ans;
    }
};