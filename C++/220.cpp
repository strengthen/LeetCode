__________________________________________________________________________________________________
× Close
sample 8 ms submission
class Solution {
public:
	// 使用multiset
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		if (k < 1 || t < 0)
			return false;
		int n = nums.size();
		int i = 0;
		multiset<long long int> mst{};
		long long int maxdis = t;
		while (i < n && mst.size() < k)
		{
			long long curnum = nums[i];
			auto it = mst.upper_bound(curnum);
			// 可能出现的三种结果，最左边，最右边，中间位置
			if (mst.empty())
			{
				mst.insert(curnum);
				++i;
				continue;
			}
			if (it == mst.end())
			{
				auto left_nearest = it;
				--left_nearest;
				long long int curdis = abs(*left_nearest - curnum);
				if (curdis <= maxdis)
					return true;
				mst.insert(curnum);
				++i;
			}
			else if (it == mst.begin())
			{
				auto right_nearest = it;
				long long int curdis = abs(*right_nearest - curnum);
				if (curdis <= maxdis)
					return true;
				mst.insert(curnum);
				++i;
			}
			else
			{
				auto left_nearest = it;
				auto right_nearest = it;
				--left_nearest;
				long long int curdis_left = abs(*left_nearest - curnum);
				long long int curdis_right = abs(*right_nearest - curnum);
				if (curdis_left <= maxdis || curdis_right <= maxdis)
					return true;
				++i;
			}
		}
		while (i < n)
		{
			long long curnum = nums[i];
			auto it = mst.upper_bound(curnum);
			if (it == mst.end())
			{
				auto left_nearest = it;
				--left_nearest;
				long long int curdis = abs(*left_nearest - curnum);
				if (curdis <= maxdis)
					return true;

			}
			else if (it == mst.begin())
			{
				auto right_nearest = it;
				long long int curdis = abs(*right_nearest - curnum);
				if (curdis <= maxdis)
					return true;
			}
			else
			{
				auto left_nearest = it;
				auto right_nearest = it;
				--left_nearest;
				long long int curdis_left = abs(*left_nearest - curnum);
				long long int curdis_right = abs(*right_nearest - curnum);
				if (curdis_left <= maxdis || curdis_right <= maxdis)
					return true;
			}
			mst.insert(curnum);
			mst.erase(mst.find(nums[i - k]));
			++i;
		}
		return false;
	}
};
__________________________________________________________________________________________________
sample 8976 kb submission
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
                  
                     if (k < 1 || t < 0) return false;
                    for(int i = 0; i < nums.size(); i++){
                        for(int j = i+1; j < i+k+1; j++){
                                if(j >= nums.size()) 
                                        break;
                                if(abs((long)nums[i] - (long)nums[j]) <= t) 
                                    return true;
                         }
                     }
                    return false;
    }
};
__________________________________________________________________________________________________
