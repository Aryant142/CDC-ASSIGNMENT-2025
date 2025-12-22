class Solution {
public:
    string mergeAlternately(string word1, string word2) {
    int i = 0, j = 0;
    string s;

    // Alternately add characters from both words
    while (i < word1.size() && j < word2.size()) {
        s += word1[i++];
        s += word2[j++];
    }

    // Add remaining characters from word1
    while (i < word1.size()) {
        s += word1[i++];
    }

    // Add remaining characters from word2
    while (j < word2.size()) {
        s += word2[j++];
    }

    return s;
}

};