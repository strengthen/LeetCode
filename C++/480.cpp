__________________________________________________________________________________________________
sample 52 ms submission
static const auto __ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
  vector<double> medianSlidingWindow(vector<int>& nums, int k) {
	int len = nums.size();
	if (len < k || k <= 0) return {};

	vector<double> medians;
	auto ascend_comp =
			  [](const pair<int, int>& e1, const pair<int, int>& e2) {
				return e1.first > e2.first || 
			  (e1.first == e2.first && e1.second > e2.second); 
			  };
	auto descend_comp =
	  [](const pair<int, int>& e1, const pair<int, int>& e2) {
		return e1.first < e2.first || 
						  (e1.first == e2.first && e1.second > e2.second); 
	  };
    std::priority_queue<pair<int, int>,
                        vector<pair<int, int>>,
                        decltype(ascend_comp)> big_queue(ascend_comp);
    std::priority_queue<pair<int, int>,
                        vector<pair<int, int>>,
                        decltype(descend_comp)> small_queue(descend_comp);

	for (int i = 0; i < k; ++i) big_queue.emplace(nums[i], i);
	for (int i = 0; i < k / 2; ++i) {
	  small_queue.push(big_queue.top());
	  big_queue.pop();
	}

	if (k % 2 == 0) {
	  double median = 
		(((double)big_queue.top().first) + small_queue.top().first) / 2;
	  medians.push_back(median);
	} else {
	  medians.push_back(big_queue.top().first);
	}
	for (int i = k; i < len; ++i) {
	  int current = big_queue.top().first;
	  if (i - k == big_queue.top().second) {
		do {
		  big_queue.pop();
		} while (!big_queue.empty() && big_queue.top().second <= i - k);
		if (nums[i] >= current) {
		  big_queue.emplace(nums[i], i);
		} else {
		  small_queue.emplace(nums[i], i);
		  big_queue.push(small_queue.top());
		  do {
			small_queue.pop();
		  } while (!small_queue.empty() && small_queue.top().second <= i - k);
		}
	  } else if (i - k == small_queue.top().second) {
		do {
		  small_queue.pop();
		} while (!small_queue.empty() && small_queue.top().second <= i - k);
		if (nums[i] >= current) {
		  big_queue.emplace(nums[i], i);
		  small_queue.push(big_queue.top());
		  do {
			big_queue.pop();
		  } while (!big_queue.empty() && big_queue.top().second <= i - k);
		} else {
		  small_queue.emplace(nums[i], i);
		}
	  } else {
		if (nums[i - k] > current) {
		  if (nums[i] >= current) {
			big_queue.emplace(nums[i], i);
		  } else {
			small_queue.emplace(nums[i], i);
			big_queue.push(small_queue.top());
			do {
			  small_queue.pop();
			} while (!small_queue.empty() && small_queue.top().second <= i - k);
		  }
		} else {
		  if (nums[i] < current) {
			small_queue.emplace(nums[i], i);
		  } else {
			big_queue.emplace(nums[i], i);
			small_queue.push(big_queue.top());
			do {
			  big_queue.pop();
			} while (!big_queue.empty() && big_queue.top().second <= i - k);
		  }
		}
	  }

	  if (k % 2 == 0) {
		double median = 
		  (((double)big_queue.top().first) + small_queue.top().first) / 2;
		medians.push_back(median);
	  } else {
		medians.push_back(big_queue.top().first);
	  }
	}

	return medians;
  }
};
__________________________________________________________________________________________________
sample 64 ms submission
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
 
        vector<double> res;
        multiset<double> ms(nums.begin(), nums.begin() + k);
        auto mid = next(ms.begin(), k /  2);
        for (int i = k; i < nums.size() ; ++i) {
            res.push_back((*mid + *prev(mid,  1 - k % 2)) / 2);        
            ms.insert(nums[i]);
            if (nums[i] < *mid) --mid;
            if (nums[i - k] <= *mid) ++mid;
            ms.erase(ms.lower_bound(nums[i - k]));
        }
        res.push_back((*mid + *prev(mid,  1 - k % 2)) / 2);
        return res;
        
    }
};
__________________________________________________________________________________________________
sample 12632 kb submission
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        size_t steps = nums.size() - k + 1;
        vector<double> v;
        vector<double> win(k);
        
        for (size_t i = 0; i < steps; ++i) {
            std::copy(nums.begin()+i, nums.begin()+i+k, win.begin());
            std::sort(win.begin(), win.end());
            if (k % 2) {
                v.push_back(win[k/2]);
            } else {
                v.push_back((win[k/2-1]+win[k/2])/2);
            }
        }
        return v;
    }
};