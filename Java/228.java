__________________________________________________________________________________________________
sample 0 ms submission

class Solution {
    public List<String> summaryRanges(int[] nums) {
        List<String> res = new ArrayList<>();
       
        int start = 0; //index
        for(int i=0; i<nums.length; i++){
            if(i==nums.length-1 || nums[i]+1 != nums[i+1]){
                if(start == i){
                    res.add(nums[start]+"");
                }else{
                    res.add(nums[start]+"->"+nums[i]);
                }
                start=i+1; //compare same index rather than num at i+1 (avoids arrayindex exception)
            }   
        }
        
        return res;
    }
}
__________________________________________________________________________________________________
sample 34648 kb submission
class Solution {
  public List<String> summaryRanges(int[] nums) {
    if (nums.length == 0) return Arrays.asList();
    int start = nums[0], prev = nums[0];
    List<String> res = new ArrayList<>();
    BiConsumer<Integer, Integer> adder = (_start, _prev) -> {
      if (_start.equals(_prev)) res.add(String.valueOf(_start));
      else res.add(_start + "->" + _prev);
    };

    for (int i = 1; i < nums.length; ++i) {
      if (nums[i] == prev + 1) {
        prev = nums[i];
      } else {
        adder.accept(start, prev);
        start = nums[i];
        prev = nums[i];
      }
    }
    
    adder.accept(start, prev);
    return res;
  }
}
__________________________________________________________________________________________________
