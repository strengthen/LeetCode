__________________________________________________________________________________________________
8ms
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int Target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        int length_i = nums.size() - 3;
        if(length_i < 1){
            return result;
        }
        int length_ii = length_i + 1;
        int last = INT_MAX;
        int a = Target - nums[length_i] - nums[length_ii] - nums[length_ii + 1];
        for(int i=0; i<length_i; i++){
            if(nums[i]==last || nums[i] < a) 
                continue;
            if(nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > Target) 
                break;
            last = nums[i];
            int target = Target - last;
            int b = target - nums[length_ii] - nums[length_ii + 1];
            int last2 = INT_MAX;
            for(int ii = i+1; ii < length_ii; ii++){
                if(nums[ii] == last2 || nums[ii] < b)
                    continue;
                if(nums[ii] + nums[ii+1] + nums[ii+2] > target)
                    break;
                last2 = nums[ii];
                int target2 = target - last2;
                int j = ii + 1, k = length_ii + 1;
                while(j<k){
                    int temp = nums[j] + nums[k] - target2;
                    //cout<<target2<<" "<<nums[i]<<" "<<nums[ii]<<nums[j]<<" "<<nums[k]<<endl;
                    if(temp < 0){
                        j++;
                    }
                    else if(temp == 0){
                        result.push_back(vector<int>({nums[i],nums[ii],nums[j],nums[k]}));
                        while(j<k && nums[j]==nums[j+1]) j++;
                        while(j<k && nums[k]==nums[k-1]) k--;
                        j++; k--;
                    }
                    else{
                        k--;
                    }
                }
            }
        }
        return result;
    }
};
__________________________________________________________________________________________________
12ms
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
vector<vector<int>> res;
    std::sort(nums.begin(),nums.end());
    size_t size = nums.size();
    int front, back;
    
    for (int i =0; i < size; i++){
        if (i+3 >= size || i+2 >= size || i+1>=size){
            break;
        }
        if (nums[i] + nums[i+1]+nums[i+2]+nums[i+3] > target)break;
        if (nums[i] + nums[size-1]+nums[size-2]+nums[size-3] < target)continue;
        for (int j = i+1; j < size; j++){
            if (j+1>=size || j+2 >= size){
                break;
            }
            int target2nums = target - nums[i] - nums[j];
            front = j+1; //3rd num index
            back = size -1; // 4th num index
            if (nums[i] + nums[j] + nums[j+1] + nums[j+2] > target)break;
            if (nums[i] + nums[j] + nums[size-1] + nums[size-2] < target)continue;
            while (front < back){//ensure not out of index!
                if (nums[front] + nums[back] < target2nums){
                    front++;
                }else if (nums[front] + nums[back] > target2nums){
                    back--;

                }else{
                    res.push_back({nums[i],nums[j],nums[front],nums[back]});
                    std::cout << "push_back" << std::endl;
                    while (front < back && nums[front+1] == nums[front]){front++;}
                    while (front < back && nums[back-1] == nums[back]){back--;}
                    front++;
                    back--;
                }
            }
            //no dup
            while (j+1<size && nums[j+1] == nums[j]){j++;}
        }

        while (i+1<size && nums[i+1] == nums[i]){i++;}
    }

    return res;
    }
};
__________________________________________________________________________________________________
20ms
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
int i, j, x, y;
int size = nums.size();
int target3, target2, sum;
vector<vector<int>> res;

    sort(nums.begin(), nums.end());

    for (i = 0; i < size - 3; i++)
    {
        if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target)
            return res;
        if(nums[i]+nums[nums.size()-3]+nums[nums.size()-2]+nums[nums.size()-1]<target) continue;
        target3 = target - nums[i];
        for (j = i + 1; j < size - 2; j++)
        {
            if (nums[j] + nums[j + 1] + nums[j + 2] > target3)
                break;
            if(nums[i]+nums[j]+nums[nums.size()-2]+nums[nums.size()-1]<target) continue;
            target2 = target3 - nums[j];
            x = j + 1;
            y = size - 1;
            while (x < y)
            {
                if (nums[x] + nums[x + 1] > target2)
                    break;
                sum = nums[x] + nums[y];
                if (sum > target2)
                {
                    y--;
                }
                else if (sum < target2)
                {
                    x++;
                }
                else
                {
                    res.push_back({nums[i], nums[j], nums[x], nums[y]});
                    while (x < y && nums[x + 1] == nums[x])
                        x++;
                    x++;
                    while (x < y && nums[y - 1] == nums[y])
                        y--;
                    y--;
                }
            }
            while (j < size - 3 && nums[j + 1] == nums[j])
                j++;
        }
        while (i < size - 4 && nums[i + 1] == nums[i])
            i++;
    }

    return res;        
    }
};
__________________________________________________________________________________________________
10424 kb
class Solution {
private:
    int next_forward(vector<int>& nums, const int now,int i, const int max_i){
        while(i<max_i && nums[i]==now)
            ++i;
        return i;
    };
    
    int next_backward(vector<int>& nums, const int now,int i, const int min_i){
        while(i>min_i && nums[i]==now)
            --i;
        return i;
    };
    
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        //NlogN?
        vector<int> sorted_nums = nums;
        sort(sorted_nums.begin(), sorted_nums.end());
        
        vector<vector<int> > v_answer;
        const int len=sorted_nums.size();
        
        int i=0;
        while(i<(len-3)){
            int a1 = sorted_nums[i];
            int j = i+1;
            while(j<(len-2)){
                int a2 = sorted_nums[j];
                int k=j+1, l=len-1;
                // a1 + a2 + (aim) = target;
                // aim = target - (a1+a2)
                int aim = target - (a1+a2);
                while(k<l){
                    int a3 = sorted_nums[k];
                    int a4 = sorted_nums[l];
                    int a34 = a3 + a4;
                    if(a34==aim){
                        v_answer.push_back(vector<int>{a1,a2,a3,a4});
                        k = next_forward(sorted_nums, a3, k, l);
                        l = next_backward(sorted_nums, a4, l, k);
                    }
                    else if(a34 < aim)
                        k = next_forward(sorted_nums, a3, k, l);
                    else 
                        l = next_backward(sorted_nums, a4, l, k);
                        
                }
                j = next_forward(sorted_nums, a2, j, len-2);
            }
            
            //++i when next is same
            i = next_forward(sorted_nums, a1, i, len-3);
        }
        
        return v_answer;
    }
};
__________________________________________________________________________________________________
10452 kb 
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int k,l;
        
        if(nums.size() < 4)
            return res;
        
        sort(nums.begin(),nums.end());
        for(int i=0; i<nums.size()-3; i++) {
            for(int j=i+1; j<nums.size()-2; j++) {
                k = j+1; l=nums.size()-1;
                while(k<l) {
                    if(nums[i]+nums[j]+nums[k]+nums[l] == target) {
                        res.push_back(vector<int>{nums[i],nums[j],nums[k],nums[l]});
                        while(k<l && nums[k] == nums[k+1]) k++;
                        while(k<l && nums[l] == nums[l-1]) l--;
                        k++;
                        l--;
                    }
                    else if(nums[i]+nums[j]+nums[k]+nums[l] > target)
                        l--;
                    else
                        k++;
                }
                
                while(j<nums.size()-2 && nums[j] == nums[j+1]) j++;
            }
            
            while(i<nums.size()-3 && nums[i] == nums[i+1]) i++;
        }
        
        return res;
    }
};
__________________________________________________________________________________________________
