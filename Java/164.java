__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public int maximumGap(int[] nums) {
    int n = nums.length;
    if(n < 2) return 0;
    int min = nums[0];
    int max = nums[0];
    for(int i = 1;i < n;i++){
        if(min > nums[i]) min = nums[i];
        if(max < nums[i]) max = nums[i];
    }
    
    int gap = (max-min)/(n-1);
    if(gap == 0) gap++;
    int len = (max-min)/gap+1;
    int [] tmax = new int [len];
    int [] tmin = new int [len];
    
    for(int i = 0;i < n;i++){
        int index = (nums[i]-min)/gap;
        if(nums[i] > tmax[index]) tmax[index] = nums[i];
        if(tmin[index] == 0 || nums[i] < tmin[index]) tmin[index] = nums[i];
    }
    int myMax = 0;
    for(int i = 0;i < len;i++){
        if(myMax < tmin[i]-min) myMax = tmin[i]-min;
        if(tmax[i] != 0) min = tmax[i];
    }
    return myMax;
 }
}
__________________________________________________________________________________________________
sample 35456 kb submission
class Solution {
    class Bucket {
        int high, low;
        boolean init;
        
        Bucket () {
        }
    }
    public int maximumGap(int[] nums) {
        int max, min, bucketSize, bucketNum, maxGap;
        Bucket[] bucket;
        Bucket prevBucket;
        
        if (nums.length < 2) {
            return (0);
        }
        
        max = min = nums[0];
        for (int i : nums) {
            max = Math.max(max, i);
            min = Math.min(min, i);
        }
        
        bucketSize = Math.max(1, (max - min) / (nums.length - 1));
        bucketNum = (max - min) / bucketSize + 1;
        bucket = new Bucket[bucketNum];
        for (int i = 0; i < bucketNum; i++) {
            bucket[i] = new Bucket();
        }
        
        for (int i = 0; i < nums.length; i++) {
            int idx;
            
            idx = (nums[i] - min) / bucketSize;
            if (!bucket[idx].init) {
                bucket[idx].init = true;
                bucket[idx].low = nums[i];
                bucket[idx].high = nums[i];
            } else {
                bucket[idx].low = Math.min(bucket[idx].low, nums[i]);
                bucket[idx].high = Math.max(bucket[idx].high, nums[i]);
            }
        }
        
        maxGap = 0;
        prevBucket = null;
        for (int i = 0; i < bucketNum; i++) {
            if (!bucket[i].init) {
                continue;
            }
            if (prevBucket == null) {
                prevBucket = bucket[i];
                continue;
            }
            
            maxGap = Math.max(maxGap, bucket[i].low - prevBucket.high);
            prevBucket = bucket[i];
        }
        
        return (maxGap);
    }
}
__________________________________________________________________________________________________
