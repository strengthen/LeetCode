__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public int[] deckRevealedIncreasing(int[] deck) {
        
        Arrays.sort(deck);
        return myDeckRevealedIncreasing(deck,false);
    }
    public int[] myDeckRevealedIncreasing(int[] deck,boolean needReverse) {
        if(deck==null)return null;
        int len = deck.length;
        if(len==0)return null;
        int[] res = new int[len];
        int mid = (len+1)/2;
        for(int i = 0;i < mid;i++){
            res[i*2] = deck[i];
        }
        int left = len/2;
        int[] leftNums = new int[left];
        for(int i = mid;i < len;i++){
            leftNums[i-mid] = deck[i];
        }
        boolean isNeed = false;
        if(len%2!=0)isNeed = true;
        int[] leftRes = myDeckRevealedIncreasing(leftNums,isNeed);
        if(leftRes!=null){
            for(int i = 0;i < left;i++){
                res[i*2+1] = leftRes[i];
            }
        }
        if(needReverse){
            res = adapt(res);
        }
        return res;
    }
    int[] adapt(int[] list){
        if(list==null)return null;
        int len = list.length;
        int[] res = new int[len];
        for(int i=1;i<len;i++){
            res[i] = list[i-1];
        }
        res[0] = list[len-1];
        return res;
    }
}
__________________________________________________________________________________________________
sample 35952 kb submission
class Solution {
    public int[] deckRevealedIncreasing(int[] deck) {
        Arrays.sort(deck);
        Deque<Integer> deque = new LinkedList<>();
        for (int i = deck.length-1 ; i >= 0 ; i--) {
            deque.offerFirst(deck[i]);
            if (i != 0) {
                deque.offerFirst(deque.pollLast());
            }
        }
        
        return deque.stream().mapToInt(Integer::intValue).toArray();
    }
}
__________________________________________________________________________________________________
