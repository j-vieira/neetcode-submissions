class Solution {
public:
    int findMin(vector<int> &nums) {
        return binarySearch(nums, 0, nums.size()-1, nums[0]);
    }

    int binarySearch(vector<int> &nums, int l, int r, int currentMin) {
        if (l > r) return currentMin;

        int mid = (l+r) / 2;
        
        currentMin = (currentMin > nums[mid]) ? nums[mid] : currentMin;

        bool minInRight = nums[r] < nums[mid];
        if (minInRight) {
            return binarySearch(nums, mid+1, r, currentMin);
        }
        return binarySearch(nums, l, mid-1, currentMin);
    }
};
