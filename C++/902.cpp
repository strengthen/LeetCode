__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& D, int N) {
        vector<int> B;
        for (int n = N; n; n /= 10) B.push_back(n % 10);
        vector<int> cnt;
        for (int i = 0, pow = 1; i < B.size(); i++, pow *= D.size()) {
            cnt.push_back(pow);
            // cout<<i<<" "<<cnt[i]<<endl;
        }
        int res = 0;
        bool iseq = true;
        for (int i = B.size() - 1; iseq && i >= 0; i--) {
            iseq = false;
            for (auto d: D) {
                if (d[0] - '0' < B[i]) res += cnt[i];
                else if (d[0] - '0' == B[i]) {
                    iseq = true;
                    break;
                } else {
                    break;
                }
            }
        }
        if (iseq) res += 1;

        for (int i = 1; i < B.size(); i++) {
            res += cnt[i];
        }
        return res;
    }
};
__________________________________________________________________________________________________
sample 8912 kb submission
class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& D, int N) {
		return helper(D, N, true);
    }  

private:

	int helper(vector<string>& D, int N, bool lessDigits) {
        int digits = get_num_digits(N);
        int ret = 0;
		if ( lessDigits )
			ret += get_all(digits - 1, D.size());
		int scale = my_pow(10, digits - 1);
        int high_digit = N / scale;
        int smaller = get_smalls(D, high_digit);
        if ( smaller )
            ret += smaller * my_pow(D.size(), digits - 1);
		int left = N - high_digit * scale;
        if ( has_digit(D, high_digit) && left >= (scale/10)) {
			if ( digits-1 > 0 )
	            ret += helper(D, left, false);
			else
				ret++;
		}
        return ret;
	}

    static int my_pow(int b, int p) {
        int ret = 1;
        for (int i = 0; i < p; i++)
            ret *= b;
        return ret;
    }
    
    
    static int get_num_digits(int num) {
        string s = to_string(num);
        return s.size();
    }
    
    
    static int get_all(int digits, int size) {
        int total = 0;
        for ( int i = 1; i <= digits; i++ )
            total += my_pow(size, i);
        return total;
    }
    
    static int get_smalls(const vector<string>& D, int num) {
        for ( int i = 0; i < D.size(); i++)
            if ( D[i][0] - '0'  >= num )
                return i;
        return D.size();
    }
    
    static bool has_digit(const vector<string>& D, int num) {
        for (int i = 0; i < D.size(); i++)
            if ( D[i][0] - '0' == num )
                return true;
        return false;
    }
};
__________________________________________________________________________________________________
