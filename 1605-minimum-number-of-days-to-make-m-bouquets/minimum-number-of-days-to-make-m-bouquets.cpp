class Solution {
public:
    bool canWeMakeMBouquetsWithDDays(vector<int>& bloomDay, int m, int k, int D){
        int counter = 0;
        for(int  i=0; i<bloomDay.size(); i++){
            if(bloomDay[i] <= D){
                counter++;
            }
            if(counter == k){
                m--;
                counter = 0;
                if(m == 0)
                break;
            }
            if(bloomDay[i] > D)
            counter = 0;
        }
        return m == 0;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long int Product = (long long)m *(long long) k;
        if(bloomDay.size() < Product)
        return -1;
        int start = *min_element(bloomDay.begin(),bloomDay.end());
        int end = *max_element(bloomDay.begin(),bloomDay.end());
        int ans = -1;

        while(start <= end){
            int mid = (start + end) >>1;
            int day = mid;

            if(canWeMakeMBouquetsWithDDays(bloomDay,m,k,day)){
                ans = mid;
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
        return ans;
        
    }
};