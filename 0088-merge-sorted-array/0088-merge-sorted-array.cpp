class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0, j = 0;
        vector<int> x ;
        while (i < m && j < n) {
            if (nums1[i] <= nums2[j]) {
                x.push_back(nums1[i++]);
              
            } else
                x.push_back(nums2[j++]);
               
        }
        while (i < m) {
            x.push_back(nums1[i++]);
         
        }
        while (j < n) {
            x.push_back(nums2[j++]);
            
        }
        for(int k= 0; k < x.size(); k++){
            nums1[k]=x[k];
        }
    }
};