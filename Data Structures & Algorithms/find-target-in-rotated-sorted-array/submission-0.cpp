class Solution {
public:
    int search(vector<int>& nums, int target) {
        return binarySearch(nums, 0, nums.size()-1, target);
    }

    int binarySearch(vector<int> &nums, int l, int r, int target) {
        if (l > r) return -1;

        int mid = (l+r)/2;

        if (nums[mid] == target) return mid;

        bool leftIsOrdered = nums[l] <= nums[mid];
        if (leftIsOrdered) {
            bool targetInLeft = nums[l] <= target && target < nums[mid];
            if (targetInLeft) {
                return binarySearch(nums, l, mid-1, target);
            }
            return binarySearch(nums, mid+1, r, target); // search in right
        } else {
            bool targetInRight = target <= nums[r] && nums[mid] < target;
            if (targetInRight) {
                return binarySearch(nums, mid+1, r, target); 
            }
            return binarySearch(nums, l, mid-1, target);
        }
    }
};
