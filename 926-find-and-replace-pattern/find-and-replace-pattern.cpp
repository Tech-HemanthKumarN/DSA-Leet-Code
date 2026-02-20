class Solution {
public:
    void normalise(string& str) {
        char start = 'a';
        unordered_map<char, char> mapping;

        for (int i = 0; i < str.length(); i++) {
            char stirngKaCharecter = str[i];
            if (mapping.find(stirngKaCharecter) == mapping.end()) {
                // if mapping is not present at first
                // then create it and move ahead
                mapping[stirngKaCharecter] = start;
                start++;
            }
        }
        // mapping is created now
        // string str ko update or normailse kardo using mapping
        for (int i = 0; i < str.length(); i++) {
            char mappedChar = mapping[str[i]];
            str[i] = mappedChar;
        }
        // tho humne str wali string normalise update / normailse kardia
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        normalise(pattern);
        // let's travrese on words --> normailse them --> check k vo pattern ke
        // equal or nahi
        for (int i = 0; i < words.size(); i++) {
            // ith word
            string currWord = words[i];
            // noralise karo word ko
            string currWordCopy = currWord;
            normalise(currWordCopy);
            if (currWordCopy == pattern) {
                // ans me store kena h
                ans.push_back(currWord);
            }
        }
        return ans;
    }
};