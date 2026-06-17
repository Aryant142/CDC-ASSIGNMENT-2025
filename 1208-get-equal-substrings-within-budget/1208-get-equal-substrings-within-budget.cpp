class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int i = 0, j = 0;
        int costUsed = 0;
        int ans = 0;
        int n = s.size();
        while (j < n) {

            costUsed += abs(s[j] - t[j]);

            while (costUsed > maxCost) {
                costUsed -= abs(s[i] - t[i]);
                i++;
            }

            ans = max(ans, j - i + 1);

            j++;
        }

        return ans;
    }
};