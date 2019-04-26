__________________________________________________________________________________________________
sample 36 ms submission
static const auto __ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
  int findMaximizedCapital(int k, int W, vector<int>& Profits, 
						   vector<int>& Capital) {
	if (k == 0) return 0;
	int len = Capital.size();
	if (len == 0) return 0;

	priority_queue<int> pq;
	int start = 0;
	while (start < len) {
	  int end = partition(Profits, Capital, W, start, len);
	  for (int i = start; i < end; ++i) pq.push(Profits[i]);
	  if (pq.empty()) return W;
	  W += pq.top();
	  pq.pop();
	  start = end;
	  if (--k == 0) break;
	}
	
	while (k-- > 0 && !pq.empty()) {
	  W += pq.top();
	  pq.pop();
	}

	return W;
  }

  int partition(vector<int>& profits, vector<int>& capital, int value, 
				 int start, int end) {
	int small = start - 1;
	int i = start;
	for (int i = start; i < end; ++i) {
	  if (capital[i] <= value) {
		++small;
		if (small != i) {
		  swap(capital[small], capital[i]);
		  swap(profits[small], profits[i]);
		}
	  }
	}

	return small + 1;
  }
};
__________________________________________________________________________________________________
sample 13468 kb submission
class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& profits, vector<int>& capital) {
        priority_queue<int> available_projects;
        
        int N = capital.size();
        vector<pair<int, int>> capital_to_index(N);
        for (int i = 0; i < N; ++i)
            capital_to_index[i] = {capital[i], i};
        
        sort(capital_to_index.begin(), capital_to_index.end());

        int i = 0;
        while (k) {
            while(i < N && capital_to_index[i].first <= W) {
                int proj_index = capital_to_index[i].second;
                available_projects.push(profits[proj_index]);
                ++i;
            }
            
            if (available_projects.empty()) break;
            W += available_projects.top();
            --k;
            available_projects.pop();
        }
        
        return W;
    }
};
__________________________________________________________________________________________________
