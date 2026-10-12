class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_map<char, int> charMap;

        int substringSize = 0; int longestSubstring = 0; 

        int l = 0; int r = 0; 
        while (r < s.size()) {
            char c = s[r];

            if (charMap[c] == 0) {
                charMap[c] += 1;
                substringSize++;
                r++;
            } else {
                charMap[s[l]] -= 1;
                substringSize--;
                l++;
            }

            if (substringSize > longestSubstring) {
                longestSubstring = substringSize;
            }
        }
        
        return longestSubstring;
    }
};