__________________________________________________________________________________________________
class Solution {
public:
    vector<Interval> intervalIntersection(vector<Interval>& A, vector<Interval>& B) {
        vector<Interval> merged;
        for(int i = 0, j = 0; i < A.size() || j < B.size();){
            if( (i < A.size() && j < B.size() && A[i].start < B[j].start) || j >= B.size()) merged.push_back(A[i++]);
            else merged.push_back(B[j++]);
        }
        vector<Interval> ans;
        if(!merged.size()) return {};
        int end = merged[0].end;
        for(int i = 1; i < merged.size(); i++){
            if(merged[i].start <= end) ans.push_back(Interval(merged[i].start, min(merged[i].end,end)));
            end = max(merged[i].end, end);
        }
        return ans;
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    vector<Interval> intervalIntersection(vector<Interval>& A, vector<Interval>& B) {
  vector<Interval> res;
  for (auto i = 0, j = 0; i < A.size() && j < B.size(); ) {
    if (A[i].end < B[j].start) ++i;
    else if (B[j].end < A[i].start) ++j;
    else {
      res.push_back({ max(A[i].start, B[j].start), min(A[i].end, B[j].end) });
      if (A[i].end < B[j].end) ++i;
      else ++j;
    }
  }
  return res;
  }
};
__________________________________________________________________________________________________
