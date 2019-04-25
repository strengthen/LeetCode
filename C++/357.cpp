__________________________________________________________________________________________________
× Close
sample 0 ms submission
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        if (n == 1) return 10;
        int val = 9, ans = 10;
        for (int i = 2; i <= n; ++i) {
            val *= 11 - i;
            ans += val;
        }
        return ans;
    }
};
__________________________________________________________________________________________________
sample 8008 kb submission
class Solution {
public:
    
    int getNum(int num){
        if(num == 0){
            return 1;
        }else if(num == 1){
            return 9;
        }
        
        int result = 9;
        int count = 9;
        for(int d = 2; d <= num; d++){
            result *= (count--);
        }
        return result;
    }
    
    int countNumbersWithUniqueDigits(int n) {
        int result = 0;
        for(int d = 0; d <= n; d++){
            result += getNum(d);
        }
        return result;
    }
};
__________________________________________________________________________________________________
