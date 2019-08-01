__________________________________________________________________________________________________
sample 1 ms submission
class Solution 
{
     public int maximumProduct(int[] nums) {
        int max1 = Integer.MIN_VALUE, max2 = Integer.MIN_VALUE, max3 = Integer.MIN_VALUE;
        int min1 = Integer.MAX_VALUE, min2 = Integer.MAX_VALUE;
        for (int i : nums) {
            if (i > max3) {
                if (i > max2) {
                    max3 = max2;
                    if (i > max1) {
                        max2 = max1;
                        max1 = i;
                    } else {
                        max2 = i;
                    }
                } else {
                    max3 = i;
                }
            }
            if (i < min2) {
                if (i < min1) {
                    min2 = min1;
                    min1 = i;
                } else {
                    min2 = i;
                }
            }
        }
        return max1 * Math.max(min1 * min2, max2 * max3);
    }
}
__________________________________________________________________________________________________
sample 39020 kb submission
class Solution {
    public int maximumProduct(int[] nums) {
        if(nums.length < 3 )
            return -1;   
        int max1 = Integer.MIN_VALUE;
        int max2 = Integer.MIN_VALUE;
        int max3 = Integer.MIN_VALUE;
        int min1 = Integer.MAX_VALUE;
        int min2 = Integer.MAX_VALUE;
        
        for(int n : nums) {
            
            if( n > max1) {
                
                max3= max2;
                max2 = max1;
                max1 = n;
            }
            else if(n>max2) {
                
                max3 = max2;
                max2= n;
            }
            else if( n > max3)  {
                max3 = n;
            }
            if( n < min1) {
                min2 = min1;
                min1 = n;
            }
            else if(n < min2) {
                min2 = n;
            }
            
        }
        
        
        System.out.println("max values"+ max1 + " " + max2 +" " + max3);
        
        return Math.max(max1 * max2 * max3, min1 * min2 * max1);
        
    }
}
__________________________________________________________________________________________________
