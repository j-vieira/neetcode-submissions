class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(); int n = matrix[0].size();
        return binarySearch(matrix, 0, m*n-1, target) != -1 ? true : false;
    }

    int binarySearch(vector<vector<int>> &matrix, int l, int r, int target) {
        if (l > r) return -1;

        int mid = (l+r)/2;
        
        auto [i, j] = idxToMatrix(mid, matrix[0].size());
    
        if (matrix[i][j] == target) return mid;

        if (matrix[i][j] > target) {
            return binarySearch(matrix, l, mid-1, target);
        }
        return binarySearch(matrix, mid+1, r, target);
    }

    pair<int, int> idxToMatrix(int idx, int n) {
        return {idx / n, idx % n};
    }
};
