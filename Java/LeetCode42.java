__________________________________________________________________________________________________
0ms
class Solution {
    public int trap(int[] height) {
        int result = 0;
        int start = 0;
        int end = height.length - 1;
        while (start < end) {
            if (height[start] <= height[end]) {
                int current = height[start];
                while (height[++start] < current) {
                    result += current - height[start];
                }
            } else {
                int current = height[end];
                while(height[--end] < current) {
                    result += current - height[end];
                }
            }
        }
        return result;
    }
}
__________________________________________________________________________________________________
1ms
class Solution {
    public int trap(int[] height) {
        if(height == null || height.length == 0)
            return 0;
        int[] leftHighest = new int[height.length];
        for(int i = 1; i < height.length; i++)
        {
            leftHighest[i] = Math.max(leftHighest[i-1], height[i-1]);
        }
        
        int rightHighest = height[height.length-1], result = 0;
        for(int i = height.length-2; i > 0; i--)
        {
            int smaller = Math.min(rightHighest, leftHighest[i]);
            if(smaller > height[i])
                result += smaller-height[i];
            rightHighest = Math.max(rightHighest, height[i]);
        }
        return result;
    }
}
__________________________________________________________________________________________________
2ms
class Solution {
    public int trap(int[] height) {
        
        List<Integer> left = new ArrayList<>();
        List<Integer> right = new ArrayList<>();
        int max = Integer.MIN_VALUE;
        int ans  = 0;
        for(int i = 0; i<height.length;i++)
        {
            left.add(Math.max(max,height[i]));
            max = Math.max(max,height[i]);
        }
        
        max = Integer.MIN_VALUE;
        for(int i = height.length - 1; i>=0;i--)
        {
            right.add(Math.max(max,height[i]));
            max = Math.max(max,height[i]);

        }
        int l = 0, r = height.length - 1;
        for(int i = 0; i<height.length;i++)
        {
            ans = ans + Math.min(left.get(l++),right.get(r--)) - height[i];
        }
        return ans;
    }
}
__________________________________________________________________________________________________
35508 kb
class Solution {
    public int trap(int[] height) {
        int[] maxSoFarLeft = new int[height.length];
        int[] maxSoFarRight = new int[height.length];
        int left = 0;
        int right = 0;
        for(int i = 0; i < height.length; i++){
            maxSoFarLeft[i] = Math.max(left, height[i]);
            left = maxSoFarLeft[i];
        }
        
        for(int i = height.length -1 ; i >=0; i--){
            maxSoFarRight[i] = Math.max(height[i], right);
            right = maxSoFarRight[i];
        }
        
        int area = 0;
        
        for(int i= 0; i < height.length; i++){
            area += Math.min(maxSoFarLeft[i], maxSoFarRight[i]) - height[i];
        }
        
        return area;
        
    }
}
__________________________________________________________________________________________________
35552 kb
class Solution {
        public int trap(int[] A) {
            if (A.length < 3)
                return 0;
            int ans = 0;
            int l = 0;
            int r = A.length - 1;
            // find the left and right edge which can hold water
            // 找到存储水的左右边界
            while ((l < r) && (A[l] <= A[l + 1]))// 找到下降的位置
                l++;
            while ((l < r) && (A[r] <= A[r - 1]))
                r--;
            while (l < r) {
                int left = A[l];
                int right = A[r];
                if (left <= right) {
                    // add volum until an edge larger than the left edge
                    // 加上水的体积直到大于左边界的数出现
                    while ((l < r) && (left >= A[++l]))
                        // left=A[1]=1, A[++l]=A[2]=0, +=1-0
                        // A[3]=2>left, l=3, continue
                        ans += (left - A[l]);
                }
                else {
                    // add volum until an edge larger than the right volum
                    // 加上水的体积直到大于右边界的数出现
                    while ((l < r) && (A[--r] <= right))
                        ans += (right - A[r]);
                }
                // while ((l < r) && (A[l] <= A[l + 1]))// 找到下降的位置
                // l++;
                // while ((l < r) && (A[r] <= A[r - 1]))
                // r--;
            }
            return ans;
        }
    }
__________________________________________________________________________________________________