class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result;
        
        vector<int> prefixArray(nums.size(), 1); vector<int> suffixArray(nums.size(), 1); 
        
        for (int i = 1; i < nums.size(); i++) {
            prefixArray[i] = prefixArray[i-1]*nums[i-1];
        }

        for (int i = nums.size()-2; i >= 0; i--) {
            suffixArray[i] = suffixArray[i+1]*nums[i+1];
        }

        for (int i=0; i<nums.size(); i++) {
            int r = prefixArray[i] * suffixArray[i];
            result.push_back(r);
        }

        return result;
    }
};
