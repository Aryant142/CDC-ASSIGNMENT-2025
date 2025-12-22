class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;  // both pointers start at 0

        while (i < s.length() && j < t.length()) {
            if (s[i] == t[j]) {
                i++;  // move s pointer if characters match
            }
            j++;      // always move t pointer
        }

        return i == s.length();  // did we match all of s?
    }
};
