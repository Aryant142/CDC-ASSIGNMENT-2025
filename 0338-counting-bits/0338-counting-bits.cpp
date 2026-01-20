class Solution {
public:
    int solve(int i ){
        long long count = 0 ;
        while(i != 0){
            if (( i & 1) == 1) count++;
            i>>=1;
        }
        return count;
    }
    
    vector<int> countBits(int n) {
        vector<int> res(n+1,0);
        for(int i = 1 ; i < n+1 ; i++){
           res[i] = solve(i);
        }
        return res;
    }
};