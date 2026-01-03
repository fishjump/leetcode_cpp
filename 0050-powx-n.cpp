#include <iostream>

using namespace std;

class Solution {
public:
    double powGt0(double x, int64_t n) {
        int64_t i = 0;
        int64_t acc = 1;
        double result = 1;
        double factor = x;
        while (i != n) {
            if (i + acc > n) {
                acc = 1;
                factor = x;
            }
            result *= factor;
            i += acc;
            acc *= 2;
            factor *= factor;
        }

        return result;
    }

    double powLt0(double x, int64_t n) {
        int64_t i = 0;
        int64_t acc = 1;
        double result = 1;
        double factor = x;
        while (i != n) {
            if (i + acc > n) {
                acc = 1;
                factor = x;
            }
            result /= factor;
            i += acc;
            acc *= 2;
            factor *= factor;
        }

        return result;
    }

    double myPow(double x, int n) {
        int64_t n_prime = n;
        if (n_prime == 0) {
            return 1;
        } else if (n_prime > 0) {
            return powGt0(x, n_prime);
        } else {
            return powLt0(x, -n_prime);
        }
        return 1;
    }
};

int main() {
    Solution solution;
    cout << solution.myPow(2, -2) << endl;
    return 0;
}