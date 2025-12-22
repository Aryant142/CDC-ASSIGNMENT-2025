class Solution {
public:
    bool isplain(string a){
        string s2 = a;
        reverse(s2.begin(),s2.end());
        return s2==a ? 1 : 0;
    }

    void getstr( string s, vector<vector<string>>& ans ,vector<string>& part){
       if(s.size() == 0){
        ans.push_back(part);
        return ;
       }
       
       
       for(int i = 0 ; i < s.size();i++){
        string parts = s.substr(0,i+1);
        if(isplain(parts)){
            part.push_back(parts);
            getstr(s.substr(i+1),ans,part);
            part.pop_back();
        }
       }
    }
    vector<vector<string>> partition(string s) {
      vector<vector<string>> ans;
      vector<string> part ; 
      getstr(s,ans,part);
      return ans ;
    }
};