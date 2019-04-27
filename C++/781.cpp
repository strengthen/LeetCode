__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        vector<int> count(1000, 0);
        
        int n = answers.size(), res = 0;
        
        for(int i = 0; i < n; i++) {
           count[answers[i]]++;
        }
        
        for(int i = 0; i < 1000; i++) {
            int mult = ceil((double)count[i] / (i + 1));
            res += mult * (i + 1);
        }
        
        return res;
    }
};
__________________________________________________________________________________________________
sample 8708 kb submission
class Solution {
    static constexpr int N = 1e3 + 5;
    
    int told_left[N];
    
public:
    int numRabbits(vector<int>& answers) {
        int res = 0;
        for (int ans : answers) {
            if (told_left[ans] == 0) {
                res += ans + 1;
                told_left[ans] = ans;
            } else {
                --told_left[ans];
            }
        }
        return res;
    }
};
__________________________________________________________________________________________________
