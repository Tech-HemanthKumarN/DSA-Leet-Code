class Solution {
public:
    bool canKokoFinishBananasInKSpeed(vector<int>& piles, int h, int k) {
        long long int totalHoursTakenByKokoToFinishAllBananas = 0;
        for (int i = 0; i < piles.size(); i++)
            totalHoursTakenByKokoToFinishAllBananas +=
                ceil(piles[i] / (double)k);
        // if(totalHoursTakenByKokoToFinishAllBananas <= h){
        //     return true;
        // }
        // else{
        //     return  false;
        // }
        // or
        return totalHoursTakenByKokoToFinishAllBananas <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1;
        int ans = -1;
        // auto it = max_element(piles.begin(), piles.end());
        // int end = *it;
        int end = *max_element(piles.begin(), piles.end());
        // end is pkka abs hai

        while (start <= end) {
            int mid = (start + end) >> 1;
            int k = mid;
            
            if (canKokoFinishBananasInKSpeed(piles, h, k)) {
                // koko will finish all bananas
                // without being caught

                ans = k;
                end = mid - 1;
            } else
            start = mid + 1;
        }
        return ans;
    }
};