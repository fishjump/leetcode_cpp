#include <stdint.h>

class Solution {
public:
  bool SafeMulti10(int &x) {
    if (x < 0) {
      if (x < (INT32_MIN / 10)) {
        x = 0;
        return false;
      }
    } else if (x > 0) {
      if ((INT32_MAX / 10) < x) {
        x = 0;
        return false;
      }
    }

    x *= 10;
    return true;
  }

  bool SafeAdd(int &x, int a) {
    if (x < 0) {
      if ((x + a) > 0) {
        x = 0;
        return false;
      }
    } else if (x > 0) {
      if ((x + a) < 0) {
        x = 0;
        return false;
      }
    }

    x += a;
    return true;
  }

  int reverseRecursive(int x, int acc) {
    if (x == 0) {
      return acc;
    }

    if (!SafeMulti10(acc)) {
      return acc;
    }

    if (!SafeAdd(acc, x % 10)) {
      return acc;
    }

    return reverseRecursive(x / 10, acc);
  }

  int reverse(int x) { return reverseRecursive(x, 0); }
};