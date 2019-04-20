__________________________________________________________________________________________________
0ms
class Solution {
    public void nextPermutation(int[] nums) {
        final int len = nums.length;
        if(len <= 1){
            return;
        }
        int i = len - 1;
        //case 5423 -> 5432
        if(nums[i] > nums[i - 1]){
            int temp = nums[i];
            nums[i]= nums[i-1];
            nums[i-1] = temp;
            return;
        }
        i--;
        while(i >= 0 && nums[i + 1] <= nums[i]){
            i--;
        }
        //case 5432
        if(i < 0){
            reverse(nums, 0, nums.length - 1);
            return;
        }
        //case 465321
        int j = len - 1;
        while(nums[j] <= nums[i]){
            j--;
        }
        //swap i and j
        int tem = nums[i];
        nums[i] = nums[j];
        nums[j] = tem;
        reverse(nums, i + 1, len - 1);
  
    }
    
    private void reverse(int[] nums, int i, int j){
        while(i < j){
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            i++;
            j--;
        }

    }
}
__________________________________________________________________________________________________
1ms
public class Solution
{
    public void nextPermutation(int[] nums)
    {
        int i = nums.length - 2;
        while (i>=0 && nums[i+1]<=nums[i])
            i--;
        
        if (i >= 0)
        {
            int j = nums.length - 1;
            while (j >= 0 && nums[j] <= nums[i])
                j--;
            
            swap(nums, i, j);
        }
        reverse(nums, i + 1);
    }

    private void reverse(int[] nums, int start)
    {
        int i = start, j = nums.length-1;
        while (i < j)
        {
            swap(nums, i, j);
            i++;
            j--;
        }
    }

    private void swap(int[] nums, int i, int j)
    {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}
__________________________________________________________________________________________________
2ms
class Solution {
    public void nextPermutation(int[] nums) {
        if(nums.length == 0 || nums.length == 1)
            return;
        List<Integer> list = new ArrayList<>();
        list.add(nums[nums.length-1]);
        for(int i=nums.length-2;i>=0;i--){
            if(nums[i]>=nums[i+1]){
                list.add(nums[i]);
            }else{
                list = help(list,nums,i);
                int index = 0;
                for(int k=i+1;k<nums.length;k++){
                    nums[k] = list.get(index);
                    index++;
                }
                break;
            }
        }
        if(list.size() == nums.length){
            Collections.sort(list); 
            for(int i=0;i<nums.length;i++){
                nums[i] = list.get(i);
            }
        }
    }
    public List<Integer> help(List<Integer> list, int[] nums, int i){
         Collections.sort(list);
         for(int j=0;j<list.size();j++){
            if(list.get(j)>nums[i]){
                int temp = nums[i];
                nums[i] = list.get(j);
                list.set(j,temp);
                break;
            }
         }
        Collections.sort(list);
        return list;
    }
}
__________________________________________________________________________________________________
35948 kb
class Solution {
    public void nextPermutation(int[] nums) {
        int curIndex =-1;
    
        for(int i = nums.length-2;i>=0;i--){
            if(nums[i] < nums[i+1]) {curIndex = i;break;}
        }
        
        if(curIndex == -1) sort(nums,0,nums.length-1);
        else {
           int curmin = Integer.MAX_VALUE; 
            int curminIndex = -1;
          for(int i = curIndex+1;i< nums.length;i++){
                       //   System.out.println(i);

              if(nums[i]> nums[curIndex] && nums[i]<curmin){curmin = nums[i];curminIndex =i;}
          }
            //switch i and curminIdex
           // System.out.println(curIndex);
            //System.out.println(curminIndex);
            if(curminIndex == -1) return;
            
            swap(nums,curIndex,curminIndex);
            
           // System.out.println("here");
            
          sort(nums,curIndex+1,nums.length-1);  
        }
    }
    
    private void sort(int[] nums, int startIndex,int endIndex){
        if(startIndex == endIndex) return;

        for(int j = 0;j<=endIndex-startIndex+1;j++){
           for(int i=startIndex;i<=endIndex-1;i++){
               if(nums[i]>nums[i+1]) swap(nums,i,i+1);
           } 
        }
       
    }
    private void swap(int[] nums, int i,int j){
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;  
    }
}
__________________________________________________________________________________________________
36004 kb
class Solution {
    public void nextPermutation(int[] nums) {
        if(nums.length == 0 || nums.length == 1) 
            return;
        
        int i = nums.length-1;
        int min = nums[i];
        int minIndex = i;
        
        for(;i>0;i--) {
            if(nums[i]>nums[i-1]) {
                break;
            } 
        }
        
        if(i>=0) {
            Arrays.sort(nums,i,nums.length);
            if(i>0) {
                int j = i-1;
                while(i<nums.length && nums[j]>=nums[i])
                    i++;
                swap(nums,i,j);
            }    
        }
    }
    
    private void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}
__________________________________________________________________________________________________