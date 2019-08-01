__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
   public int[] constructRectangle(int area) {
        int w = (int)Math.sqrt(area);
	while (area%w!=0) w--;
	return new int[]{area/w, w};
 }
}
__________________________________________________________________________________________________
sample 32180 kb submission
class Solution {
    public int[] constructRectangle(int area) {
        int[] dim = new int[2];
        
        int length = 1;
        int width = (int) Math.sqrt(area);
        
        while(width>=1)
        {
            length = area/width;
            if(area%length==0)
            {
                break;
            }
            width--;
        }
        
        dim[0]=length;
        dim[1]=width;
        
        return dim;
        
    }
}
__________________________________________________________________________________________________
