__________________________________________________________________________________________________
sample 68 ms submission
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res(n);
        int cur = 1;
        for (int i = 0; i < n; i++) 
        {
            res[i] = cur;
            if (cur * 10 <= n) 
            {
                cur *= 10;
            } else {
                if (cur == n) 
                    cur /= 10;
                cur += 1;
                while (cur % 10 == 0)
                    cur /= 10;
            }
        }
        return res;
    }
};
__________________________________________________________________________________________________
sample 11136 kb submission
class Solution {
public:
    vector<int> lexicalOrder(int n) {
       	vector<int> ret(n);
	int value = 1;

	for (int i = 0; i < n; i++) {
		ret[i] = value;
		if (value * 10 <= n)
			value *= 10;
		else {
			if (value >= n)
				value /= 10;
			value++;
			while (value % 10 == 0)
				value /= 10;
		}
	}
        return ret;
    }
};
__________________________________________________________________________________________________
