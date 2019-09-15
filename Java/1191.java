__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
    public int kConcatenationMaxSum(int[] arr, int k) {
        long l=0,r=0,sum=0,total=0,tmp=0;
        for(int i=0;i<arr.length;i++){
            tmp+=arr[i];
            r=Math.max(tmp,r);
        }
        tmp=0;
        for(int i=arr.length-1;i>=0;i--){
            tmp+=arr[i];
            l=Math.max(tmp,l);
        }
        tmp=0;
        for(int i=0;i<arr.length;i++){
            tmp+=arr[i];
            if(tmp<0)
                tmp=0;
            sum=Math.max(sum,tmp);
        }
        
        for(int i=0;i<arr.length;i++){
            total+=arr[i];
        }
        int mod=1000000007;
        if(k==1)
            return (int)sum;
        else if(k==2)
            return (int)(Math.max(sum,l+r)%mod);
        else{
            if(total>0)
                return (int)((l+r+(k-2)*total)%mod);
            else
                return (int)(Math.max(sum,l+r)%mod);
        }
    }
}
__________________________________________________________________________________________________
sample 5 ms submission
class Solution {
    public int kConcatenationMaxSum(int[] arr, int k) {
        long sum = 0l;
        for (int i : arr) sum += i;
        if (k == 1) return getMaxSubarr(arr);
        if (sum <= 0) {
            int[] doubleArr = doubleArray(arr);
            return getMaxSubarr(doubleArr);
        }
        else {
            int maxFromStart = 0, maxFromEnd = 0, accu = 0;
            for (int i = 0; i < arr.length; i++) {
                accu += arr[i];
                maxFromStart = Math.max(maxFromStart, accu);
            }
            accu = 0;
            for (int i = arr.length - 1; i >= 0; i--) {
                accu += arr[i];
                maxFromEnd = Math.max(maxFromEnd, accu);
            }
            long res = sum * (k - 2) + maxFromStart + maxFromEnd;
            return (int)(res % 1000000007);
        }
    }
    
    private int[] doubleArray(int[] arr) {
        int[] b = new int[arr.length * 2];
        System.arraycopy(arr, 0, b, 0, arr.length);
        System.arraycopy(arr, 0, b, arr.length, arr.length);
        return b;
    }
    
    private int getMaxSubarr(int[] arr) {
        int max = 0, accu = 0;
        for (int i : arr) {
            accu = Math.max(i, i + accu);
            max = Math.max(max, accu);
        }
        return max;
    }
}
__________________________________________________________________________________________________
