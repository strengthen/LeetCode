__________________________________________________________________________________________________
sample 44 ms submission
static int fast = []{
   ios::sync_with_stdio(0);
   cin.tie(0);
   return 0;
}();

class Solution {
public:

// -50000 <= A[i] <= 50000

       vector<int> sortArray(vector<int>& nums) {
      int n = nums.size();
      int minEl = nums[0], maxEl = nums[0];
      for (int i = 1; i < n; ++i) {
         if (minEl > nums[i]) minEl = nums[i];
         if (maxEl < nums[i]) maxEl = nums[i];
      }
      vector<int> C(maxEl - minEl + 1);
      for (int i : nums) ++C[i-minEl];
      int j = 0;
      for (int i = 0; i < C.size(); ++i) {
         int el = i + minEl;
         int &cnt = C[i];
         while (cnt--) nums[j++] = el;
      }
      return nums;
    }
};
__________________________________________________________________________________________________
sample 48 ms submission
#pragma GCC optimize("Ofast")
__attribute__((constructor)) void _() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cerr.tie(nullptr);
}
class Solution {
public:
  static vector<int> sortArray(vector<int>& nums) noexcept {
      int16_t _arr[100001] = {0};
      int16_t *arr  = _arr + 50000;
      int min = 50000, max  = -50000;
      for (const auto &n : nums){
          min = std::min(min, n);
          max = std::max(max, n);
          ++arr[n];
      }
     int i = 0;
     for (; min <= max; ++min){
        while (arr[min] > 0){
          --arr[min];
            nums[i++] = min;
         }
      }
      return nums;
    }
};

__________________________________________________________________________________________________
