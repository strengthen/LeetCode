__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public List<Integer> pathInZigZagTree(int label) {
        List<Integer> res = new LinkedList<>();

        // calculate the current level sum (we need use it to track)
        // sum = start_label + end_label
        //     = 2^r + 2^(r + 1) - 1
        int row = log2(label); // java does not provide, need do it yourself!
        int start = 1 << row; // 2^(row)
        int sum = start + (2 * start - 1); // start + end is sum

        while (label >= 1) {
            res.add(0, label); // do target add first

            // early stop
            if (label == 1) break;

            // then next label (i.e., parent one)
            label /= 2; // parent candidate label

            // we already derived the relation of current level sum and parent
            // level sum
            sum = (sum - 1) / 2; // parent sum

            label = swap(label, sum); // for next label swap
        }

        return res;
    }

    // Do swap, e.g., on level 2, in: 7, out: 4, sum: 11
    private int swap(int label, int sum) {
        if (label == 1) return 1;

        return sum - label;
    }

    // java does not provide, log2 is for the row index of label value
    // e.g., 4 -> 2, 7 -> 2 for row index
    public int log2(int n) {
        // ideally: 31 - Integer.numberOfLeadingZeros(n);

        int r = 0;
        while (n > 1) {
            r++; // do target first

            n >>= 1; // then next
        }

        return r;
    }
}
__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public List<Integer> pathInZigZagTree(int label) {
        int n = 0;
        while (n<200){
            int min = (int)Math.pow(2,n);
            int max = (int)Math.pow(2,n+1)-1;
            if (min<=label&&max>=label){
                break;
            }
            n++;
        }
        int i = 0;
        if (n%2==0){
            i = label - (int)Math.pow(2,n);
        }else{
            i = (int)Math.pow(2,n+1)-1-label;
        }
        List<Integer> res = new ArrayList();
        res.add(label);
        while (n>0){
            n--;
            i = i/2;
            if (n%2==0){
                res.add((int)Math.pow(2,n)+i);
            }else{
                res.add((int)Math.pow(2,n+1)-1-i);
            }
        }
        Collections.reverse(res);
        return res;
    }
}
__________________________________________________________________________________________________
