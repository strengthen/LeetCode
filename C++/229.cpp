__________________________________________________________________________________________________
sample 8 ms submission
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int ans[2], cnt[2];
        int k = 2;
        cnt[0] = cnt[1] = 0;
        int sz = nums.size();
        for(auto num : nums) {
            bool flag = 0;
            for(int j=0;j<k;++j) {
                if(num == ans[j]) {
                    cnt[j]++;
                    flag = true;
                    break;
                }
            }
            if(flag) continue;
            flag = 0;
            for(int j=0;j<k;++j) {
                if(cnt[j] == 0) {
                    ans[j] = num;
                    cnt[j]++;
                    flag = 1;
                    break;
                }
            }
            if(flag) continue;
            for(int j=0;j<k;++j) 
                cnt[j]--;
        }
        memset(cnt, 0, sizeof(cnt));
        for(auto num : nums) {
            for(int j=0;j<k;++j) {
                if(num == ans[j]) {
                    cnt[j]++;
                }
            }
        }
        vector<int> temp;
        for(int j=0;j<k;++j) {
            if(3*cnt[j] > sz) {
                temp.push_back(ans[j]);
            }
        }
        return temp;
    }
};

static const auto _ = []() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0; }(); 
__________________________________________________________________________________________________
sample 10412 kb submission
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> maj;
        int n=nums.size(),a=0,b=0,cnta=0,cntb=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==a) cnta++;
            else if(nums[i]==b) cntb++;
            else if(cnta==0) {a=nums[i];cnta=1;}
            else if(cntb==0) {b=nums[i];cntb=1;}
            else {cnta--;cntb--;}
        }
        
        cnta=0;cntb=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==a) cnta++;
            if(nums[i]==b) cntb++;
        }
        
        if(cnta>n/3) maj.push_back(a);
        if(cntb>n/3&&b!=a) maj.push_back(b);
        
        return maj;
    }
};
__________________________________________________________________________________________________
