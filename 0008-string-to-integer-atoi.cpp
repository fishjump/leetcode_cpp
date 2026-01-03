#include <algorithm>
#include <string>

using namespace std;

static inline int32_t charToInt32(char ch) {
  if ('0' <= ch && ch <= '9') {
    return ch - '0';
  }

  return -1;
}

class Solution {
public:
  string_view trimSpace(const string &s) {
    string_view sv{s};
    size_t beg = sv.find_first_not_of(' ');
    if (beg == std::string::npos) {
      return sv;
    }
    return sv.substr(beg);
  }

  std::pair<bool, string_view> judgePosNegAndStrip(const string_view &sv) {
    if (sv.size() == 0) {
      return std::make_pair(true, sv);
    }

    if (sv[0] == '-' || sv[0] == '+') {
      return std::make_pair((sv[0] == '+'), sv.substr(1));
    }

    return std::make_pair(true, sv);
  }

  int64_t parseSvToInt64(const string_view &sv) {
    int64_t result = 0;
    for (char ch : sv) {
      int32_t converted = charToInt32(ch);
      if (converted == -1) {
        break;
      }
      result *= 10;
      result += converted;
      if (result < INT32_MIN || INT32_MAX < result) {
        break;
      }
    }

    return result;
  }

  int32_t roundInt64(int64_t value, bool isPositive) {
    if (!isPositive) {
      value = -value;
    }

    if (value < INT32_MIN) {
      value = INT32_MIN;
    } else if (value > INT32_MAX) {
      value = INT32_MAX;
    }

    return value;
  }

  int myAtoi(string s) {
    auto trimed = trimSpace(s);
    auto [isPositive, sv] = judgePosNegAndStrip(trimed);
    int64_t value = parseSvToInt64(sv);
    return roundInt64(value, isPositive);
  }
};

int main() {
  Solution solution;
  solution.myAtoi("42");
  return 0;
}