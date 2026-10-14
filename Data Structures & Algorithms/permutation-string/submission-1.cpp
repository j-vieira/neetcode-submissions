class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        int i = 0;
        int j = s1.size() - 1;
            
        unordered_map<char, int> frequencies;
        for (char c : s1) frequencies[c] +=1;

        bool result = false;
        while (j < s2.size()) {
            unordered_map<char, int> s1Frequencies;
            for (int k = i; k <= j; k++) s1Frequencies[s2[k]] += 1;

            if (frequencies == s1Frequencies) return true;

            i++; j++;
        }

        return result;
    }
};
