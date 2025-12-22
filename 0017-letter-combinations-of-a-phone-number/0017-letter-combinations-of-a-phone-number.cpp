class Solution {
public:
    void solve(string digit,int index,string mapping[], vector<string>& ans,  string output){
        if(index >= digit.length()){
          ans.push_back(output);
          return;
        }
        int digitx = digit[index]-'0';
        string value = mapping[digitx];
        for(int i = 0 ; i  < value.length() ; i++){
           output.push_back(value[i]);
           solve(digit,index+1,mapping,ans,output);
           output.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digit) {
        vector<string> ans;
        string output ;
        int index = 0; 
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "qprs", "tuv", "wxyz"};
        if(digit.length() == 0) return ans;
        solve(digit,index,mapping,ans,output);
        return ans;
    }
};