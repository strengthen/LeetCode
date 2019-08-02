__________________________________________________________________________________________________
sample 0 ms submission
class Solution {    
    public int numRabbits(int[] answers) {
        if (answers == null || answers.length == 0) {
            return 0;
        }
        int[] cnt = new int[1000];
        int res = 0;
        for (int i: answers) {
            if (cnt[i] > 0) {
                cnt[i]--;
            } else {
                res += i + 1;
                cnt[i] = i;
            }
        }
        return res;
    }
}
__________________________________________________________________________________________________
sample 36732 kb submission
class Solution {
    public int numRabbits(int[] answers) {
        HashMap<Integer, Integer> map=new HashMap<Integer, Integer>();
        int count=0;
        for(int i: answers){
            if(i==0){
                count++;
            }
            else if(map.containsKey(i)){
                map.put(i,map.get(i)-1);
                if(map.get(i)==0){
                    map.remove(i);
                }
            }
            else{
                map.put(i,i);
                count+=(i+1);
            }
        }
        return count;
        
    }
}
__________________________________________________________________________________________________
