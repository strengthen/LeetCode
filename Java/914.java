__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public boolean hasGroupsSizeX(int[] deck) {
        if(deck==null || deck.length<2) return false;
       int[]count=new int[1000];
        for(int i:deck){
            count[i]++;
        }
     int g=-1;
        for(int m: count) {
            if(m>0) g=g==-1? m: gcd(g, m);
        }
       return g>=2;
    }
    public int gcd(int x, int y) {
        return x==0?y:gcd(y%x, x);
    }
}
__________________________________________________________________________________________________
sample 37152 kb submission
class Solution {
    public boolean hasGroupsSizeX(int[] deck) {
        HashMap<Integer, Integer> hm = new HashMap<>();
        
        for(int i: deck){
            hm.putIfAbsent(i,0);
            hm.compute(i,(x,y)->y+1);          
        }
        int size=Integer.MAX_VALUE;
        for(int i: hm.values()){
            if(i<size){
                size=i;
            }
            }
        if(size<2){
            return false;
        }
        for(int i: hm.values()){
        if(hcf(size,i)==1){
            return false;
        }
        }
        return true;
    }
int hcf(int a, int b){
    int hcf=1;
    for(int i=1;i<=a && i<=b;i++){
        if(a%i==0 &&b%i==0){
            hcf=i;
        }
    }
    return hcf;
  }
}
__________________________________________________________________________________________________
