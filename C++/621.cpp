__________________________________________________________________________________________________
sample 12 ms submission
int any = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
	int leastInterval(vector<char> &tasks, int n) {
		if (tasks.empty())
			return 0;
		int count[26] = { 0 };
		for (char l : tasks)
			++count[l - 'A'];
		sort(count, count + 26, greater<int>());
		int interval = (count[0] - 1) * (n + 1) + 1, index = 0;
		for (int i = 1; i < 26; ++i) {
			if (count[i] == 0)
				break;
			if (count[i] == count[0]) {
				++interval;
				--count[i];
			}
			if (n == 0)
				interval += count[i];
			else {
				index += count[i];
				if (index >= count[0] - 1) {
					if (n > 1)
						index -= count[0] - 1;
					else
						interval += index - count[0] + 1;
					--n;
				}
			}
		}
		return interval;
	}
};
__________________________________________________________________________________________________
sample 9636 kb submission
typedef long long int64;
const int INF = 0x3f3f3f3f;
template <class T> inline int len (const T &a) { return a.size (); }

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector <int> dat(26, 0);
        for (char task: tasks) dat [task - 'A']++;
        sort(dat.begin(), dat.end(), greater<int>());
        int ret = 0;
        while (true) {
            bool ok = true;
            int knt = 0;
            for (int i = 0; i < 26; i++)
                if (dat[i]) {
                    dat[i]--;
                    knt++;
                    if (knt == n + 1) break;
                }
            for (int i = 0; i < 26; i++) ok &= (dat[i] == 0);
            if (ok) {
                ret += knt;
                break;
            }
            else ret += max(knt, n + 1);
            sort(dat.begin(), dat.end(), greater<int>());
        }
        return ret;   
    }
};

static int fastio = []() {
    #define endl '\n'
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(0);
    return 0;
}();
__________________________________________________________________________________________________
