class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        for (int i = 0; i < nums1.size(); i++) {
            int ele = nums1[i];
            for (int j = 0; j < nums2.size(); j++) {
                if (ele == nums2[j]) {
                    ans.push_back(ele);
                    nums2[j] = INT_MIN;
                    break;
                }
            }

            // Skip over duplicates in nums1
            // while (i + 1 < nums1.size() && nums1[i] == nums1[i + 1]) {
            //     i++;
            // }
        }
        return ans;
    }
};
