class Solution {
public:
    int findDuplicate(vector<int>& n) {
        sort(n.begin(), n.end());
        for (int i = 1; i < n.size(); i++) {
            if (n[i] == n[i - 1]) {
                return n[i];
            }
        }
        return -1; // In case no duplicate is found (theoretically shouldn't happen in valid input)
    }
};
