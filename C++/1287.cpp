__________________________________________________________________________________________________
sample 0 ms submission
[[maybe_unused]] static auto const fast = []{return ios_base::sync_with_stdio(false);}();

inline
namespace leetcode0ms
{
 struct Solution
 {
  int findSpecialInteger (vector<int>const& values)
  {
   auto const n = values.size();
   for (int i = 0; i < 4; i++)
   {
    auto const value = values[i*n/4];
    auto const [lo,hi] = equal_range(begin(values),end(values),value);
    if (distance(lo,hi) > n/4)
    {
     return value;
    }
   }
   throw "control should never reach here";
  }
 };
}
__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    Solution(){
        ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
    }
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        for (int i : {n/4, n/2, n*3/4}) {
            auto p = equal_range(arr.begin(), arr.end(), arr[i]);
            if (p.second - p.first > n / 4)
                return arr[i];
        }
        return 0;
    }
};
__________________________________________________________________________________________________
