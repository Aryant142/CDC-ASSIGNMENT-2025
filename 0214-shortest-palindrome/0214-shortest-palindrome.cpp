class Solution {
public:
    void compute(vector<int>&lps , string p ){
        for(int i = 1 , len = 0 ; i < p.length() ;){
            if(p[len]==p[i]){
                lps[i++]=++len;
            }
            else if(len) len = lps[len-1];
            else lps[i++] = 0;
        }
    }

    string shortestPalindrome(string s) {
        
        string rev = s;
        reverse(rev.begin(), rev.end());

        string pat = s + "#" + rev;

        vector<int> lps(pat.length());
        compute(lps, pat);

        int x = lps[lps.size()-1];

        return rev.substr(0, s.size() - x) + s;
    }
};