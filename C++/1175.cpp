__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
public:
    
    int64_t permutations(int a) {

        int64_t result = 1;
        for(int64_t i = 2; i <= a; i++) {
            result = (result * i) % 1000000007;
        }
        return result;
    }
    
    bool prime(int n) {
        if(n <= 1) return false;
        if(n <= 3) return true;
        for(int i = 2; i <= sqrt(n); i++) {
            if(n % i == 0) return false;
        }
        return true;
    }
    
    int numPrimeArrangements(int n) {
        
        int primes = 0;
        for(int i = 1; i <= n; i++) {
            if (prime(i)) primes++;
        }
        
        int64_t a = (permutations(primes) % 1000000007) * (permutations(n - primes) % 1000000007);
        
        return a % 1000000007;
    }
};
__________________________________________________________________________________________________
0ms
class Solution {
    const int MOD = 1000000000 + 7;
    int getPrime(int n){
        int num = 0;
        for(int i=2;i<=n;i++){
            bool is = true;
            for(int j=2;j<i;j++){
                if(i%j == 0){
                    is = false;
                    break;
                }
            }
            if(is)num++;
        }
        return num;
    }
    long long jiecheng(int n){
        if(n<=1)return 1;
        long long ans = 1;
        while(n>0){
            ans = ans * n % MOD;
            n--;
        }
        return ans;
    }
public:
    int numPrimeArrangements(int n) {
        if(n==1 || n == 2)return 1;
        int x = getPrime(n);
        return jiecheng(x) * jiecheng(n - x) % MOD;
    }
};
__________________________________________________________________________________________________
