class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        // base case
        if (k == 1) return 'a';

        long long len = 1;
        long long nk = -1;
        int opty = -1;

        for (int i = 0; i < operations.size(); i++) {
            len *= 2;
            if (len >= k) {
                nk = k - len / 2;
                opty = operations[i];
                break;
            }
        }

        char ch = kthCharacter(nk, operations);

        if (opty == 0) return ch;
        return (ch == 'z') ? 'a' : ch + 1;
    }
};
