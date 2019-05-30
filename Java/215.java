__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    static int findKthLargest(int[] nums, int k){
        int n = nums.length;
        partition(nums,0, n-1, k);
        return nums[k-1];
    }

    static void partition(int[] nums, int start, int end, int k){
        if(start >= end)
            return;

        int i = start;
        int j = end;
        int pivot = median3(nums, start, end);

        while(i <= j){
            while(nums[i] > pivot)
                i++;
            while(nums[j] < pivot)
                j--;
            if(i <= j){
                swap(nums, i, j);
                i++;
                j--;
            }
        }

        if(k <= i){
            partition(nums, start, i - 1, k);
        }else{
            partition(nums, i, end, k);
        }
    }

    static int median3(int[] nums, int left, int right){
        int center = (left + right) / 2;
        if(nums[left] > nums[center])
            swap(nums, left, center);
        if(nums[left] > nums[right])
            swap(nums, left, right);
        if(nums[center] > nums[right])
            swap(nums, center, right);

        return nums[center];
    }

    static void swap(int[] nums, int i, int j){
        int tmp = nums[j];
        nums[j] = nums[i];
        nums[i] = tmp;
    }
}
__________________________________________________________________________________________________
sample 34436 kb submission
class Solution {
    public int findKthLargest(int[] nums, int k) {
    PriorityQueue<Integer> pq=new PriorityQueue<Integer>((n1,n2)->n1-n2);
    for(int n:nums)
    {
        pq.add(n);
        if(pq.size()>k)pq.poll();
    }
        return pq.poll();
    }
}
__________________________________________________________________________________________________
