
#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        unordered_map<string, vector<string>> hashMap;

        for (const auto &str : strs) {
            string sorted = str;
            std::sort(sorted.begin(), sorted.end());
            vector<string> &vec = hashMap[sorted];
            vec.push_back(str);
        }

        vector<vector<string>> out;
        for (const auto &[k, v] : hashMap) {
            out.push_back(v);
        }

        return out;
    }
};