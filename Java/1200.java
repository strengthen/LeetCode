__________________________________________________________________________________________________
sample 20 ms submission
class Solution {
    public List<List<Integer>> minimumAbsDifference(int[] arr) {
        Arrays.sort(arr);
        int min = (int)1e7;
        for(int i=0;i<arr.length-1;i++){
            if(arr[i+1]-arr[i]<min)
                min=arr[i+1]-arr[i];
        }
        //System.out.println(min);
        boolean flag=false;
        List<List<Integer>> al=new ArrayList<>();
        for(int i=0;i<arr.length-1;i++){
            if(arr[i+1]-arr[i]==min){
                ArrayList<Integer> tmp=new ArrayList<Integer>();
                tmp.add(arr[i]);
                tmp.add(arr[i+1]);
                al.add(tmp);
            }
        }
        return al;
    }
}
__________________________________________________________________________________________________
sample 23 ms submission
class Solution {
    public List<List<Integer>> minimumAbsDifference(int[] arr) {
        Arrays.sort(arr);
        int minDiff = 0x7fffffff;
        for (int i = 0; i < arr.length - 1; i++) {
            minDiff = Math.min(minDiff, arr[i + 1] - arr[i]);
        }
        List<List<Integer>> res = new ArrayList<>();
        for (int i = 0; i < arr.length - 1; i++) {
            if (arr[i + 1] - arr[i] == minDiff) {
                List<Integer> cur = new ArrayList<>(Arrays.asList(arr[i], arr[i + 1]));
                res.add(cur);
            }
        }
        return res;
    }
}
__________________________________________________________________________________________________
