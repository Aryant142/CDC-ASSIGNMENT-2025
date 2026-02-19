class Solution {
public:
    int strStr(string text, string pat) {

    int n = text.size(), m = pat.size();
    vector<int> lps(m);

    // build LPS
    for (int i = 1, len = 0; i < m; ) {
        if (pat[i] == pat[len])
            lps[i++] = ++len;
        else if (len)
            len = lps[len - 1];
        else
            lps[i++] = 0;
    }

    // search
    for (int i = 0, j = 0; i < n; ) {
        if (text[i] == pat[j]) {
            i++; j++;
            if (j == m) return i - m;
        }
        else if (j)
            j = lps[j - 1];
        else
            i++;
    }

    return -1;
}

};