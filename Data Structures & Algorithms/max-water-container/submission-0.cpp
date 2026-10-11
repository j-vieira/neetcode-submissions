class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i = 0; int j = heights.size()-1;

        int maxArea = 0; 
        while(i < j) {
            int area;
            if (heights[i] <= heights[j]) {
                area = (j-i) * heights[i];
                i++;
            } else {
                area = (j-i) * heights[j];
                j--;
            }
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};
