__________________________________________________________________________________________________
sample 2 ms submission
class Solution {
    public int[] nextGreaterElements(int[] nums) {
        int length = nums.length;
        if(nums==null||nums.length==0){
            return new int[]{};
        }
        if(length ==1){
            return new int[]{-1};
        }
        int [] res = new int[length];
        int max = 0;
        for(int i = 1;i< length;++i){
            if(nums[i]>nums[max]){
                max = i;
            }
        }
        res[max]=-1;
        int index = max;
        // if(index == -1){
        //     index = length-1;
        // }
        
        outer:
        for(int i =0;i<length;i++){
            index--;
            if(index ==-1){
                index = length-1;
            }
            int next = index+1;
            if(next ==length){
                next = 0;
            }
            if(nums[next]>nums[index]){
                res[index] = next;
            }
            else{
                next = res[next];
                while(next!=-1){
                    //System.out.println(nums[index]+" "+nums[next]);
                    if(nums[index]< nums[next]){
                        res[index] = next;
                        continue outer;
                    }
                    next =res[next];
                }
                res[index] = -1;
            }
            
        }
        for(int i =0;i<length;i++){
            if(res[i]!=-1)
                res[i]= nums[res[i]];
        }
        return res;
    }
}
__________________________________________________________________________________________________
sample 41492 kb submission
class Solution {
    public int[] nextGreaterElements(int[] nums) {
        int[] res = new int[nums.length];
        ArrayDeque<Integer> stack = new ArrayDeque<>();

        for (int pass = 0; pass < 2; ++pass) {
            for (int i = 0; i < nums.length; ++i) {
                while (!stack.isEmpty() && nums[i] > nums[stack.getFirst()]) {
                    res[stack.removeFirst()] = nums[i];
                }

                if (pass == 0) {
                    stack.addFirst(i);
                }
            }
        }
        
        while (!stack.isEmpty()) {
            res[stack.removeFirst()] = -1;
        }

        return res;
    }
}
__________________________________________________________________________________________________
