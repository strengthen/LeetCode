__________________________________________________________________________________________________
sample 4 ms submission
auto gucciGang = []() {std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return 0; }();
/*
首先可以确定的是，
nums中必然包含1，如果不包含1，那么[1,n]这个范围中的1就没法实现
其次数组中的元素不能重复使用，如果允许重复使用，那么把1重复多次，就可以组成任意整数。
令miss为[0,n]中缺少的最小整数，意味着我们可以实现[0,miss)范围内的任意整数。
如果数组中有某个整数x<=miss, 那么我们可以把[0,miss)区间的所有整数加上x，区间变成了[x, miss+x)，由于区间[0,miss)和[x, miss+x)重叠，两个区间可以无缝连接起来，意味着我们可以把区间[0,miss)扩展到[0, miss+x)。
如果数组中不存在小于或等于miss的元素，则区间[0,miss)和[x, miss+x) 脱节了，连不起来。此时我们需要添加一个数，最大限度的扩展区间[0, miss)。那添加哪个数呢？当然是添加miss本身，这样区间[0,miss)和[miss, miss+miss)恰好可以无缝拼接。
举个例子，令nums=[1, 2, 4, 13, 43], n=100，我们需要让[1,100]内的数都能够组合出来。
使用数字1,2,4，我们可以组合出[0, 8)内的所有数，但无法组合出8，由于下一个数是13，比8大，根据规则2，我们添加8，把区间从[0,8)扩展到[0,16)。
下一个数是13，比16小，根据规则1，我们可以把区间从[0,16)扩展到[0,29)。

下一个数是43，比29大，根据规则2，添加29，把区间从[0,29)扩大到[0,58)。

由于43比58小，根据规则1，可以把区间从[0,58)扩展到[0,101)，刚好覆盖了[1,100]内的所有数。

最终结果是添加2个数，8和29，就可以组合出[1,100]内的所有整数。
*/
class Solution {
public:
	int minPatches(vector<int>& nums, int n) {
		size_t count = 0;
		size_t i = 0;
		for (long t = 0; t < n;){
			if (i < nums.size() && t >= nums[i] - 1) { t += nums[i++]; }
			else{ t += t + 1; ++count; }
		}
		return count;
	}
};
__________________________________________________________________________________________________
sample 8864 kb submission
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        return mp(nums,n);
    }
private:
    int mp(vector<int>& nums, int n)
    {
        int c=0;
        long sum=0;
        int ns = nums.size();        
        for(int i=0; i<ns; ++i)
        {
            while(sum+1<nums[i] && sum<n)
            {
                sum = 2*sum +1;
                ++c;
            }
            
            sum += nums[i];
            if(sum>=n) return c;
        }
        
        while(sum<n)
        {
            sum = 2*sum +1;
            ++c;
        }
        
        return c;
    }
};
__________________________________________________________________________________________________
