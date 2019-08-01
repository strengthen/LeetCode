__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        int len2 = nums2.length;
        if (len2 == 0) return nums1;
        int [] map = new int[6005];
        map [ nums2[len2 - 1 ] ] = -1;
        for (int i = len2 - 2; i >= 0; i-- ) {
            int k = nums2[i];
            int v = nums2[i + 1];
            if (k > v)
                do {
                    v=map[v];
                } while ( k>v && v != -1);
            map[k] = v;
        }

        for (int i = 0; i < nums1.length; i++)
            nums1[i] = map[ nums1[i] ];

        return nums1;
    }
}
__________________________________________________________________________________________________
sample 35616 kb submission
class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
      Map<Integer, Integer> nGE = new HashMap<>();
      Stack<Integer> greaterElement = new Stack<>();
      for(int i = nums2.length -1; i>=0;i--) {
        if (greaterElement.empty()) {
          greaterElement.push(nums2[i]);
          nGE.put(nums2[i], -1);
        } else if (greaterElement.peek() < nums2[i]) {
          while(!greaterElement.empty() && greaterElement.peek() < nums2[i])
            greaterElement.pop();
          nGE.put(nums2[i], greaterElement.empty() ? -1 : greaterElement.peek());
          greaterElement.push(nums2[i]);
        } else {
          nGE.put(nums2[i], greaterElement.empty() ? -1 : greaterElement.peek());
          greaterElement.push(nums2[i]);
        }
      }
      
      int nge1[] = new int[nums1.length];
      for (int i=0;i< nums1.length;i++) {
        nge1[i]  = nGE.computeIfAbsent(nums1[i], k -> -1);
      }
      return nge1;
        
    }
}
__________________________________________________________________________________________________
