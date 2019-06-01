__________________________________________________________________________________________________
sample 51 ms submission
class NumArray {
//start segment tree
    class SegmentTreeNode {
      int start;
      int end;
      int sum;
      SegmentTreeNode left;
      SegmentTreeNode right;
      
      public SegmentTreeNode( int start, int end) {
        this.start=start;
        this.end=end;
        this.left=null;
        this.right=null;
        this.sum=0;
        
        
      }
    }
  
    SegmentTreeNode root=null;
  
    private SegmentTreeNode buildSegmentTree(int[] nums, int start, int end) {
      if(start>end) return null;
      SegmentTreeNode ret=new SegmentTreeNode(start, end);
      if(start==end) {
        ret.sum=nums[start];
      }else {
        int mid=start+(end-start)/2;
        ret.left=buildSegmentTree(nums, start, mid);
        ret.right=buildSegmentTree(nums, mid+1, end);
        ret.sum=ret.left.sum+ret.right.sum;
      }
      return ret;  
    }
  
   
    public void updateSegmentTree(SegmentTreeNode root, int pos, int val) {
      if(root.start==root.end) {
        root.sum=val;
        return;
      } 
      int mid=root.start+(root.end-root.start)/2;
      if(pos<=mid)
        updateSegmentTree(root.left, pos, val);
      else
        updateSegmentTree(root.right, pos, val);
      root.sum=root.left.sum+root.right.sum;
    }
  
  
    public int sumRangeSegmentTree(SegmentTreeNode root, int start, int end) {
      if(root.end==end && root.start==start)        
        return root.sum;
      int mid=root.start+(root.end-root.start)/2;
      if(end<=mid)
        return sumRangeSegmentTree(root.left, start, end);
      else if(start>=mid+1)
        return sumRangeSegmentTree(root.right, start, end);
      else
        return sumRangeSegmentTree(root.left, start, mid) + sumRangeSegmentTree(root.right, mid+1, end);
    }
  
//end segment tree
  
    public NumArray(int[] nums) {
      //root=buildSegmentTree(nums, 0, nums.length-1);
      this.size=nums.length;
      this.BITTree=new int[size+1];
      this.nums=nums;
      for(int i=0; i<size; i++) {
        updateBITTree(i+1, nums[i]);
      }
      
    }
    public void update(int i, int val) {
      //updateSegmentTree(root, i, val)  ;
      updateBITTree(i+1, val-nums[i]);
      nums[i]=val;
    }
    
  
    public int sumRange(int i, int j) {
      //return sumRangeSegmentTree(root, i, j);
      
      return getSum(j+1)-getSum(i);
    }
  
  
//start BIT binary index tree
    int[] BITTree;
    int[] nums;
    int size;
//end BIT  
    public void updateBITTree(int i, int delta)  {
      
      while(i<BITTree.length) {
        BITTree[i]+=delta;
        i+= i&(-i);
      }
    }
  
    private int getSum(int i) {
      int sum=0;
      
      while(i>0) {
        sum+=BITTree[i];
        i-=(i&-i);
      }
      return sum;
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
__________________________________________________________________________________________________
sample 43692 kb submission
class NumArray {
    private int MAXN = 100100;
    private int[] T = new int[MAXN];
    private int[] nums;
    
    private void add(int i, int val) {
        for (i++; i < MAXN; i += (i & -i)) {
            T[i] += val;
        }
    }
    
    private int sum(int i) {
        int s = 0;
        for (i++; i > 0; i -= (i & -i)) {
            s += T[i];
        }
        return s;
    }
    
    public NumArray(int[] nums) {
        this.nums = nums;
        for (int i = 0; i < nums.length; i++) {
            add(i, nums[i]);
        }
    }
    
    public void update(int i, int val) {
        int delta = val - nums[i];
        nums[i] = val;
        add(i, delta);
    }
    
    public int sumRange(int i, int j) {
        return sum(j) - sum(i-1);
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
__________________________________________________________________________________________________
