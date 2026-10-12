class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> result;
        for (int i=0; i<nums.size(); i++) {
            if (i==0 || nums[i]!=nums[i-1]) {
            int target = -nums[i];
                twoSum(i+1, nums, target, result);
            }
        }
        return result;
    }

    void twoSum(int i, vector<int>& numbers, int target, vector<vector<int>> &result) {
        int j = numbers.size()-1;
        while (i < j) {
            int n1 = numbers[i]; int n2 = numbers[j];

            if (n1+n2 == target) {
                result.push_back({-target, numbers[i], numbers[j]});
                while (i + 1 < numbers.size() && numbers[i] == numbers[i+1]) i++;
                while (j > 0 && numbers[j]==numbers[j-1]) j--;
            } 

            if (n1+n2 > target) {
                j--;
            } else if (n1+n2 < target) {
                i++;
            } else if (n1-target >= n2-target) {
                i++;
            } else if (n1-target < n2-target) {
                j--;
            }
        }
    }
};
