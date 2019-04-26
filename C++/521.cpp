__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    int findLUSlength(string a, string b) {
       return a==b?-1:max(a.size(), b.size());

    }
};
__________________________________________________________________________________________________
sample 8296 kb submission
class Solution {
public:
    int findLUSlength(string a, string b) {
        return (a==b)?-1:max(a.length(), b.length());
    }
};
__________________________________________________________________________________________________
