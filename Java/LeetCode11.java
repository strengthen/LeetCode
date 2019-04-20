__________________________________________________________________________________________________
1ms
class Solution {
    public int maxArea(int[] height) {
       
        int max = 0,  lo = 0,  hi = height.length-1;
         if(height == null || height.length < 2){
             return max;
         }
        while (lo < hi){
             int loMax = height[lo],  hiMax = height[hi];
             int candidate = (hi - lo) * (loMax < hiMax ? loMax : hiMax );
             max = (candidate < max) ? max : candidate;
            if(height[lo] <= height[hi])
                while (lo < hi && height[lo] <= loMax) ++lo;
            else
                while (hi > lo && height[hi] <= hiMax) --hi;     
        }
        return max;
        
    }
}
__________________________________________________________________________________________________
2ms
class Solution {
    public int maxArea(int[] height) {
        int left = 0, right = height.length - 1, max = 0;
        while(left < right) {
            int dist = right - left;
            int minBorder = Math.min(height[left], height[right]);
            max = Math.max(max, dist * minBorder);
            if (height[left] <= height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return max;
    }
}
__________________________________________________________________________________________________
3ms
class Solution {
    public int maxArea(int[] height) {
        int res = 0;
        int left =0, right=height.length-1;
        while(left<right){
            int h1 = height[left];
            int h2 = height[right];
            int length = right - left;
            res = Math.max(res,length*Math.min(h1,h2));
            if(h1<h2) left++;
            else right--;
        }
        return res;
    }
}
__________________________________________________________________________________________________
35720 kb
class Solution {
    public int maxArea(int[] height) {
        int l = 0;
        int r = height.length-1;
        int max = (r-l)*Math.min(height[l],height[r]);
        while (l<r){
            max = Math.max(max, (r-l)*Math.min(height[l], height[r]));
            if (height[l]<height[r]){
                l++;
            } else {r--;}
            // max = Math.max(max, (r-l)*Math.min(height[l], height[r]));
        }
        return max;
    }
}
__________________________________________________________________________________________________
36168 kb
class Solution {
    public int maxArea(int[] height) {
        int maxarea = 0;
        for(int i=0; i<height.length; i++){
            for(int j=0; j<height.length; j++){
                maxarea = Math.max(maxarea, Math.min(height[i], height[j])*(j-i));
            }
        }
        return maxarea;
    }
}
__________________________________________________________________________________________________
