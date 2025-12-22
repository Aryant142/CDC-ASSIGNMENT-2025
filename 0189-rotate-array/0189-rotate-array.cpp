class Solution {
public:
    void rotate(vector<int>& n, int k) {
       
        vector<int>x(n.size());
        for(int i =0 ; i< n.size(); i++){
            x[(i+k)%n.size()] = n[i];
        }
        n=x;
    }    
};