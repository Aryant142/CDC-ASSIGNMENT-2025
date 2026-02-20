class Solution {
public:
    int M = 1e9 + 7;
    int numberOfGoodPartitions(vector<int>& nums) {
        int i = 0 , j =0 ;
        unordered_map<int,int> mp;
        for(int i = 0  ; i < nums.size();i++){
            mp[nums[i]] = i;
        }
        j = max(j,mp[nums[0]]);
        long long res = 1;
        while( i < nums.size()){
            if( i > j){
                res = (res*2) % M;
            }
            j = max(j,mp[nums[i]]);
            i++;
        }
        return res;
    }
};