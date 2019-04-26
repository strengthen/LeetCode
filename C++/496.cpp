__________________________________________________________________________________________________
sample 8 ms submission
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {       
        vector<int> answers;
        if(nums1.size() == 0 || nums2.size() == 0)
            return answers;
        
        //find min and max in num2
        int max = nums2[0];
        for(auto it = nums2.begin(); it != nums2.end(); it++)
        {
            if(*it > max)
                max = *it;
        }

        vector<int> indexVector;
        indexVector.resize(max+1,-1);
       
        //set num2 values in array
        int index = 0;
        for(auto it = nums2.begin(); it != nums2.end(); it++)
        {
            indexVector[*it] = index++;
        }
        
        //find answers
        for(auto it = nums1.begin(); it != nums1.end(); it++)
        {
            bool found = false;
            int index = indexVector[*it];

            for(int i = index+1; i < nums2.size(); i++)
            {
                if(nums2[i] > nums2[index])
                {
                    answers.push_back(nums2[i]);
                    found = true;
                    break;
                }
            }

            if(!found)
            {
                answers.push_back(-1);
            }
        }
        
        return answers;
    }
};
__________________________________________________________________________________________________
sample 8820 kb submission
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        vector<int> ret;

        for(int i = 0; i < findNums.size() ; i ++)
        {
            int idx = find(nums.begin(), nums.end(), findNums[i]) - nums.begin();
            int tmp = -1;
            int j = 1;
            while(idx + j <= nums.size() - 1)
            {
                if(nums[idx+j] > nums[idx])
                {
                    tmp = nums[idx+j];
                    break;
                }
                j++;
            }
            ret.push_back(tmp);
        }
        
        return ret;
    }
};
__________________________________________________________________________________________________
