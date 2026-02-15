class Solution {
public:
    string removeDuplicates(string s, int k) {
        // Stack to store {character, count}
        vector<pair<char, int>>stack;
        for(char c : s){
            if(!stack.empty() && stack.back().first == c){
                // If match, increment count
                stack.back().second++;
            }
            else{
                // If no match, push new character with count 1
                stack.push_back({c,1});
            }
            // If count reaches k, remove it
            if(stack.back().second == k){
                stack.pop_back();
            }
        }
        // Reconstruct the string from the stack
        string result = "";
        for(auto const& p : stack){
            result.append(p.second, p.first);
        }
        return result;
    }
};