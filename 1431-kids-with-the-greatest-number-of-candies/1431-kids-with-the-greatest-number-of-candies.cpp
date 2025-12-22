class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> kids(candies.size());
        int maxi = 0;

        // Step 1: Find the maximum number of candies
        for (auto& i : candies) {
            maxi = max(maxi, i);
        }

        // Step 2: Check each kid
        for (int i = 0; i < candies.size(); i++) {
            if (candies[i] + extraCandies >= maxi) {
                kids[i] = true;
            } else {
                kids[i] = false;
            }
        }

        return kids;
    }
};
