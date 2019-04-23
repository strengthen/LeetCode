__________________________________________________________________________________________________
4ms
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k = nums1.size()-1;
        int j = n-1;
        int i = m-1;
        if(i < 0){
            nums1 = nums2;
            return;
        }
        while(k >= 0){
            if(i >= 0 && j >= 0){
                if(nums1[i] > nums2[j]){
                    nums1[k--] = nums1[i--];
                }else{
                    nums1[k--] = nums2[j--];
                }
            }else if(i >= 0){
                nums1[k--] = nums1[i--];
            }else{
                nums1[k--] = nums2[j--];
            }
        }
    }
};
__________________________________________________________________________________________________
8852 kb
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1;
        int j = n-1;
        
        int pos = m+n-1;
        while (i >=0 && j>=0)
        {
            while (i >= 0 && j >= 0 && nums1[i] >= nums2[j])
            {
                nums1[pos--] = nums1[i--];
            }
            
            while (i >= 0 && j >= 0 && nums2[j] >= nums1[i])
            {
                nums1[pos--] = nums2[j--];
            }
        }
        while (i >= 0)
        {
            nums1[pos--] = nums1[i--];
        }
        while (j >= 0)
        {
            nums1[pos--] = nums2[j--];
        }
    }
};
__________________________________________________________________________________________________
