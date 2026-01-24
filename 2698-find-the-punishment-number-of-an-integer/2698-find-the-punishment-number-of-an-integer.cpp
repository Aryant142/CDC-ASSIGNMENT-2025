class Solution {
public:
   bool check(int idx , int sum , string st, int x){
        if(idx == st.length()) return sum == x;
        if(sum > x) return false;
        bool solve = false;
        for(int j = idx ; j < st.length() ; j++){
            string s = st.substr(idx,j-idx+1);
            int val = stoi(s);
            solve = solve || check(j+1,sum+val,st,x);
            if(solve) return true;
        }
        return false;
   }
   
    int punishmentNumber(int n) {
        int punish = 0;
        for(int i = 1 ; i <= n ; i++){
            int sq = i*i;
            string st = to_string(sq);
            if(check(0,0,st,i))
               punish += sq;
        }
        return punish;
    }
};