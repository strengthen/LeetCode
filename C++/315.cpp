__________________________________________________________________________________________________
sample 20 ms submission
template <typename T> inline T safe_cast(size_t size) {
  assert(size <= static_cast<size_t>((std::numeric_limits<T>::max)()));
  return static_cast<T>(size);
}

static const int _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
  
// A binary index tree with value type T and index type U.
template <typename T, typename U = long long> class BinaryIndexTree {
  static_assert(std::numeric_limits<U>::is_integer);

public:
  // Create a BIT for range [1, Size] with initial value Val.
  BinaryIndexTree(U Size, T Val) : Size(Size), RangeSums(Size, Val) {}

  // \return Range sum of [1, Idx].
  int get(U Idx) {
    U Sum = 0;
    while (Idx > 0) {
      Sum += RangeSums[Idx - 1];
      Idx -= Idx & (~Idx + 1);
    }
    return Sum;
  }

  // Increase value at Idx by one and update all super ranges.
  void update(U Idx) {
    while (Idx - 1 < Size) {
      RangeSums[Idx - 1]++;
      Idx += Idx & (~Idx + 1);
    }
  }

private:
  // Size of the range covered by this BIT.
  U Size;

  // The sum of elements in range [x - lowerbit(x) + 1, x].
  std::vector<T> RangeSums;
};

std::vector<int> countSmaller(std::vector<int> &Nums) {
  // Handle corner cases.
  const auto N = safe_cast<int>(Nums.size());
  if (N < 1)
    return {};

  // Shift the values to [2, inf] since binary index tree must operate on
  // index >= 1 and we would query [1, Nums[i] - 1].
  std::vector<long long> ShiftNums;
  long long MinNum = *std::min_element(Nums.begin(), Nums.end());
  long long MaxNum = std::numeric_limits<long long>::min();
  for (long long Num : Nums) {
    ShiftNums.push_back(Num - MinNum + 2);
    MaxNum = std::max(MaxNum, ShiftNums.back());
  }

  // Hold the number of elements in each range [1, i <= MaxNum].
  BinaryIndexTree<int> BIT(MaxNum, 0);

  // Counts[i] = number of elements in range [1, ShiftNums[i] - 1].
  std::vector<int> SmallerCnts(N, 0);
  for (int i = N - 1; i >= 0; --i) {
    SmallerCnts[i] = BIT.get(ShiftNums[i] - 1);
    BIT.update(ShiftNums[i]);
  }
  return SmallerCnts;
}
  
};
__________________________________________________________________________________________________
sample 9656 kb submission
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> ret(n);
        for ( int i=0; i<n ;i++ ) {
            int k = 0;
            for ( int j=i+1; j<n; j++ ) {
                if ( nums[j] < nums[i] ) k++;
            }
            ret[i] = k;
        }
        return ret;
    }
};
__________________________________________________________________________________________________
