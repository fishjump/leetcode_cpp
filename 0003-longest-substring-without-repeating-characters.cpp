#include <string>
#include <unordered_set>

using namespace std;

static inline bool IsEleInHashMap(const std::unordered_set<char> &hashmap,
                                  char ch) {
    return hashmap.find(ch) != hashmap.end();
}

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int right = 0;
        int max = 0;
        int len = s.size();
        std::unordered_set<char> hashmap;
        while (left < len && right < len) {
            if (IsEleInHashMap(hashmap, s[right])) {
                hashmap.erase(s[left]);
                left++;
            } else {
                hashmap.insert(s[right]);
                max = std::max(max, right - left + 1);
                right++;
            }
        }

        return max;
    }
};