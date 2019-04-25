__________________________________________________________________________________________________
sample 28 ms submission
static const int _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
  
  bool isPowerOfThree(int Num) {
  constexpr int MaxInt = std::numeric_limits<int>::max();
  constexpr int MaxPowerOfThree =
      std::pow(3, int(std::log10(MaxInt) / std::log10(3)));
  return Num > 0 && 1162261467 % Num == 0;
}
  
};
__________________________________________________________________________________________________
sample 7844 kb submission
class Solution {
public:
    bool isPowerOfThree(int n) {
        return n == 1 || (n > 2 && !(1162261467%n));
    }
};
__________________________________________________________________________________________________
