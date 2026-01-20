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
    vector<int> sortByBits(vector<int>& arr) {
        auto ik = [&](int a , int b){
            int x = solve(a);
            int y = solve(b);
            if(x == y) return a < b ;
            return x < y;
        };
        sort(begin(arr),end(arr),ik);
        return arr;
    }
};