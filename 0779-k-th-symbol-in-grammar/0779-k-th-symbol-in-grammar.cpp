class Solution {
public:
    int solve(int n , int k){
        
        if(n == 1 && k == 1){
            return 0;
        }
        int length = pow(2,n-1);
        int mid = length/2;
        if(mid >= k){
           return solve(n-1,k);
        }
         return 1-solve(n-1,k-mid);
    }
    int kthGrammar(int n, int k) {
        int ans = solve(n,k);
        return ans;
    }
};