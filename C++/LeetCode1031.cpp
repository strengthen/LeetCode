__________________________________________________________________________________________________
8ms
class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        vector<int> ll, lr, ml, mr;
        int sum = accumulate(A.begin(), A.begin() + L, 0), max = sum;
        ll.push_back(max);
        for (int i = L; i < A.size() - M; i++) {
            sum += A[i];
            sum -= A[i - L];
            max = max > sum ? max : sum;
            ll.push_back(max);
        }
        sum = accumulate(A.end() - L, A.end(), 0);
        max = sum;
        lr.push_back(max);
        for (int i = A.size() - L - 1; i >= M; i--) {
            sum += A[i];
            sum -= A[i + L];
            max = max > sum ? max : sum;
            lr.push_back(max);
        }
        sum = accumulate(A.begin(), A.begin() + M, 0);
        max = sum;
        ml.push_back(max);
        for (int i = M; i < A.size() - L; i++) {
            sum += A[i];
            sum -= A[i - M];
            max = max > sum ? max : sum;
            ml.push_back(max);
        }
        sum = accumulate(A.end() - M, A.end(), 0);
        max = sum;
        mr.push_back(max);
        for (int i = A.size() - M - 1; i >= L; i--) {
            sum += A[i];
            sum -= A[i + M];
            max = max > sum ? max : sum;
            mr.push_back(max);
        }
        int res = 0;
        for (int i = 0; i < ll.size(); i++) {
            int temp = ll[i] + mr[ll.size() - 1 - i];
            res = res > temp ? res : temp;
        }
        for (int i = 0; i < lr.size(); i++) {
            int temp = lr[i] + ml[lr.size() - 1 - i];
            res = res > temp ? res : temp;
        }
        return res;
    }
};
__________________________________________________________________________________________________
12ms
class Solution {
private:
    int prefix[1005], maxLbefore[1005], maxLafter[1005], maxMbefore[1005], maxMafter[1005];
    int get(int l, int r) {
        int ans = prefix[r];
        if (l > 0) ans -= prefix[l - 1];
        return ans;
    }
    
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        int n = A.size();
        for (int i = 0; i < n; i++) {
            prefix[i] = i == 0 ? 0 : prefix[i-1];
            prefix[i] += A[i];
        }
        // <=
        for (int i = 0; i < n; i++) {
            maxLbefore[i] = i == 0 ? -1 : maxLbefore[i-1];
            if (i >= L - 1)
                maxLbefore[i] = max(maxLbefore[i], get(i - L + 1, i));
            maxMbefore[i] = i == 0 ? -1 : maxMbefore[i-1];
            if (i >= M - 1)
                maxMbefore[i] = max(maxMbefore[i], get(i - M + 1, i));
        }
        // >=
        for (int i = n - 1; i >= 0; i--) {
            maxLafter[i] = i == n - 1 ? -1 : maxLafter[i+1];
            if (i + L <= n)
                maxLafter[i] = max(maxLafter[i], get(i, i + L - 1));
            maxMafter[i] = i == n - 1 ? -1 : maxMafter[i+1];
            if (i + M <= n)
                maxMafter[i] = max(maxMafter[i], get(i, i + M - 1));
        }
        int ans = 0;
        for (int i = 0; i < n - 1; i++) {
            // cout << i << ' ' << maxLbefore[i] << ' ' << maxMbefore[i] << ' ' << maxMafter[i + 1] << ' ' << maxLafter[i + 1] << endl;
            ans = max(ans, maxLbefore[i] + maxMafter[i + 1]);
            ans = max(ans, maxMbefore[i] + maxLafter[i + 1]);
        }
        return ans;
    }
};
__________________________________________________________________________________________________
16ms
class Solution {
    typedef long long ll;
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        int N = A.size();
        vector<ll> sum(N+1, 0);
        for (int i=0; i<N; i++) sum[i+1] = sum[i] + A[i];
        ll v = INT_MIN;
        for (int i=0; i+L<=N; i++) {
            ll vm = INT_MIN;
            for (int j=0; j+M<=i; j++) vm = max(vm, sum[j+M]-sum[j]);
            for (int j=i+L; j+M<=N; j++) vm = max(vm, sum[j+M]-sum[j]);
            v = max(v, vm+sum[i+L]-sum[i]);
        }
        return v;
    }
};
__________________________________________________________________________________________________

__________________________________________________________________________________________________

__________________________________________________________________________________________________