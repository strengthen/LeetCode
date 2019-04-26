__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    bool checkPerfectNumber(int num) {
        
        if(num==1)
            return false;
        int sum = 1 ;
        
        for(int i=2;i*i<num;i++)
        {
            if(num%i==0)
            {
                sum = sum + i + (num/i);
            }
        }
        
        if(sum==num)
            return true;
        return false;
    }
};
__________________________________________________________________________________________________
sample 8368 kb submission
class Solution {
public:
    bool checkPerfectNumber(int num) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        if(num==1) return false;
        int sq = sqrt(num);
        int ans = 1;
        for(int i=2 ; i<=sq ; i++){
            if(num%i==0){
                ans+=i+num/i;
            }
        }
        return ans==num?true:false;
    }
};
__________________________________________________________________________________________________
