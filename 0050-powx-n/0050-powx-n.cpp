class Solution {
public:
    double myPow(double x, int n) {

        double product = 1.0;
        long long N = n;
        if (n == 0)
            return 1;

        if (n < 0) {
            x = 1 / x;
            N = -N;
        }

        while(N > 0) {
            if (N % 2 == 1) {
                product  *= x;
            }
            x *= x;
            N /= 2;
        }

        return product;
    }
};