__________________________________________________________________________________________________
class Solution {
public:
    int numDigits(int N) {
        int digits = 0;
        while(N) {
            digits++;
            N/=10;
        }
        return digits;
    }
    
    int getAns(int N, int digits) {
        int f = 0;
        while(N) {
            int l = N%10;
            N/=10;
            f+=pow(l,digits);
        }
        return f;
    }
    
    bool isArmstrong(int N) {
        int digits = numDigits(N);
        int formed  = getAns(N,digits);
        return (N == formed);
    }
};
__________________________________________________________________________________________________
class Solution {
public:
	bool isArmstrong(int N) {
		long long sl = to_string(N).length(), i, j, k, s = 0, x, xx, nn = N;;
		while (N > 0) {
			x = N % 10;
			N /= 10;

			xx = 1;
			for (i = 0; i < sl; i++) xx *= x;
			s += xx;
		}

		return nn == s;
	}
};
__________________________________________________________________________________________________
