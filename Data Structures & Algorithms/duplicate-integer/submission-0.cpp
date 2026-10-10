class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> m;
        
        for (auto n : nums) {
            m[n] += 1;

            if (m[n] > 1) return true;
        }

        return false;
    }
};