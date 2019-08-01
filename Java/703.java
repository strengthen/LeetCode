__________________________________________________________________________________________________
sample 52 ms submission
class KthLargest {

    int k;
    int[] heap;

    public KthLargest(int k, int[] nums) {
        int size = Math.min(k, nums.length);
        this.k = k;

        heap = new int[k];
        for(int i = 0; i < size; i++) {
            heap[i] = nums[i];
        }

        // dummy value
        if (size < k) {
            heap[k-1] = Integer.MIN_VALUE;
        }
        buildMinHeap(heap);
        
        // if size > k
        for (int i = k; i < nums.length; i++) {
            add(nums[i]);
        }
    }

    private void buildMinHeap(int[] heap) {
        int half = (k/2) - 1;
        
        for (int i = half; i >= 0; i--) {
            heapify(i, heap);
        }
    }

    private void heapify(int i, int[] heap) {
        int leftIndex = 2 * i + 1;
        int rightIndex = 2 * i + 2;
        
        int lowest = i;
        
        if (leftIndex < k && heap[leftIndex] < heap[lowest]) {
            lowest = leftIndex;
        }
        
        if (rightIndex < k && heap[rightIndex] < heap[lowest]) {
            lowest = rightIndex;
        }
        
        if (lowest != i) {
            swap(heap, i, lowest);
            heapify(lowest, heap);
        }
    }

    private void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    public int add(int val) {
        if (val > heap[0]) {
            heap[0] = val;
            heapify(0, heap);
        }
        
        return heap[0];
    }

}

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */
__________________________________________________________________________________________________
sample 41412 kb submission
class KthLargest {
    private PriorityQueue<Integer> pq = new PriorityQueue<>();
    private Integer limit = -1;

    public KthLargest(int k, int[] nums) {
        limit = k;
        for (int n : nums) {
            pq.offer(n);
            if (pq.size() > limit)
                pq.poll();
        }
    }
    
    public int add(int val) {
        pq.offer(val);
        if (pq.size() > limit) pq.poll();
        return pq.peek();
    }
}

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */
__________________________________________________________________________________________________
