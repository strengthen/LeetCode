__________________________________________________________________________________________________
sample 32 ms submission
static const auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    static bool interval_compare(const vector <int>& interval_1, const vector <int>& interval_2)
    {
        return interval_1[1] < interval_2[1] || (interval_1[1] == interval_2[1] && interval_1[0] < interval_2[0]);
    }
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), interval_compare);
        int ans = 0, second_last = -1, last = -1;
        for(const auto& interval : intervals)
        {
            if(interval[0] > last)
            {
                last = interval[1];
                second_last = interval[1] - 1;
                ans += 2;
            }
            else if(interval[0] > second_last)
            {
                if(last == interval[1])
                    second_last = interval[1] - 1;
                else
                {              
                    second_last = last;
                    last = interval[1];
                }
                ans++;
            }
        }
        return ans;
    }
};
__________________________________________________________________________________________________
sample 15176 kb submission
class Solution {
public:
  static bool cmp (const vector<int>& a, const vector<int>& b) {
    if (a[1]==b[1])
      return a[0]>b[0];
    else 
      return a[1]<b[1];
  }
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
      int ans=0, p1=-1, p2=-1, N=intervals.size();
      sort(intervals.begin(),intervals.end(),cmp);
      for (int i=0;i<N;i++) {
        if (intervals[i][0]<=p1)
            continue;
        if (intervals[i][0]>p2) {
          ans+=2;
          p2=intervals[i][1];
          p1=p2-1;  
        }  
        else {
          ++ans;
          p1=p2;
          p2=intervals[i][1];  
        }  
      }  
      return ans;
    }
};
__________________________________________________________________________________________________
