class Solution {
public:
    string removeDuplicates(string s) {
        // intialise ans string as empty string
        string ans = "";

        int n = s.length();

        for (int i = 0; i < n; i++) {
            char currChar = s[i];
            if (ans.empty()) {
                // if ans is emty, directly push the currChar
                ans.push_back(currChar);
            } // right most charecter of ans = ans.back()
            else if (currChar == ans.back()) {
                ans.pop_back();
            } else if (currChar != ans.back()) {
                ans.push_back(currChar);
            }
        }

        return ans;
    }
};
