class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, pair<bool, char>> charsMap;
        charsMap['('] = {true, ')'}; charsMap[')'] = {false, '('};
        charsMap['{'] = {true, '}'}; charsMap['}'] = {false, '{'};
        charsMap['['] = {true, ']'}; charsMap[']'] = {false, '['};

        stack<char> st;

        for (char c : s) {
            bool isOpening = charsMap[c].first;
            if (isOpening) {
                st.push(c);
            } else {
                if (st.size() < 1) return false;
                char top = st.top(); st.pop();
                if (top != charsMap[c].second) return false;
            }
        }
        
        return st.size() == 0 ? true : false;
    }
};
