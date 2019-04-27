__________________________________________________________________________________________________
sample 172 ms submission
int any = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
	int scheduleCourse(vector<vector<int>> &courses) {
		sort(courses.begin(), courses.end(), [](const vector<int> &lhs, const vector<int> &rhs) {
			return lhs[1] < rhs[1];
		});
		priority_queue<int> taken;
		int days = 0;
		for (const vector<int> &course : courses)
			if (days + course[0] <= course[1]) {
				days += course[0];
				taken.push(course[0]);
			} else if (taken.size() && course[0] < taken.top()) {
				days -= taken.top() - course[0];
				taken.pop();
				taken.push(course[0]);
			}
		return taken.size();
	}
};
__________________________________________________________________________________________________
sample 40196 kb submission
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(),[](const vector<int> &op1,
                const vector<int> &op2) { return op1[1] < op2[1]; });
        priority_queue<int> max_heap;
        int timestamp = 0;
        for(int i = 0; i < (int)courses.size(); i++)
        {
            max_heap.push(courses[i][0]);
            timestamp += courses[i][0];
            if(timestamp > courses[i][1])
                {
                timestamp -= max_heap.top();
                max_heap.pop();
                }
        }
        return max_heap.size();
    }
};
static int fast_io = []() { std::ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
__________________________________________________________________________________________________
