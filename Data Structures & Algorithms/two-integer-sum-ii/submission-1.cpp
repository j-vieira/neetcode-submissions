class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0; int j = numbers.size()-1;
        while (i < j) {
            int n1 = numbers[i]; int n2 = numbers[j];

            if (n1+n2 == target) {
                return {i+1, j+1};
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
        return {0,0};
    }
};
