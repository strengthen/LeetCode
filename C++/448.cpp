__________________________________________________________________________________________________
sample 72 ms submission
template <typename T> inline T safe_cast(size_t size) {
  assert(size <= static_cast<size_t>((std::numeric_limits<T>::max)()));
  return static_cast<T>(size);
}

static const int _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
  std::vector<int> findDisappearedNumbers(std::vector<int>& Nums) {
    const auto N = safe_cast<int>(Nums.size());
    for (const int Num : Nums) {
      const int Idx = std::abs(Num) - 1;
      Nums[Idx] = Nums[Idx] > 0 ? -Nums[Idx] : Nums[Idx];
    }
     
    std::vector<int> LostNums;
    for (int Idx = 0; Idx < N; ++Idx) {
      if (Nums[Idx] > 0)
        LostNums.push_back(Idx + 1);
    }
    
    return LostNums;
  }
};
__________________________________________________________________________________________________
sample 14856 kb submission
static const auto __ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
  vector<int> findDisappearedNumbers(vector<int>& nums) {
	int len = nums.size();
	vector<int> result;
	if (len == 0) return result;

	int i = 0;
	while (i < len) {
	  if (nums[i] == i + 1 || nums[nums[i] - 1] == nums[i]) ++i;
	  else swap(nums[i], nums[nums[i] - 1]);
	}

	for (int i = 0; i < len; ++i) 
	  if (nums[i] != i + 1) result.push_back(i + 1);

	return result;
  }
};
__________________________________________________________________________________________________
