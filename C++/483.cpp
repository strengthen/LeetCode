__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    string smallestGoodBase(string n) {
        long num = stol(n);
        for (int i = log(num + 1) / log(2); i >= 2; --i) {
            long left = 2, right = pow(num, 1.0 / (i -1)) + 1;
            while (left < right) {
                long mid = left + (right - left) / 2, sum = 0;
                for (int j = 0; j < i; ++j)
                    sum = sum * mid + 1;
                
                if (sum == num) return to_string(mid);
                if (sum < num) left = mid + 1;
                else right = mid;
            }
        }
        
        return to_string(num - 1);
    }
};
__________________________________________________________________________________________________
sample 8916 kb submission
class Solution {
public:
    long long count(long long N, long long base, int len) {
        long long cur = (long long)1, sum = (long long)1;
        for (int i = 1 ; i <= len ; i++) {
            cur *= base;
            sum += cur;
            if (sum > N)    return N+1;
            // if (base == (long long)496)
            // cout << N << ' ' << i << ' ' << len << ' ' << cur << ' ' << sum << endl;
        }
        return sum;
    }
    long long find(long long N, int len) {
        long long left = (long long)2, right = (long long)pow(N, 1.0/len)+(long long)1;
        // cout << len << "->" << left << "vs" << right << endl;
        while (left <= right) {
            long long mid = (left+right)/(long long)2;
            long long tmp = count(N, mid, len);
            if (tmp == N)   return mid;
            else if (tmp > N)   right = mid-1;
            else    left = mid+1;
        }
        return (long long) 0;
    }
    string smallestGoodBase(string n) {
        long long N = (long long)0;
        for (auto c : n)    N = N*(long long)10 + (long long)(c - '0');
        for (int i = 61 ; i >= 2 ; i--) {
            long long tmp = find(N, i);
            if (tmp > (long long)0) return to_string(tmp);
        }
        return to_string(N-1);
    }
};
__________________________________________________________________________________________________
