#include <string>

using namespace std;

class Solution {
public:
    string makeRLE(const string &input) {
        std::string output;
        output.reserve(input.size() * 2);
        size_t count = 1;
        char prev = input[0];
        for (int i = 1; i < input.size(); i++) {
            if (input[i] == prev) {
                count++;
                continue;
            }

            output.push_back(count + '0');
            output.push_back(prev);

            count = 1;
            prev = input[i];
        }

        output.push_back(count + '0');
        output.push_back(prev);

        return output;
    }

    string countAndSay(int n) {
        if (n == 1) {
            return "1";
        }

        return makeRLE(countAndSay(n - 1));
    }
};