__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    private Map<String, List<Integer>> map = new HashMap<>();
    public List<Integer> diffWaysToCompute(String input) {
        List<Integer> res = new ArrayList<>();
        if(map.containsKey(input)){
            return map.get(input);
        }
        if(input==null||input.isEmpty()) return res;
        
        int len = input.length();
        if(len==1){
            res.add(Integer.parseInt(input));
            return res;
        }
        
        char[] nums = input.toCharArray();
        
        for(int i = 0; i<len; i++){
           if(nums[i]=='+'||nums[i]=='-'||nums[i]=='*') {
               String left = input.substring(0,i);
               String right = input.substring(i+1);
               for(int numLeft:diffWaysToCompute(left)){
                   for(int numRight:diffWaysToCompute(right)){
                       if(nums[i]=='+'){
                           res.add(numLeft+numRight);
                       }else if(nums[i]=='-'){
                           res.add(numLeft-numRight);
                       }else if(nums[i]=='*'){
                           res.add(numLeft*numRight);
                       }
                   }
               }
           }
        }
        
        if(res.size()==0){
            res.add(Integer.parseInt(input));
        }
        
        map.put(input, res);
        
        return res;
    }
}
__________________________________________________________________________________________________
sample 34408 kb submission
class Solution {
    public List<Integer> diffWaysToCompute(String input) {
        Map<String, List<Integer>> map = new HashMap<>();
        return helper(map, input);
    }
    private List<Integer> helper(Map<String, List<Integer>> map,String input) {
        List<Integer> res = new ArrayList<>();
        if(input == null || input.length() == 0) return res;
        if (map.containsKey(input)) {
            return map.get(input);
        }
        int len = input.length();
        for (int i = 0; i < len; i++) {
            char c = input.charAt(i);
            if (c == '+' || c == '-' || c == '*') {
                String subLeft = input.substring(0,i);
                List<Integer> res1 = helper(map, subLeft);
                
                String subRight = input.substring(i+1);
                List<Integer> res2 = helper(map, subRight);
                
                for (Integer i1: res1) {
                    for (Integer i2: res2) {
                        if (c == '+') {
                            res.add(i1+i2);
                        } else if (c=='-') {
                            res.add(i1-i2);
                        } else {
                            // *
                            res.add(i1*i2);
                        }
                    }
                }
                
            }
        }//for i
        if (res.size() == 0) res.add(Integer.valueOf(input));
        map.put(input, res);
        return res;
    }
}
__________________________________________________________________________________________________
