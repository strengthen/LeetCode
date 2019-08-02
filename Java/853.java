__________________________________________________________________________________________________
sample 5 ms submission
class Solution {
    public int carFleet(int target, int[] position, int[] speed) {
        
        if(position.length==0)return 0;
        int fleets=1;
        int[] idx=new int[position.length];
        for(int i=0;i<idx.length;i++)idx[i]=i;
        sort(idx, position, 0, idx.length-1);
       // for(int i=0;i<idx.length;i++)System.out.print(position[idx[i]]+" ");
        //stack stores distinct fleets
        float ahead=(target-position[idx[0]])/(float)speed[idx[0]];
        for(int i=1;i<idx.length;i++){
            float t=(target-position[idx[i]])/(float)speed[idx[i]];
            //if one can reach earlier or in same time than the ahead then it forms a fleet with the ahead 
            if(ahead>=t)continue;
            //if one cant reach earlier than the ahead then it forms its own unique fleet
            ahead=t;
            fleets++;
        }
        return fleets;
        
    }
    public void sort(int[] idx, int[] position, int left, int right){
        if(left<right){
            int x=partition(idx, position, left, right);
            sort(idx, position, left, x-1);
            sort(idx, position, x+1, right);
        }
    }
    public int partition(int[] idx, int[] position, int left, int right){
            int pivot=position[idx[right]];
            int i=left-1, j=left;
            while(j<=right){
                if(position[idx[j]]>=pivot){
                    swap(idx, ++i, j);
                }
                j++;
            }
        return i;
    }
    public void swap(int[] A, int i, int j){
        int temp=A[i];A[i]=A[j];A[j]=temp;
    }
}
__________________________________________________________________________________________________
sample 35704 kb submission
class Solution {
    public int carFleet(int target, int[] position, int[] speed) {
        if (position == null || position.length == 0) {
            return 0;
        }
        List<int[]> list = new ArrayList<int[]>();
        for (int i = 0; i < position.length; i++) {
            
            list.add(new int[] {position[i], speed[i]});
        }
        Collections.sort(list, (a,b) -> {return b[0] - a[0];});
        int ans = 1;
        double limit = (double) (target - list.get(0)[0]) / list.get(0)[1];
        for (int[] info: list) {
            double time =(double) (target - info[0]) / info[1];
            if (time <= limit) {
                continue;
            }
            else {
                limit = time;
                ans ++;
            }
        }
        return ans;
    }
}
__________________________________________________________________________________________________
