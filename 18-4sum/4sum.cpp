class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        if (n < 4) return ans;
        
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; i++) {
            // 1. Skip duplicate i
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            // 2. PRUNING (The Smart Stuff)
            // Smallest possible sum with this 'i'
            if ((long long)nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break;
            // Largest possible sum with this 'i'
            if ((long long)nums[i] + nums[n - 3] + nums[n - 2] + nums[n - 1] < target) continue;

            for (int j = i + 1; j < n - 2; j++) {
                // 3. Skip duplicate j
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                int p = j + 1;
                int q = n - 1;

                while (p < q) {
                    long long sum = (long long)nums[i] + nums[j] + nums[p] + nums[q];

                    if (sum == target) { // FIXED: Was sum == 0
                        ans.push_back({nums[i], nums[j], nums[p], nums[q]});

                        while (p < q && nums[p] == nums[p + 1]) p++;
                        while (p < q && nums[q] == nums[q - 1]) q--;

                        p++;
                        q--;
                    } else if (sum < target) {
                        p++;
                    } else {
                        q--;
                    }
                }
            }
        }
        return ans;
    }
};