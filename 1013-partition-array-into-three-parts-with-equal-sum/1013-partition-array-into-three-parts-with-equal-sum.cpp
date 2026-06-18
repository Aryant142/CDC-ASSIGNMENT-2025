class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int sum = 0;
        for (int x : arr)
            sum += x;

        if (sum % 3 != 0)
            return false;

        int target = sum / 3;
        int curr = 0;
        int count = 0;

        for (int i = 0; i < arr.size(); i++) {
            curr += arr[i];

            if (curr == target) {
                count++;
                curr = 0;
            }
        }

        return count >= 3;
    }
};