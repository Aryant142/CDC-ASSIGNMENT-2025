class Solution {
public:
    int maxProfit(vector<int>& price) {
        int mini = INT_MAX , maxi=0 ;
        for(auto i : price){
            mini = min(mini,i);
            maxi = max(maxi,i-mini);
        }
        return maxi;
    }
};