class Solution {
public:
    string longestPrefix(string s) {
        int pre = 0, suf = 1;
        vector<int> lps(s.size(), 0);  // corrected to store prefix lengths, not chars

        while(suf < s.size()) {
            if(s[pre] == s[suf]) {
                lps[suf] = pre + 1;
                pre++;
                suf++;
            }
            else {
                if(pre == 0) {
                    lps[suf] = 0;
                    suf++;
                }
                else {
                    pre = lps[pre - 1];
                }
            }
        }

        return s.substr(0, lps[s.size() - 1]); // return the longest prefix which is also a suffix
    }
};
