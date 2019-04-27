__________________________________________________________________________________________________
sample 16 ms submission
int any = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
	vector<int> exclusiveTime(int n, vector<string> &logs) {
		vector<int> time(n, 0);
		stack<int> functions;
		int prev = 0, current = 0;
		for (string &log : logs) {
			int index = log.find(':'), id = stoi(log.substr(0, index));
			index = log.find(':', index + 1);
			current = stoi(log.substr(index + 1));
			if (log[index - 1] == 't') {
				if (functions.size())
					time[functions.top()] += current - prev;
				functions.push(id);
			} else {
				++current;
				time[functions.top()] += current - prev;
				functions.pop();
			}
			prev = current;
		}
		return time;
	}
};
__________________________________________________________________________________________________
sample 11480 kb submission
template <class T> inline int toInt (const T& t) { int n; stringstream ss; ss << t; ss >> n; return n; }

class Solution {
public:
    pair <string, pair <int, int> >
    helper(string s) {
        int index = 0, work = 0, k = 0, N = s.size();
        string key = "start";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'd') key = "end";
            if (s[i] == ':') {
                if (k == 0) {
                    index = toInt(s.substr(0, i));
                    k = i;
                } else {
                    work = toInt(s.substr(i + 1, N - i));
                }
            }
        }
        return make_pair(key, make_pair(index, work));
    }
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector <int> ret(n, 0);
        stack <int> st;
        int prevTime = 0;
        for (string log: logs) {
            pair <string, pair <int, int> > p = helper(log);
            // cout << p.first << " " << p.second.first << " " << p.second.second << endl;
            if (!st.empty()) ret[st.top()] += p.second.second - prevTime;
            prevTime = p.second.second;
            if (p.first == "start") st.push(p.second.first);
            else {
                ret[st.top()]++;
                st.pop();
                prevTime++;
            }
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
