__________________________________________________________________________________________________
sample 8 ms submission
class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int keep_1 = INT_MAX;
        int exchange_1 = INT_MAX;
        int keep = INT_MAX;
        int exchange = INT_MAX;
        
        keep_1 = 0;
        exchange_1 = 1;
        
        int pre_a = A[0];
        int pre_b = B[0];

        const int n = A.size();
        for (int i = 1; i < n; i++) {
            keep = exchange = INT_MAX;
            const int a = A[i];
            const int b = B[i];

            if (a > pre_a && b > pre_b) {
                keep = keep_1;
                exchange = exchange_1 + 1;
            }
            
            if (a > pre_b && b > pre_a) {
                keep = min(keep, exchange_1);
                exchange = min(keep_1+1, exchange);
            }
            
            keep_1 = keep;
            exchange_1 = exchange;
            
            pre_a = a;
            pre_b = b;
        }
        
        return min(keep_1, exchange_1);
    }
};
__________________________________________________________________________________________________
sample 9524 kb submission
class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        int swap=1,nonswap=0;//是否swap i
        for(int i=1;i<A.size();i++)
        {
            if(A[i-1]>=B[i]||B[i-1]>=A[i])
            {
                //关于i和i-1的结局，必须是AA挨着，BB挨着，所以对i-1的操作必须和对i的操作一样
                swap++;
      //          cout<<i<<" "<<swap<<" "<<nonswap<<endl;
            }
            else if(A[i-1]>=A[i]||B[i-1]>=B[i])
            {
                //关于i和i-1的结局，必须是AB，AB，所以对i-1的操作必须和对i的操作相反
                int temp=nonswap;
                //如果swap了i-1，就不能swapi
                nonswap=swap;
                //如果没有swap i-1，就必须swapi
                swap=temp+1;
  //              cout<<i<<" "<<swap<<" "<<nonswap<<endl;
            }
            else{
                //max(A[i-1],B[i-1])<min(A[i],B[i])无论是否swap，都不会影响order
                int temp=nonswap;
                nonswap=min(nonswap,swap);
                swap=min(swap,temp)+1;
  //              cout<<i<<" "<<swap<<" "<<nonswap<<endl;
                
            }
        }
        
        
        return min(swap,nonswap);
        
    }
};
__________________________________________________________________________________________________
