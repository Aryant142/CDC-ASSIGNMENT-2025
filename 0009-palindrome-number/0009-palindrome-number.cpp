class Solution {
public:
    bool isPalindrome(int x) {
      long long a = x ;
      long long b , rev = 0 ;
      while (a > 0){
          b = a % 10;
          rev = rev * 10 + b;
          a /= 10;
      }  
        return x == rev ;
    }
};