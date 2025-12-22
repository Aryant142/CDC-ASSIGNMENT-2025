class Solution {
public:
    long long getDescentPeriods(vector<int>& p) {
        long long result = 1;
        long long count  = 1;
        for(int i = 1 ; i < p.size() ; i++){
            if (p[i]==p[i-1]-1) count++;
            else count = 1;
            result += count;         
        }
        return result; 
    }
};