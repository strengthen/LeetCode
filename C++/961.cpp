__________________________________________________________________________________________________
sample 16 ms submission
class Solution {
public:
  int repeatedNTimes(vector<int>& A) {
    unordered_map<int,int> elements;
    int N = A.size()/2;
    for( int element: A ) {
      int currCount = (elements[element] += 1);

      if( currCount > 1 )
        return element;
    }
    return -1;
  }
};

static auto io = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
__________________________________________________________________________________________________
sample 20 ms submission
static auto io = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution 
{
    array<uint8_t, 10000> nums;
public:
    int repeatedNTimes(const vector<int>& A) 
    {
        nums.fill(0);
        for (const auto& num : A)
        {
            if (nums[num] == 1)
                return num;
            else
                ++nums[num];
        }
        return 0;
    }
};
__________________________________________________________________________________________________
