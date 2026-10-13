
class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int r = 0;

        unordered_map<char, int> charFrequency;
        
        int longestRepeatingSequence = 0;
        while (r < s.size()) {
            charFrequency[s[r]]++;

            while ((r - l + 1) - getGreatestFrequency(charFrequency) > k) { // necessaryReplacements = windowSize - charFreq 
                charFrequency[s[l]]--;
                l++;
            }

            longestRepeatingSequence = max(longestRepeatingSequence, r - l + 1);
            r++;
        }

        return longestRepeatingSequence;
    }

    int getGreatestFrequency(unordered_map<char, int>& charFrequency) {
        int greatestQuantity = 0;

        for (auto e : charFrequency) {
            greatestQuantity = max(greatestQuantity, e.second);
        }

        return greatestQuantity;
    }
};
