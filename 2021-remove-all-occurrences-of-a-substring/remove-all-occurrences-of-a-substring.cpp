class Solution {
public:
    string removeOccurrences(string full, string pattern) {

        // In full string until the pattern string found run the loop
        while (full.find(pattern) != string::npos) {
            // erase in full string
            //  in erase function we have 2 argumnet, in 1st argument we have
            //  pattern starting index
            // full.find(pattern), full string its providing the starting of the
            // pattern in 2nd argument have to specify, how many char have to
            // remove from starting index.
            full.erase(full.find(pattern), pattern.length());
        }

        return full;
    }
};