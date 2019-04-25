__________________________________________________________________________________________________
sample 8 ms submission
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()==0 & nums2.size()==0)
            return vector<int>();
        
        vector<int> results;
        unordered_set set(nums1.begin(), nums1.end());
        for (int i: nums2){
            if (set.count(i)==1){
                results.push_back(i);
                set.erase(i);
            }
        }
        return results;
    }
};
__________________________________________________________________________________________________
sample 8700 kb submission
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> inter;
        int last; bool has = false;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        auto it1 = nums1.begin();
        auto it2 = nums2.begin();
        while(it1 != nums1.end() && it2 != nums2.end()) {
            if (*it1 < * it2) it1++;
            else if (*it1 == *it2) {
                if (!has || *it1 != last)
                {
                    has = true;
                    inter.push_back(*it1);
                    last = *it1;
                }
                it1++;
                it2++;
            } else it2++;
        }
        
        return inter;
    }
};
__________________________________________________________________________________________________
