__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    int findComplement(int num) {
        int ans=0,i=0;
        while(num>0)
        {
            if(num%2==0)ans=ans|(1<<i);
            i++;
            num=num/2;
        }
        return ans;
    }
};
__________________________________________________________________________________________________
sample 8772 kb submission
class Solution {
public:
    int findComplement(int num) {
        int total=0,i=0,numt=num;
        while(numt){
            total|=(1<<i);
            i++;
            numt>>=1;
        }
        
        
        return num^total;
    }
};
__________________________________________________________________________________________________
