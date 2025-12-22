class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        vector<int> freq(1000005, 0);
        int maxi = -1;
        for (auto i : nums) {
            if (i % 2 == 0) {
                freq[i]++;
                maxi = max(maxi, freq[i]);
            }
        }
        if (maxi == -1)
            return -1;

        for (int i = 0; i < 100000; i++) {
            if (freq[i] == maxi) {
                return i;
            }           
        }
        return -1;
    }
};