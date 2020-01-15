__________________________________________________________________________________________________
sample 56 ms submission
int a[100000];

static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        if(nums.size()%k) return false;
        memset(a,0,k*4);
        int roll=k,now=-1,all=0,need=0;
        for(auto num:nums){
            if(num==now){
                --need;
            }else{
                if(need>0) return false;
                all+=(a[(roll-1)%k]=-need)-a[roll%k];
                a[roll%k]=0;
                need=all;
                ++roll;
                if(num!=now+1&&need) return false;
                --need;
                now=num;
            }
        }
        return true;
    }
};

__________________________________________________________________________________________________
sample 60 ms submission
[[maybe_unused]] static auto const fast = []{return ios_base::sync_with_stdio(false);}();

inline
namespace leetcode100ms
{
 struct a_counted_value
 {
  int value;
  int count;

  auto totuple () const
  {
   return tie(value,count);
  }

  a_counted_value (int value, int count)
  : value(value)
  , count(count)
  {
  }
 }; // counted_value

 struct a_solution
 {
  vector<a_counted_value> values;
  int const k;

  auto totuple () const
  {
   return tie(values,k);
  }

  a_solution (vector<int>const& values, int const k) : k(k)
  {
   for (auto&& value : values)
   {
    if (this->values.size() && this->values.back().value == value)
    {
     ++this->values.back().count;
    }
    else
    {
     this->values.emplace_back(value,1);
    }
   }
  }

  bool solve ()
  {
   for (auto [index,N] = tuple(0,values.size()); index < N;)
   {
    if (index+k > N)
    {
     return false;
    }
    for (auto i = 0; i < k; ++i)
    {
     if (i > 0 && values[index+i].value != values[index+i-1].value+1)
     {
      return false;
     }
     if (--values[index+i].count < 0)
     {
      return false;
     }
    }
    while (index<N && values[index].count == 0) { ++index; }
   }
   return true;
  }
 }; // solution

 struct Solution
 {
  bool isPossibleDivide (vector<int>& values, int const k)
  {
   if (values.size()%k) { return false; }
   sort(values.begin(),values.end());
   return a_solution{values,k}.solve();
  }
 };
} 
__________________________________________________________________________________________________
