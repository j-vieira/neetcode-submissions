class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> occurrences;
        vector<pair<int, int>> v; // frequency, value
        vector<int> topK;

        for (auto num : nums) {
            occurrences[num] += 1;            
        }

        for (auto &e : occurrences) {
            v.push_back({e.second, e.first});
        }

        sort(v.begin(), v.end(), [](auto const &a, auto const &b) {
            return a.first > b.first;
        });

        for (int i=0; i<k; i++) {
            topK.push_back(v[i].second);
        }

        return topK;
    }
};
