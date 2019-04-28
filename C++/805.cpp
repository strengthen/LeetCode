__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    bool dfs(int i, int sumN, int N, vector<int>& A) {
        int n = A.size();
        if(N == 0) return sumN == 0;
        if(A[i] > sumN/N) return false;
        for(int j = i; j < n - N + 1; ++j) {
            if(j > i && A[j] == A[j-1]) continue;
            if(dfs(j+1,sumN-A[j],N-1,A)) return true;
        }
        return false;
    }
    bool splitArraySameAverage(vector<int>& A) {
        int n =A.size(), sum = 0;
        for(auto c : A) sum += c;
        sort(A.begin(),A.end());
        for(int len = 1; len <= n/2; ++len) {
            if(sum * len % n ) continue;
            if(dfs(0,sum*len/n,len,A)) return true;
        }
        return false;
    }
};
__________________________________________________________________________________________________
sample 8756 kb submission
class Solution {
public:
    bool splitArraySameAverage(vector<int>& A) {
        int N = A.size();
        if(N<2) return false;
        int S = accumulate(A.begin(),A.end(),0);
        sort(A.begin(), A.end());
        for(int i = 1; i <= N/2; i++){
            if(i*S%N)
                continue;
            if(dfs(0, i*S/N, i, A))
                return true;
        }
        return false;
    }
    bool dfs(int start, int target, int count, vector<int>& A){
        if(count == 0)
            return target == 0;
        for(int i = start; i < A.size() - count + 1; i++){
            if(i > start && A[i] == A[i-1])
                continue;
            if(dfs(i+1, target - A[i], count - 1, A))
                return true;
        }
        return false;
    }
};
__________________________________________________________________________________________________
