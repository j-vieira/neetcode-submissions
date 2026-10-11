class Solution {
public:
    bool isPalindrome(string s) {
        
        int i = 0; int j=s.size()-1;
        while(i<j) {
            char c1 = s[i]; char c2 = s[j];
            if (!isAlphanumeric(c1)) {
                i++;
            } else if (!isAlphanumeric(c2)) {
                j--;
            } else if (isAlphanumeric(c1) && isAlphanumeric(c2)) {
                if (tolower(c1) != tolower(c2)) return false;
                i++; j--;
            }
        }
        return true;
    }

    bool isAlphanumeric(char c) {
        int charIntValue = (int) c;
        bool isAlpha = (charIntValue >= (int)'A' &&  charIntValue <= (int)'Z') || (charIntValue >= (int)'a' &&  charIntValue <= (int)'z');
        bool isNumeric =  charIntValue >= (int)'0' &&  charIntValue <= (int)'9';
        return isAlpha || isNumeric;
    }
};
