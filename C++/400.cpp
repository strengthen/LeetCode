__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    int findNthDigit(int n) {
        long base = 9;
        long digit = 1;
        if(n<=9)
            return n;
        while(n>base*digit){
            n-=base*digit;
            base*=10;
            digit++;
        }
        n--;
        int index = n/digit;
        int offset = n%digit;
        int num =1;
        for(int i =1;i<digit;i++){
            num*=10;
        }
        int basenum = num;
        num+=index;
        int res =0;
        for(int i =0;i<=offset;i++){
            res = num/basenum;
            num= num% basenum;
            basenum= basenum/10;
        }
        return res;
    }
};
__________________________________________________________________________________________________
sample 8396 kb submission
class Solution {
public:
    int findNthDigit(int n) {
        long long target = n;
        long long next_num = 1;
        long long c = 0;
        int d = 1; 
                for (;c + d*(next_num * 9) < target; d++) {
                    c +=  d*(next_num * 9) ;
            next_num *= 10;
                }
            int q = (target - c) / d;
            int r =  (target - c) % d;
            if (r == 0) {
            return (next_num -1 + q)%10;
            } else {
                int tmp = next_num + q;
                while (d > r) { 
            tmp /=10;	
            d --;
            }
            return tmp%10;
            }
            return 0;
        }
};
__________________________________________________________________________________________________
