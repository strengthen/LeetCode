__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    int trailingZeroes(int n) {
     
        
        int count=0;
        long long i=5;
        while(n/i)
        {
            count+=n/i;
            i=i*5;
        }
        
        return count;
        
    }
};
__________________________________________________________________________________________________
sample 8232 kb submission
class Solution {
public:
    int trailingZeroes(int n) {
        if(n<5) return 0;
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int ans = 0;
        for(long i=5 ; i<=n ; i+=5){
            if(i>n) break;
            int temp = i;
            while(temp%5 == 0){
                ans++;
                temp/=5;
            }
        }
        return ans;
    }
};
__________________________________________________________________________________________________
