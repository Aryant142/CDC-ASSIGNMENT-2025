class Solution {
public:
    bool is_possible(vector<int>& piles, int h, int k) {
        long long count = 0;
        for (int i = 0; i < piles.size(); i++) {
            if (piles[i] % k == 0) {
                count += piles[i] / k ;
            } else {
                count += (piles[i] / k) + 1;
            }
        }
        return count <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1;
        int end = *max_element(piles.begin(), piles.end()); // max speed needed
        int ans = end;

        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (is_possible(piles, h, mid)) {
                ans = mid; // try to minimize
                end = mid - 1;
            } else {
                start = mid + 1; // increase speed
            }
        }

        return ans;
    }
};
