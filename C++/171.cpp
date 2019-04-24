__________________________________________________________________________________________________
sample 4 ms submission
#include <string>
#include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:
    // (26 ^ i) * val
    int titleToNumber(string s) {
        if (s.empty())
            return 0;

        int num = 0;
        int i = s.size() - 1;
        for (auto c : s) {
            num += pow(26, i) * (c - 'A' + 1);
            --i;
        }

        return num;
    }
};
__________________________________________________________________________________________________
sample 7892 kb submission
class Solution {
public:
    int titleToNumber(string s) {
        int result = 0;
        for(int i = 0; i < s.length(); i++){
            result = result*26 + (s.at(i) - 'A'+1);
        }
        
        return result;
    }
};
__________________________________________________________________________________________________
