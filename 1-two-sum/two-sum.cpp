// class Solution {
// public:
//     vector<int> twoSum(vector<int>& arr, int target) {
//         int n = arr.size();

//         for(int i = 0; i < n - 1; i++){
//             for(int j = i + 1; j < n; j++){
//                 if(arr[i] + arr[j] == target){
//                     return {i,j};
//                 }
//             }
//         }
//         return {};
//     }
// };

class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {

        unordered_map<int, int> mapping;
        vector<int> ans;

        for(int  i = 0; i < arr.size(); i++){
            int first = arr[i];
            int second = target - first;

            if(mapping.find(second) != mapping.end()){
                ans.push_back(i);
                ans.push_back(mapping[second]);
                break;
            }
            mapping[first] = i;
        }
        return ans;
    }
};