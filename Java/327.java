__________________________________________________________________________________________________
sample 5 ms submission
class Solution {
    int count;
    
    public int countRangeSum(int[] nums, int lower, int upper) {
        long[] sum=new long[nums.length+1];
        for(int i=1;i<=nums.length;i++){
            sum[i]=sum[i-1]+nums[i-1];
        }
        long[] tmp=new long[sum.length];
        count=0;
        mergesort(sum ,0, sum.length-1,tmp,lower,upper);
        return count;
    }
    
    public void mergesort(long[] nums,int l, int r, long[] tmp,int  lower, int upper ){
        if(l>=r) return;
        int mid=(l+r)/2;
        mergesort(nums,l,mid,tmp,lower,upper);
        mergesort(nums,mid+1,r,tmp,lower,upper);
        merge(nums,l,mid,r,tmp,lower,upper);
    }
    
    public void  merge(long[] nums,int l,int mid,int r,long[] tmp,int lower,int upper){
        int i=l,j=mid+1,idx=l;
        int m1=mid+1,m2=mid+1;
        while(i<=mid) {
            while(m1<=r && nums[m1]-nums[i]<lower) m1++;
            while(m2<=r && nums[m2]-nums[i]<=upper)  m2++;
            
            while(j<=r && nums[j]<nums[i])
                tmp[idx++]=nums[j++];
            tmp[idx++]=nums[i++];
            count+= m2-m1;
        }
        while(j<=r) tmp[idx++]=nums[j++];
        for(int k=l;k<=r;k++) nums[k]=tmp[k];
    }
}
__________________________________________________________________________________________________
sample 35364 kb submission
class Solution {
    public int countRangeSum(int[] nums, int lower, int upper) {
        int n = nums.length;
        long[] sums = new long[n + 1];
        long[] helper = new long[n + 1];
        for (int i = 0; i < n; i++)
        {
            sums[i + 1] = nums[i] + sums[i];
            helper[i + 1] = sums[i + 1];
        }
        return mergeSort(sums, helper, 0, n + 1, lower, upper);
    }
    
    private int mergeSort(long[] sums, long[] helper, int left, int right, int lower, int upper)
    {
        if (left + 1 == right) return 0;
        int mid = left + (right - left) / 2;
        int leftCount = mergeSort(helper, sums, left, mid, lower, upper);
        int rightCount = mergeSort(helper, sums, mid, right, lower, upper);
        int low = mid, up = mid, j = mid, k = left, count = 0;
        for (int i = left; i < mid; i++)
        {
            while (j < right && helper[j] <= helper[i]) sums[k++] = helper[j++];
            sums[k++] = helper[i];
            while (low < right && helper[low] - helper[i] < lower) low++;
            while (up < right && helper[up] - helper[i] <= upper) up++;
            count += up - low;
        }
        while (j < right) sums[k++] = helper[j++];
        return count + leftCount + rightCount;
    }
}
__________________________________________________________________________________________________
