class Solution {
public:
    int missingNumber(vector<int>& num) {
        int n = num.size();
        int expectedSum = n * (n + 1) / 2;
        int actualSum = 0;

        for (int i = 0; i < n; i++) {
            actualSum += num[i];
        }

        return expectedSum - actualSum;
    }
};
