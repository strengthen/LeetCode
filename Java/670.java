__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    // e.g. 1993->9913 rather than 9193
    /*
    找到每个数字右边的最大数字(包括其自身)，这样我们再从高位像低位遍历，如果某一位上的数字小于其右边的最大数字，说明需要调换，由于最大数字可能不止出现一次，我们希望能跟较低位的数字置换，这样置换后的数字最大，所以我们就从低位向高位遍历来找那个最大的数字，找到后进行调换即可。
    */
    public int maximumSwap(int num) {
        char[] s = Integer.toString(num).toCharArray();
        
        int t = -1;
        for (int i = 0; i < s.length - 1; i++)
            if (s[i] < s[i + 1]) {
                t = i;  // 找出单调增的第一个位置
                break;
            }
        if (t == -1)    return Integer.valueOf(new String(s));
        
        int maxIdx = t;
        for (int i = t + 1; i < s.length; i++){
            if (s[maxIdx] <= s[i])  maxIdx = i;  //找出单调增的第一个位置后面最大数出现的最后一个位置maxIdx
        }
        for (int i = 0; i < s.length; i++){
            if (s[i] < s[maxIdx]) {
                swap(s, i, maxIdx);
                break;
            }
        }
        return Integer.valueOf(new String(s));
    }
    private void swap(char[] s, int idx1, int idx2){
        char temp = s[idx1];
        s[idx1] = s[idx2];
        s[idx2] = temp;
    }
}
__________________________________________________________________________________________________
sample 31616 kb submission
class Solution {
    public int maximumSwap(int num) {
        char[] arr = String.valueOf(num).toCharArray();
        int[] last = new int[10];
        for(int i=0; i<arr.length; i++){
            last[arr[i]-'0']=i;//last occurance of this digit;
        }
        for(int i=0; i<arr.length; i++){
            for(int d=9; d>arr[i]-'0'; d--){
                if(last[d]>i){
                    swap(arr, i, last[d]);
                    return Integer.valueOf(new String(arr));
                }
            }
        }
        return num;
    }
    private void swap(char[] arr, int i, int j){
        char tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
    }
}
__________________________________________________________________________________________________
