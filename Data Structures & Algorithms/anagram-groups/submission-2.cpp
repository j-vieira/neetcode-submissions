class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, unordered_map<char, int>> strsIndexCharCount; 
        unordered_map<string, vector<string>> groupsMap;
        vector<vector<string>> groups;

        for (auto s : strs) {
            string key = s;
            sort(key.begin(), key.end());

            groupsMap[key].push_back(s);
        }

        for (auto group : groupsMap) {
            groups.push_back(group.second);
        }
        return groups;
    }

    pair<int, unordered_map<char, int>> getEachCharacterQuantity(string &s) {
        unordered_map<char, int> count;
        int hash = 0;
        for (auto c : s) {
            count[c] += 1;
            hash = hash + (int)c;
        }
        return {hash, count};
    }
};
