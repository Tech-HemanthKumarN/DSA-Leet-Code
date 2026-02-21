class Solution {
public:
    string longestCommonPrefix(vector<string>& arr) {
        string ans = "";
        int n = arr.size();
        // for traversing all char of first string
        for (int i = 0; i < arr[0].length(); i++) {

            char ch = arr[0][i]; // arr[0] on ith index

            bool match = true;

            // for comparing ch with rest of the string
            for (int j = 1; j < n; j++) {
                // not match
                if (arr[j].size() < i || ch != arr[j][i]) {
                    match = false;
                    break;
                }
            }
            if(match == false){
                break;
            }
            else{
                ans.push_back(ch);
            }
        }
        return ans;
    }
};