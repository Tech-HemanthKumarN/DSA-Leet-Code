class Solution {
public:
    string decodeMessage(string key, string message) {

        // TC of unodered map is O(1)
        // step1 create maping
        unordered_map<char, char> mapping;

        char space =' ';

        mapping[space] = space;

        char start = 'a';

        int index = 0;

        while (start <= 'z' && index < key.length()) {
            char currCharOfKey = key[index];
            // start-> mapping abcd...
            // mapping -> currCharOfKey ke coresponding write alphabet
            if (mapping.find(currCharOfKey) != mapping.end()) {
                // if the mapping of currChar is already present
                // no need to store any mapping here just move to next char in
                // key
                index++;
            } else {
                // already not present
                // create mapping and move ahead
                mapping[currCharOfKey] = start;
                start++;
                index++;
            }
        }
        // step2: use mapping and decode msg
        string ans = "";
        for (int i = 0; i < message.length(); i++) {
            char msgCharacter = message[i];
            char mappedCharacter = mapping[msgCharacter];
            ans.push_back(mappedCharacter);
        }
        return ans;
    }
};