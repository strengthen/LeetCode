__________________________________________________________________________________________________
sample 14 ms submission
class Solution {
    private void swap(double[] nums,int[] index,int pos1,int pos2){
        double tmp1=nums[pos1];
        int tmp2=index[pos1];
        nums[pos1]=nums[pos2];
        index[pos1]=index[pos2];
        nums[pos2]=tmp1;
        index[pos2]=tmp2;
        // return index;
    }
    private int[] sortWithIndex(double[] nums){
        int[] indexArr=new int[nums.length];
        for(int i=0;i<nums.length;i++){
            indexArr[i]=i;
        }
        return quickSort(nums,indexArr,0,nums.length-1);
    }
    private int[] quickSort(double[] nums,int[] index,int start,int end){
        int pos=inPlace(nums,index,start,end);
        if(start<pos-1){
            quickSort(nums,index,start,pos-1);
        }
        if(pos+1<end){
            quickSort(nums,index,pos+1,end);
        }
        return index;
    }
    private int inPlace(double[] nums,int[] index,int start,int end){
        if(start==end){
            return start;
        }
        int pt1=start+1;
        for(int pt2=start+1;pt2<=end;pt2++){
            if(nums[pt2]>=nums[start])
                continue;
            else{
                swap(nums,index,pt1,pt2);
                pt1++;
            }
        }
        swap(nums,index,start,pt1-1);
        return pt1-1;
    }
    public double mincostToHireWorkers(int[] quality, int[] wage, int K) {
        double[] fraction=new double[quality.length];
        for(int i=0;i<quality.length;i++){
            fraction[i]=1.0*wage[i]/quality[i];
        }
        int[] index=sortWithIndex(fraction);
        // System.out.println(Arrays.toString(fraction));
        // System.out.println(Arrays.toString(index));
        PriorityQueue<Integer> maxHeap=new PriorityQueue<>(new Comparator<Integer>(){
            @Override
            public int compare(Integer a,Integer b){
                return b-a;
            }
        });
        int sumQuality=0;
        for(int i=0;i<K;i++){
            maxHeap.offer(quality[index[i]]);
            sumQuality+=quality[index[i]];
        }
        double minCost=sumQuality*fraction[K-1];int tmp=0;
        for(int i=K;i<quality.length;i++){
            tmp=maxHeap.poll();
            maxHeap.offer(quality[index[i]]);
            // System.out.println(tmp);
            sumQuality=sumQuality-tmp+quality[index[i]];
            if(sumQuality*fraction[i]<minCost){
                minCost=sumQuality*fraction[i];
            }
        }
        return minCost;       
    }
}
__________________________________________________________________________________________________
sample 36608 kb submission
class Solution {
    public double mincostToHireWorkers(int[] quality, int[] wage, int K) {
        List<double[]> workers = new ArrayList<>();
        int n = quality.length;
        for (int i = 0; i < n; i++) workers.add(new double[]{wage[i] * 1.0 / quality[i], quality[i]});
        workers.sort((double[] o1, double[] o2) -> Double.compare(o1[0], o2[0]));
        double res = Double.MAX_VALUE;
        double curSum = 0;
        PriorityQueue<Double> pq = new PriorityQueue<>();
        for (int i = 0; i < n; i++) {
            curSum += workers.get(i)[1];
            pq.add(-workers.get(i)[1]);
            if (pq.size() > K) curSum += pq.poll();
            if (pq.size() == K) res = Math.min(res, curSum * workers.get(i)[0]);
        }
        return res;
    }
}
__________________________________________________________________________________________________
