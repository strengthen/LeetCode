__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public String getHint(String secret, String guess) {
        int n=secret.length();
        int a=0;
        int b=0;
        int[] h=new int[128];
        for(int i=0;i<n;i++){
            if (secret.charAt(i)==guess.charAt(i))
                a++;
            else{
                h[(int)secret.charAt(i)]++;
            }
        }
        for(int i=0;i<n;i++){
            if (secret.charAt(i)!=guess.charAt(i)){
                int c=(int)guess.charAt(i);
                if (h[c]>0){
                    h[c]--;
                    b++;
                }
            }
        }
        return a+"A"+b+"B";
    }
}
__________________________________________________________________________________________________
sample 34496 kb submission
class Solution {
    public String getHint(String secret, String guess) {
        int[] number = new int[10];
        int bulls = 0, cows = 0;
        for (int i = 0; i < secret.length(); i++) {
            if (secret.charAt(i) == guess.charAt(i))
                bulls++;
            else {
                if (number[secret.charAt(i) - '0']++ < 0) cows++;
                if (number[guess.charAt(i) - '0']-- > 0) cows++;
            }
        }
        return bulls + "A" + cows + "B";
    }
}
__________________________________________________________________________________________________
