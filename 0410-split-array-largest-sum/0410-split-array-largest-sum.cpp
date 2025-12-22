class Solution {
public:
    bool is_possible(vector<int>& num, int n, int k, int mid) {
        int arr_sum = 0;
        int count = 1;
        for (int i = 0; i < n; i++) {
            if (arr_sum + num[i] <= mid) {
                arr_sum += num[i];
            } else {
                count++;
                if (num[i] > mid || count > k) {
                    return false;
                }
                arr_sum = num[i];
            }
        }
        return true;
    }

    int splitArray(vector<int>& num, int k) {
        int n = num.size();
        int start = 0;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += num[i];
        }
        int ans = -1;
        int end = sum;
        int mid;

        while (start <= end) {
            mid = start + (end - start) / 2;
            if (is_possible(num, n, k, mid)) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return ans;
    }
};