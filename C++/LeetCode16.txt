__________________________________________________________________________________________________
8ms
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int diff = INT_MAX;
        int ans = 0;
        bool flag = true;
        if(target < 0){
            flag = false;
        }
        for(int i = 0; i < n; i++){
            int j = i+1, k = n-1;
            while(j<k){
                int a = nums[i] + nums[j] + nums[k];
                if(a == target){
                    return a;
                }
                
                    if(diff  > abs(target - a)){
                    ans = a;
                    diff = abs(target - a);
                }    

                if(a > target){
                    k--;
                    continue;
                }       
                if(a < target){
                    j++;
                    continue;
                }
                
            }
        }
        return ans;
    }
};
__________________________________________________________________________________________________
12ms
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closest;
        int size = nums.size();
        if (size < 3)
            return 0;
        closest = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        for (int i = 0; i < size - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            else if (nums[i] + nums[i + 1] + nums[i + 2] >= target) {
                int sum = nums[i] + nums[i + 1] + nums[i + 2];
                if (abs(sum - target) < abs(closest - target))
                    closest = sum;
                break;
            }
            //} else if(nums[i] + nums[size - 2] + nums[size - 1] < 0) {
                
            //    continue;
            //}
            
            int j = i + 1, k = size - 1;
			while(j < k) {
                int sum = nums[i] + nums[j] + nums[k];
				if (sum - target > 0) {
                    if (abs(sum - target) < abs(closest - target))
                        closest = nums[i] + nums[j] + nums[k];
                    --k;
                } else if (sum - target < 0) {
                    if (abs(sum - target) < abs(closest - target))
                        closest = nums[i] + nums[j] + nums[k];
                    ++j;
                } else {
                    //cout<<nums[i]<<nums[j]<<nums[k]<<endl;
                    return target;
					//vec.push_back({nums[i], nums[j], nums[k]});
					do {
                        ++j; 
                    } while (nums[j] == nums[j-1] && j < k);
					do{
                        --k; 
                    } while (nums[k] == nums[k+1] && j < k);
				}
			}
        }
        return closest;
    }    
};
__________________________________________________________________________________________________
20ms
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.empty()||nums.size()<3)return NULL;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        
        if(target>0&&nums.back()<0)return nums[n-1]+nums[n-2]+nums[n-3];
        else if(target<0&&nums.front()>0)return nums[0]+nums[1]+nums[2];
        
        int cur=0,left=cur+1,right=n-1,res=nums[left]+nums[right]+nums[cur];
        for(cur=0;cur<n-2;++cur){
            left=cur+1;
            right=n-1;
            while(left<right){
                int tmp=nums[left]+nums[right]+nums[cur];
                res= abs(res-target)>abs(tmp-target)?tmp:res;
                if(target<tmp)
                    --right;
                else if(target>tmp)
                    ++left;
                else if(target==tmp)
                    return res;
            }
        }
        return res;
    }
};
__________________________________________________________________________________________________
8620 kb
static bool     _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);

class Solution 
{
public:
    int threeSumClosest(vector<int>& num, int t) 
    {
        if(num.size()<3)
            return 123;
        else if(num.size()==3)
            return num[0]+num[1]+num[2];
        std::sort(num.begin(), num.end());
        int target,front,back,sum;
        int min=99999999;
        for (int i = 0; i < num.size(); i++) 
        {

            target = t-num[i];
            front = i + 1;
            back = num.size() - 1;

            while (front < back) 
            {

                sum = num[front] + num[back];
                if (sum < target)
                    front++;

                else if (sum > target)
                    back--;

                else 
                {
                    min=t;
                    break;
                }
                if(abs(sum+num[i]-t)<abs(min-t))
                    min = sum+num[i];
            }
            while (i + 1 < num.size() && num[i + 1] == num[i]) 
                i++;
        }

        return min;
    }
};
__________________________________________________________________________________________________
8752 kb
static bool     _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);

class Solution 
{
public:
    int threeSumClosest(vector<int>& num, int t) 
    {
        if(num.size()==3)
            return num[0]+num[1]+num[2];
        std::sort(num.begin(), num.end());
        int front,back,sum;
        int min=99999999;
        for (int i = 0; i < num.size(); i++) 
        {
            front = i + 1;
            back = num.size() - 1;

            while (front < back) 
            {
                sum = num[front] + num[back] + num[i];
                if (sum < t)
                    front++;

                else if (sum > t)
                    back--;

                else 
                {
                    return t;
                }
                if(abs(sum-t)<abs(min-t))
                    min = sum;
            }
        }
        return min;
    }
};
__________________________________________________________________________________________________
