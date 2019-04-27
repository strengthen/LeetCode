__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for(int i = left; i <= right; i++) {
            int rem = i;
            while (rem != 0) {
                int digit = rem % 10;
                if (digit == 0 || i % digit != 0) {
                    break;
                }
                else if (rem/10 == 0 && i % rem == 0) {
                    ans.push_back(i);
                }
                rem = rem/10;
            }
            
        }
        return ans;
    }
};
__________________________________________________________________________________________________
sample 8356 kb submission
class Solution {
public:
    bool isSelfDividing (int nr)
    {  int ctr = 1;
        do
        {
            int divisor = nr/ctr%10;
            if (divisor==0 || nr%divisor!=0) return false;
            ctr = ctr*10;
        } while (ctr<nr);
        return true;
    }
    vector<int> selfDividingNumbers(int left, int right) {
      int ctr = left;
        vector <int> v;
        while (ctr<=right)
        {   
            if (isSelfDividing(ctr)) 
                v.push_back(ctr);
            ctr++;
        }
        return v;
    }
};
__________________________________________________________________________________________________
