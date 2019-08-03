__________________________________________________________________________________________________
sample 2 ms submission
class Solution {
    public int findJudge(int N, int[][] trust) {
        int arr[] = new int[N+1];
        int rv = -1;
        //System.out.println(trust.length);
       for(int i=0; i< trust.length; i++){
           arr[trust[i][1]]++;
       }
        
        for(int j=0; j<arr.length; j++){
            if(arr[j] == N-1){
                rv = j;
            }
        }
        //System.out.println(rv);
        
       for(int i=0; i< trust.length; i++){
           //System.out.println(trust[i][0]);
           if(trust[i][0] == rv){
               return -1;
           }
       }
            
        return  rv;    
    }
}
__________________________________________________________________________________________________
sample 55980 kb submission
class Solution {
    public int findJudge(int N, int[][] trust) {
        boolean isJudgeTrusted = true;
        int judge = -1;
        Map<Integer, List<Integer>> trustMap = new HashMap();

        for (int i = 1; i <= N; i++) {
            trustMap.put(i, new ArrayList<>());
        }

        for (int[] singleTrust : trust) {
            int personOne = singleTrust[0];
            int personTwo = singleTrust[1];
            trustMap.computeIfPresent(personOne, (k,v) -> {
                List<Integer> newTrusts = new ArrayList<>(v);
                newTrusts.add(personTwo);
                return newTrusts;
            });
        }

        for (Map.Entry<Integer, List<Integer>> person : trustMap.entrySet()) {
            if (person.getValue().isEmpty()) {
                judge = person.getKey();
            }
        }

        for (Map.Entry<Integer, List<Integer>> person : trustMap.entrySet()) {
            if (person.getKey() != judge && !person.getValue().contains(judge)) {
                isJudgeTrusted = false;
            }
        }

        if (isJudgeTrusted) {
            return judge;
        } else {
            return -1;
        }
    }
}
__________________________________________________________________________________________________
