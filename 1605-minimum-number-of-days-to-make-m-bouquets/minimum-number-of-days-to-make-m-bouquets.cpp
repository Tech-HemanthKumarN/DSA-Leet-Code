class Solution {
public: 
    bool canWeMakeMBouquetsWithDDays(vector<int>& bloomDay, int m, int k, int D){
        int counter = 0;
        for(int i = 0; i <bloomDay.size(); i++){
            //check whether the ith flower is bloomed or not
            if(bloomDay[i] <= D){
                // bloom ho gay hoga
                counter++;
            }
            if(counter == k){
                m--; //i  make can a bouqute
                counter = 0;
                if(m == 0)
                break;
            }
            // not bloomed case
            if(bloomDay[i]> D)
            counter = 0 ;
        }
        return m ==0; //were u able to make M Bouqutes

    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long int Product = ((long long)m * (long long) k);
        if(bloomDay.size() < Product)
        return -1;
        int start = *min_element(bloomDay.begin(), bloomDay.end()); // at least one flower is bloomed
        int end = *max_element(bloomDay.begin(), bloomDay.end()); // all flower is bloomed, pkka ban lung
        int ans = -1;

        while (start <= end) {
            int mid = (start + end) >> 1;
            int day = mid;

            if (canWeMakeMBouquetsWithDDays(bloomDay, m, k, day)) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return ans;
    }
};