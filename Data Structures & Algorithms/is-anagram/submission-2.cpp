class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> sMap; unordered_map<char, int> tMap;
        
        if (s.size() != t.size()) return false;

        for (auto c : s) {
            sMap[c] += 1;
        }

        for (auto c : t) {
            tMap[c] += 1;
        }

        for (auto el : sMap) {
            if (el.second != tMap[el.first]) return false;
        }

        return true;
    }
};
