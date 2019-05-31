__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public int addDigits(int num) {
        while(num>=10){
             num=(num-1)%9+1;
        }
        return num;
    }
}
__________________________________________________________________________________________________
sample 32080 kb submission
class Solution {
    public int addDigits(int num) {
        int a;
        while(num>9){
            a=0;
            while(num>0){
                a+=num%10;
                num=num/10;
            }
            num=a;
        }
        return num;
    }
}
__________________________________________________________________________________________________
