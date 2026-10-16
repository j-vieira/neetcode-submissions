class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return binarySearch(nums, 0, nums.size() - 1, target);
    }

    int binarySearch(vector<int>& nums, int l, int r, int target) {
        int mid = (l + r) / 2;

        if (l > r) return l; 
        if (l == r) {
            if (nums[mid] < target) return l+1;
            else return l;
        }

        if (nums[mid] == target) return mid;

        if (nums[mid] > target) {
            return binarySearch(nums, l, mid - 1, target);
        }
        return binarySearch(nums, mid + 1, r, target);
    }
};