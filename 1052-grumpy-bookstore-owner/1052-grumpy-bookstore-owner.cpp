class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int satisfied = 0;
        int n = customers.size(); 
        for (int i = 0; i < n; i++) {
            satisfied += customers[i] * (1 - grumpy[i]);
        }

        int gain = 0;

        for (int i = 0; i < minutes; i++) {
            gain += customers[i] * grumpy[i];
        }

        int maxGain = gain;

        for (int i = minutes; i < n; i++) {
            gain += customers[i] * grumpy[i];
            gain -= customers[i - minutes] * grumpy[i - minutes];

            maxGain = max(maxGain, gain);
        }

        return satisfied + maxGain;
    }
};