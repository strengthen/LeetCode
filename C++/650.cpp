__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    int minSteps(int n) {
	int step = 0;
	if (n == 1)return 0;
	if (n == 2)return 2;
	while (true) {
		int t = get_init(n);
		if (t == -1) {
			step += n;
			break;
		}
		else {
			int z = n / t;
			if (z == 1) {
				step += 2;
				break;
			}
			if (z == 2) {
				step += 2;
			}
			else {
				step = step + z;
			}
			n = t;
		}
	}
	return step;
}
    private:
   int get_init(int n) {
	for (int i = n/2+1; i >=2; i--) {
		if (n % i == 0) {
			return i;
		}
	}
	return -1;
    }
};
__________________________________________________________________________________________________
sample 8720 kb submission
class Solution {
public:
    int minSteps(int n) {
        if (n <= 1)
            return 0;
        for (int i = 2; i <= n; i++) {
            if (n % i == 0) {
                return i + minSteps(n/i);
            }
        }
        return 0;
    }
};
__________________________________________________________________________________________________
