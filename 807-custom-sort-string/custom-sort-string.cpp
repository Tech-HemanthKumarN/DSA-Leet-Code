string orderCopy; // golbal variable means class variable

class Solution {
public:
    static bool cmp(char& a, char& b) {
        // login -> chek the order string which will come first and which will
        // come next

        // what will compartor operater will do means
        // true --> a will be placed before b
        // false --> b will be placed before a

        return (orderCopy.find(a) < orderCopy.find(b));
    }
    string customSortString(string order, string s) {
        orderCopy = order;
        sort(s.begin(), s.end(), cmp);
        return s;
    }
};