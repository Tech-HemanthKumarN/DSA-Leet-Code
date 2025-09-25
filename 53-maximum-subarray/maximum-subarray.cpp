// class Solution {
// public:

//     int naive(vector<int>&nums){
//         int n = nums.size();
//         int ans =INT_MIN;

//         for(int i=0; i<n; i++){
//             int sum =0; // intiallizing the sum to zero
//             for(int j=i; j<n; j++){
//                 sum = sum + nums[j];// it will take sum of all subarray, with nums[i] as pivot.
//                 //(pivot-- starting point) 
//                 ans = max(ans,sum);

//             }
//         }
//         return ans;
//     }
//     int maxSubArray(vector<int>& nums) {
//         return naive(nums);
//     }
// };

//________________________________
class Solution {
public:

    int kadaneAlgo(vector<int>&nums){
        int n = nums.size();
        int ans = INT_MIN;
        int sum = 0;
        for(int i=0; i<n; i++){
            int num = nums[i];
            sum+= num;
            ans = max(ans,sum);
            if(sum<0)
            sum=0;
        }
        return ans;

    }

        int maxSubArray(vector<int>& nums) {
        return kadaneAlgo(nums);
    }
};



