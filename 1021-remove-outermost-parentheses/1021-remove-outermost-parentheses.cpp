class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int count = 0;
        
        for (char c : s) {
            if (c == '(') {
                if (count > 0) ans += c; // skip the outermost '('
                count++;
            } else {
                count--;
                if (count > 0) ans += c; // skip the outermost ')'
            }
        }
        
        return ans;
    }
};