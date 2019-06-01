__________________________________________________________________________________________________
sample 3 ms submission
class Solution {
  
  class Node{
    int val;
    int self;
    int child;
    
    Node left;
    Node right;
    
    public Node(int val) {
      this.val = val;
      this.child = 1;
    }
  }
  
  Integer[] ans;
  
  public List<Integer> countSmaller(int[] nums) {
    ans = new Integer[nums.length];
    
    if (nums == null) return null;
    if (nums.length == 0) return new ArrayList<Integer>();
    
    Node head = new Node(nums[nums.length-1]);
    ans[nums.length -1] = 0;
    
    for (int i = nums.length - 2; i >= 0; i--) {
      add(head, i, nums[i], 0); 
    }
    
    return Arrays.asList(ans);
  }
  
  private void add(Node head, int i, int val, int acc) {
    // if i > head.val, go right, add acc to head's val and pass it down
    // if i < head.val go left, increase head's acc by 1
    // if i == head.val, update the value, increase self
    if (val > head.val) {
      // go right
      if (head.right == null) {
        Node right = new Node(val);
        head.right = right;
        ans[i] = acc + head.child + head.self;
      } else {
        add(head.right, i, val, acc + head.child + head.self); 
      }
    } else if (val < head.val) {
      // go left
      head.child++;
      if (head.left == null) {
        Node left = new Node(val);
        head.left = left;
        ans[i] = acc;
      } else {
        add(head.left, i, val, acc);
      }
    } else {
      ans[i] = acc + head.child - 1;
      head.self++;
    }
  }
}
__________________________________________________________________________________________________
sample 36220 kb submission
class Solution {
    
    int[] bit;
    int[] result;
    int n;
    int maxNumber = 100001;
    void update(int idx) {
        while(idx<=maxNumber) {
            bit[idx]+=1;
            idx += idx & -idx;
        }
    }
    
    int find(int idx) {
        int sum = 0;
        while(idx > 0) {
            sum+=bit[idx];
            idx-=idx & -idx;
        }
        return sum;
    }
    
    public List<Integer> countSmaller(int[] nums) {
        n=nums.length;
        if (n==0) {
            return new ArrayList<>();
        }
        if (n==1) {
            return Arrays.asList(0);
        }
        int min = Integer.MAX_VALUE;
        for (int i=n-1;i>=0;i--) {
            min = Math.min(min, nums[i]);
        }
        if (min <= 0) {
            min--;
            for (int i=n-1;i>=0;i--) {
                nums[i] -= min;
            }
        }
        bit = new int[maxNumber];    
        result = new int[n];
        for (int i=n-1;i>=0;i--) {
            result[i] = find(nums[i]-1);
            update(nums[i]);
        }
        List<Integer> res = new ArrayList<>();
        for (int i=0;i<n;i++) {
            res.add(result[i]);
        }
        return res;
    }
}
__________________________________________________________________________________________________
