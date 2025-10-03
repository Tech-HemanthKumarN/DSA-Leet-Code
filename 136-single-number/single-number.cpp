// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         int n = nums.size();
//         int i = 0;
//         int ans = -1;

//         while(i < n){
//             if(i + 1 < n && nums[i]==nums[i+1]){
//                 i+=2;
//             }
//             else{
//                 ans = nums[i];
//                 break;
//             }
//         }
//         return ans;

//     }
// };

// Hased form
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // freq table
        unordered_map<int,int> freqMap;

        // add freq to the map/table
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i]; // 1
            freqMap[num] = freqMap[num] + 1;
        }
        unordered_map<int, int>:: iterator it;
        int ans;
        for( it = freqMap.begin(); it!=freqMap.end(); it++ ){
            int key = it->first;
            int freq= it->second;
            if(freq == 1){
                ans = key;
                break;
            }
            // cout<<key<<" "<<value<<endl;
        }
        return ans;
    }
};