__________________________________________________________________________________________________
sample 8 ms submission
static auto fast=[]{ios_base::sync_with_stdio(false);cin.tie(nullptr);return 0;}();
struct custom_sort
{
    inline bool operator()(const vector<int> &v1,const vector<int> & v2)
    {
        if(v1[0]<v2[0])
           return true;
        else if(v1[0]>v2[0])
           return false;
        else //if(v1[0]==v2[0])
        {
           if(v1[1]>v2[1])
              return true;
           else //if(v1[1]<v2[1])
              return false; 
        }
    }
};
class Solution 
{
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) 
    {
        int count=0;
        sort(intervals.begin(),intervals.end(),custom_sort());
        count++;
        int start=intervals[0][0];
        int end=intervals[0][1];
        int i=1;
        while(i<intervals.size())
        {
            if(intervals[i][0]>=start&&intervals[i][1]<=end)  //current interval covered by another interval so do nothing
            {}    
            else
            {
                count++;
                start=intervals[i][0];
                end=intervals[i][1];
            }
            i++;
        }
        return count;
    }
};
__________________________________________________________________________________________________
sample 12 ms submission
static auto fast=[]{ios_base::sync_with_stdio(false);cin.tie(nullptr);return 0;}();
struct custom_sort
{
    inline bool operator()(const vector<int> &v1,const vector<int> & v2)
    {
        if(v1[0]<v2[0])
           return true;
        else if(v1[0]>v2[0])
           return false;
        else //if(v1[0]==v2[0])
        {
           if(v1[1]>v2[1])
              return true;
           else //if(v1[1]<v2[1])
              return false; 
        }
    }
};
class Solution 
{
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) 
    {
        int count=0;
        sort(intervals.begin(),intervals.end(),custom_sort());
        count++;
        int start=intervals[0][0];
        int end=intervals[0][1];
        int i=1;
        while(i<intervals.size())
        {
            if(intervals[i][0]>=start&&intervals[i][1]<=end)  //current interval covered by another interval so do nothing
            {}    
            else
            {
                count++;
                start=intervals[i][0];
                end=intervals[i][1];
            }
            i++;
        }
        return count;
    }
};
__________________________________________________________________________________________________
