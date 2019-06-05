__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public List<int[]> kSmallestPairs(int[] nums1, int[] nums2, int k) {
        List<int[]> res = new ArrayList<>();
        if (nums1.length == 0 || nums2.length == 0 || k <= 0) return res;
        if (nums1.length <= k/nums2.length){
            for(int n1: nums1){
                for(int n2: nums2){
                    res.add(new int[]{n1,n2});
                }
            }
            return res;
        }
        int lo = nums1[0] + nums2[0], hi = nums1[nums1.length - 1] + nums2[nums2.length - 1];
        
        while(lo < hi){
            int mid = lo + ((hi - lo) >> 1);
            int count = 0;
            for(int i = 0; i < nums1.length && count < k; i++) {
                count += binarySearch(nums2, 0, nums2.length, mid - nums1[i]);
            }
            if(count >= k) hi = mid;
            else lo = mid + 1;
        }
        
        for (int i = 0; i < nums1.length; i++){
            for (int j = 0; j < nums2.length && nums1[i] + nums2[j] < lo; j++) {
                res.add(new int[]{nums1[i], nums2[j]});
            }
        }
        for (int i = 0; i < nums1.length; i++){
            for (int j = 0; j < nums2.length && nums1[i] + nums2[j] <= lo; j++) {
                if (nums1[i] + nums2[j] == lo) {
                    res.add(new int[]{nums1[i], nums2[j]});
                }
                if (res.size() == k) {
                    return res;
                }
            }
        }
        return res;
    }
    
    int binarySearch(int[] nums, int left, int right, int target) {
        while(left < right){
            int mid = left + (right - left) / 2;
            if(nums[mid] > target)  {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return right;
    }
}
__________________________________________________________________________________________________
sample 35708 kb submission
public class Solution {
    public List<int[]> kSmallestPairs(int[] nums1, int[] nums2, int k) {
        PriorityQueue<int[]> que = new PriorityQueue<>((a,b)->a[0]+a[1]-b[0]-b[1]);
        List<int[]> res = new ArrayList<>();
        // Handle edge case
        if(nums1.length==0 || nums2.length==0 || k==0) return res;
        
        // k because we need top k?
        for(int i=0; i<nums1.length && i<k; i++) que.offer(new int[]{nums1[i], nums2[0], 0});
        
        while(k > 0 && !que.isEmpty()){
            int[] cur = que.poll();
            res.add(new int[]{cur[0], cur[1]});
            k--;
            if(cur[2] == nums2.length-1) continue;
            que.offer(new int[]{cur[0],nums2[cur[2]+1], cur[2]+1});
        }
        return res;
    }
}
__________________________________________________________________________________________________
