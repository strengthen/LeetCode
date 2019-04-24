__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    int addDigits(int num) {
        while(num/10>0) { // at least two digits
            int sum=0;
            while(num>0) {
                sum+=num%10;
                num/=10;
            }
            num=sum;
        }
        return num;
    }
};
__________________________________________________________________________________________________
sample 7972 kb submission
class Solution {
public:
    int addDigits(int num)
    {
         if (num == 0){
            return 0;
        }
        int s = num % 9;
        if(s == 0){
            return 9;
        }else return s;
    }
};
__________________________________________________________________________________________________
