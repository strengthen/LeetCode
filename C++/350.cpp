__________________________________________________________________________________________________
sample 8 ms submission
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        for(int i =0;i<nums1.size();i++){
            mp[nums1[i]]++;
        }
        vector<int>ans;
        for(int i = 0;i<nums2.size();i++){
            if(mp.find(nums2[i])!= mp.end() && mp[nums2[i]]!=0){
                mp[nums2[i]]--;
                ans.emplace_back(nums2[i]);
            }
        }
        return ans;
    }
};
__________________________________________________________________________________________________
sample 8796 kb submission
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()==0 || nums2.size()==0)
            return {};
       sort(nums1.begin(),nums1.end());
       sort(nums2.begin(),nums2.end());
       vector<int>res;
       int i=0,j=0;
        while(i<=nums1.size()-1 && j<=nums2.size()-1){
            if(nums1[i]==nums2[j]){
             res.push_back(nums1[i]);   
             i++;
             j++;
            }
            else if(nums1[i]<nums2[j]){
             i++;   
            }
            else if(nums1[i]>nums2[j]){
              j++;  
            }
        }
        return res;
    }
};
__________________________________________________________________________________________________
