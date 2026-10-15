class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> tFrequencies;
        unordered_map<char, int> sFrequencies;

        for (char c : t) tFrequencies[c]++;

        int required = tFrequencies.size();
        int formed = 0;

        int i = 0; int j = 0;
        int best_i = -1; int best_j = -1;
        while (j < s.size()) {
            char c = s[j];
            sFrequencies[c]++;

            if (tFrequencies.count(c) && sFrequencies[c] == tFrequencies[c]) {
                formed++;
            }

            while (i <= j && formed == required) {
                if (best_i == -1 || j - i < best_j - best_i) {
                    best_i = i; best_j = j;
                }

                char leftChar = s[i];

                if (tFrequencies.count(leftChar) && sFrequencies[leftChar] == tFrequencies[leftChar]) {
                    formed--;
                }

                sFrequencies[leftChar]--;
                i++;
            }
            j++;
        }

        return (best_i != -1) ? s.substr(best_i, best_j - best_i + 1) : "";
    }
};