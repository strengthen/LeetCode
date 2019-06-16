__________________________________________________________________________________________________
class Solution {
    public int largestValsFromLabels(int[] v, int[] l, int n, int u) {
        int[][] arr=new int[v.length][2];
        for(int i=0;i<arr.length;i++){
            arr[i][0]=v[i];arr[i][1]=l[i];
        }
        Arrays.sort(arr,(a,b)->-a[0]+b[0]);
        Map<Integer,Integer> map=new HashMap<>();
        for(int i=0;i<arr.length;i++){
            if(!map.containsKey(arr[i][1]))map.put(arr[i][1],0);
        }
        int total=0;
        for(int i=0;i<arr.length;i++){
            if(n==0)break;
            if(map.get(arr[i][1])<u){
                map.put(arr[i][1],map.get(arr[i][1])+1);
                total+=arr[i][0];
                n--;
            }
        }
        return total;
    }
}
__________________________________________________________________________________________________

__________________________________________________________________________________________________
