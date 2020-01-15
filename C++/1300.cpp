__________________________________________________________________________________________________
sample 8 ms submission
static auto fast=[]{ios_base::sync_with_stdio(false);cin.tie(nullptr);return 0;}();
class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        int l = 0, r = arr[0];
        for (int a : arr)
            r = max(r, a);
        while (l < r) {
            int mid = (l + r) >> 1;
            if (helper(arr, mid) < target)
                l = mid + 1;
            else
                r = mid;
        }
        if (abs(helper(arr, l - 1) - target) <= abs(helper(arr, l) - target))
            return l - 1;
        return l;
    }
    int helper(vector<int>& arr, int x) {
        int res = 0;
        for (int a : arr)
            res += min(a, x);
        return res;
    }
};
__________________________________________________________________________________________________
sample 12 ms submission
class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        int res=0;
        int differ=INT_MAX;
        int left=INT_MAX;
        int right=INT_MIN;
        for(int i=0; i<arr.size();++i){
            left=0;
            right=max(right,arr[i]);
            
        }
        while(left<=right){
            int mid=(left+right)/2;
            int sum=0;
            for(int temp: arr){
                int curr=temp>mid?mid:temp;
                sum+=curr;
            }
            if(abs(sum-target)<differ){
                res=mid;
                differ=abs(sum-target);
                
            }
            if(abs(sum-target)==differ){
                res=min(res,mid);
            }
            if(sum>target){
                right=mid-1;
            }
            else if(sum==target){
                right--;
            }
            else{
                left=mid+1;
            }
        }
        return res;
    }
};
__________________________________________________________________________________________________
