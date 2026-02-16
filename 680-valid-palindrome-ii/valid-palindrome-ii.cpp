class Solution {
public:
    bool checkPalindrome(string str, int s, int e) {
        while (s <= e) {
            if (str[s] != str[e]) {
                return false;
            } else {
                s++;
                e--;
            }
        }
        return true;
        ;
    }
    bool validPalindrome(string s) {
        int len = s.length();
        int i = 0;
        int j = len - 1;

        while (i <= j) {
            if (s[i] == s[j]) {
                i++;
                j--;
            } else {
                // s[i] != s[j]
                // in this case delete the char
                // there are two option 1) delete the ith index char and 2)
                // delete the jth index char

                // 1st option
                bool ansOne = checkPalindrome(s, i + 1, j);

                // 2nd Option
                bool ansTwo = checkPalindrome(s, i, j - 1);

                bool finalAns = ansOne || ansTwo;

                return finalAns;
            }
        }
        // if reach this stage means we got the answer
        return true;
    }
};