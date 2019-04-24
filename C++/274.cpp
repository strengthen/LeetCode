__________________________________________________________________________________________________
sample 4 ms submission
class Solution 
{
public:
int hIndex(vector<int>& citations)
    {
        if (citations.empty())
        {
            return 0;
        }

        priority_queue<int> heap;
        for (int citation : citations)
        {
            heap.push(citation);
        }
        
        int hindex = 0;
        while (hindex < heap.top())
        {
            ++hindex;

            heap.pop();
            if (heap.empty())
            {
                break;
            }
        }
        
        return hindex;
    }
};
__________________________________________________________________________________________________
sample 9156 kb submission
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int size = citations.size();
        for(int i=size;i>=0;i--)
        {
            int count = 0;
            for(int j=0;j<size;j++)
            {
                if(citations[j]>=i)
                    count++;
            }
            if(count>=i)
                return i;
                
        }
        return 0;
        
    }
};
__________________________________________________________________________________________________
