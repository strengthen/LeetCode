__________________________________________________________________________________________________
sample 68 ms submission
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int result=0;
        sort(people.begin(),people.end());
        int left=0,right=people.size()-1;
        while(people[right]==limit){
            result++;
            right--;
        }
        while(left<right){
            int tmp=people[left]+people[right];
            if(tmp>limit){
                result++;
                right--;
            }else{
                result++;
                right--;
                left++;
            }
        }
        if(left==right)result++;
        return result;
    }
};
static auto speedup = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
__________________________________________________________________________________________________
sample 14016 kb submission
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) 
    {
        int boats = 0;
        sort(people.begin(), people.end());
        int size = people.size();
        for (int i = 0, j = size-1; i <= j; --j)
        {
            if ((people[i] + people[j]) <= limit)
            {
                ++i;
            }
            ++boats;
        }
        
        return boats;
    }
};
__________________________________________________________________________________________________
