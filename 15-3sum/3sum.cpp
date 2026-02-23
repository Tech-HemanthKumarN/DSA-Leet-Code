// Brute force approach

// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         vector<vector<int>> ans;

//         set<vector<int>> s;

//         int n = nums.size();

//         int target = 0;

//         for (int i = 0; i < n - 1; i++) {
//             for (int j = i + 1; j < n; j++) {
//                 for (int k = j + 1; k < n; k++) {
//                     if (nums[i] + nums[j] + nums[k] == target) {
//                         vector<int> trip = {nums[i], nums[j], nums[k]};
//                         sort(trip.begin(), trip.end());

//                         if(s.find(trip) == s.end()){
//                             s.insert(trip);
//                             ans.push_back(trip);
//                         }
//                     }
//                 }
//             }
//         }
//         return ans;
//     }
// };

// ___________________
// Optimized vrsion(Two pointer approach)

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            // left
            int j = i + 1;

            // right
            int k = n - 1;

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    ans.push_back({nums[i], nums[j], nums[k]});

                    while (j < k && nums[j] == nums[j + 1])
                        j++;
                    while (j < k && nums[k] == nums[k - 1])
                        k--;


                        j++;
                        k--;
                }
                else if(sum < 0){
                    j++;
                }
                else{
                    k--;
                }
            }
        }
        return ans;
    }
};