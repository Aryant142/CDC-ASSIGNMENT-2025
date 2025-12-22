class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0, maxl = 1;

        for (int i = 0; i < s.size(); i++) {
            expand(s, i, i, start, maxl);       // Odd length center
            expand(s, i, i + 1, start, maxl);   // Even length center
        }

        return s.substr(start, maxl);
    }

    void expand(string& s, int l, int r, int& start, int& maxl) {
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            int len = r - l + 1;
            if (len > maxl) {
                maxl = len;
                start = l;
            }
            l--;
            r++;
        }
    }
};

