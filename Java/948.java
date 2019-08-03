__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    
    public int bagOfTokensScore(int[] tokens, int pow) {
        Arrays.sort(tokens);
        int pnt = 0;
        int i = 0;
        int j = tokens.length-1;
        
        while(i<=j) {
            if(tokens[i] <= pow) {
                pnt++;                
                pow -= tokens[i];
                i++;
            } else if(pnt > 0 && i != j) {
                pnt--;
                pow += tokens[j];
                j--;
            } else {
                break;
            }
        }
        return pnt;
    }
}
__________________________________________________________________________________________________
sample 38456 kb submission
class Solution {
    public int bagOfTokensScore(int[] tokens, int P) {
        if(tokens.length < 1) return 0;
        int[] sums = new int[tokens.length];
        Arrays.sort(tokens);
        int lo = 0, hi = tokens.length-1;
        int score = 0;
        int maxScore = 0;
        while(lo <= hi){
            if(tokens[lo] <= P){
                score++;
                maxScore = Math.max(maxScore, score);
                P -= tokens[lo++];
            }else if(score > 0){
                score--;
                P += tokens[hi--];
            }else{
                break;
            }
        }
        return maxScore;
    }
    
    public int bagOfTokensScore1(int[] tokens, int P) {
        if(tokens.length < 1) return 0;
        int[] sums = new int[tokens.length];
        Arrays.sort(tokens);
        sums[0] = tokens[0];
        for(int i = 1; i < tokens.length; i++){
            sums[i] = sums[i-1] + tokens[i];
        }
        return findMaxScore(0, tokens.length - 1, P, 0, tokens, sums);
    }
    
    private int findMaxScore(int lo, int hi, int power, int score, int[] tokens, int[] sums){
        if(hi < lo) return score;
        if(sums[hi] <= power) return (hi - lo + 1) + score;
        
        int maxScore = findMaxScore(lo, hi-1, power, score, tokens, sums);
        if(score > 0) {
            maxScore = Math.max(maxScore, findMaxScore(lo, hi-1, power + tokens[hi], score - 1, tokens, sums));
        }else if(power >= tokens[lo]){
            maxScore = Math.max(maxScore, findMaxScore(lo + 1, hi, power - tokens[lo], score + 1, tokens, sums));
        }
        
        return maxScore;
    }
}
__________________________________________________________________________________________________
