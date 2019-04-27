__________________________________________________________________________________________________
sample 4 ms submission

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int min_v = 0;
        int min_i = 0;
        int max_v = INT_MIN;
        int res = 0;
        bool found_min = false;
        for (int i = 0; i < arr.size(); ++i) {
            if (arr[i] == min_v) {
                found_min = true;
            }
            max_v = max(max_v, arr[i]);
            if (found_min && ((i - min_i) == (max_v - min_v))) {
                res += 1;
                min_v = max_v + 1;
                min_i = i + 1;
                found_min = false;
            }
        }
        return res;
    }
};

__________________________________________________________________________________________________
sample 8340 kb submission
class Solution
{
public:
    int maxChunksToSorted(vector<int>& arr)
    {
        int max_element = 0, index = 0, count = 0;
        while(index < arr.size())
        {
            max_element = max(max_element, arr[index]);            
            
            if(max_element == index++)
                ++count;
        }
        
        return count;
    }
};
__________________________________________________________________________________________________
