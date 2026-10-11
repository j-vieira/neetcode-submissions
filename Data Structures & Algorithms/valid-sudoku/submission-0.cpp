class Solution {
public:
    
    bool isValidSudoku(vector<vector<char>>& board) {
        bool isValid = true;

        for (int i=0; i<board.size(); i++) {
            isValid = isValid && isValidLine(i, board);
        }
        
        for (int j=0; j<board.size(); j++) {
            isValid = isValid && isValidColumn(j, board);
        }

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board.size(); j++) {
                if (i % 3 == 0 && j % 3 == 0) {
                    isValid = isValid && isValidSubBox(i, j, board);
                }
            }
        }

        return isValid;
    }

    bool isValidLine(int i, vector<vector<char>>& board) { // i = line
        unordered_map<char, int> occurrences;
        for(int j=0; j < board.size(); j++) {
            char c = board[i][j];
            if (c != '.') {
                if (occurrences[c] == 1) return false;
                occurrences[c] += 1;
            }
        }
        return true;
    }

    bool isValidColumn(int j, vector<vector<char>>& board) { // j = column
        unordered_map<char, int> occurrences;
        for(int i=0; i < board.size(); i++) {
            char c = board[i][j];
            if (c != '.') {
                if (occurrences[c] == 1) return false;
                occurrences[c] += 1;
            }
        }
        return true;
    }

    bool isValidSubBox(int p, int q, vector<vector<char>> &board) {
        unordered_map<char, int> occurrences;

        for (int i = p; i <= p+2; i++) {
            for (int j = q; j <= q+2; j++) {
                char c = board[i][j];
                if (c != '.') {
                    if (occurrences[c] == 1) return false;
                    occurrences[c] += 1;
                }
            }
        }
        
        return true;
    }
};
