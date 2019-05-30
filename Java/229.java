__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public List<Integer> majorityElement(int[] nums) {
        List<Integer> result = new ArrayList<Integer>();
        if(nums.length == 0){
            return result;
        }
        int candidateA = nums[0];
        int candidateB = nums[0];
        int countA = 0;
        int countB = 0;
        for(int num : nums){
            if(num == candidateA){
                countA += 1;
            }else if(num == candidateB){
                countB += 1;
            }else{
                if(countA == 0){
                    candidateA = num;
                    countA = 1;
                }else if(countB == 0){
                    candidateB = num;
                    countB = 1;
                }else{
                    countA -= 1;
                    countB -= 1;
                }
            }
        }
        countA = 0;
        countB = 0;
        for(int e : nums){
            if(e == candidateA){
                countA += 1;
            }else if(e == candidateB){
                countB += 1;
            }
        }
        if(countA > nums.length / 3){
            result.add(candidateA);
        }
        if(countB > nums.length / 3){
            result.add(candidateB);
        }
        return result;
    }
}
__________________________________________________________________________________________________
sample 36872 kb submission
class Solution {
    public List<Integer> majorityElement(int[] nums) {
        List<Integer> ret = new ArrayList<Integer>();
        int occur = nums.length/3;
        HashMap<Integer, Integer> occurences = new HashMap<Integer, Integer>();
        for(int i = 0; i < nums.length; i++){
            if(occurences.containsKey(nums[i])){
                occurences.put(nums[i], occurences.get(nums[i])+1);
            }else{
                occurences.put(nums[i], 1);
            }
        }
        
        for (Map.Entry mapElement : occurences.entrySet()) {
            int compare = (int) mapElement.getValue();
            if(compare > occur){
                ret.add((int)mapElement.getKey());
            }
        }
        
        return ret;
    }
}
__________________________________________________________________________________________________
