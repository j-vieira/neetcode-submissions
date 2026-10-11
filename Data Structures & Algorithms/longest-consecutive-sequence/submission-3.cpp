class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());

        int max = 0;
        for (int number : s) {
            int longestForNumber = 0;
            
            bool firstInSequence = s.find(number-1) == s.end();
            if (firstInSequence) {
                int i = 0;
                while(s.find(number+i) != s.end()) {
                    longestForNumber++;
                    i++;
                }
            }

            if (longestForNumber > max) {
                max = longestForNumber;
            }
        }
        return max;
    }
};
