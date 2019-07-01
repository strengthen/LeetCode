__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public int[] distributeCandies(int c, int n) {
        if(n <= 0) return new int[0];
        if(n==1){
            int [] a = {c};
            return a;
        }
        int [] a = new int[n];
        int ns = n * (n+1) / 2, r = 0, nn = n * n, rs = ns + nn * r;
        while(c >= rs){
            r++;
            c-=rs;
            rs = ns + nn * r;
        }
        for(int i=0; i<n; i++)
            a[i] = n * r * (r-1) / 2 + r * (i+1);
        
        for(int i=0; i<n & c>0; i++){
            int irs = r*n + i + 1;
            a[i] += c>=irs ? irs : c;
            c-=irs;
        }
        return a;
    }
}
__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public int[] distributeCandies(int candies, int num_people) {
        
        
      /*  int k=(-1+(int)Math.sqrt(1+8*candies))/2;
        System.out.println(k);
       
        
        int remain=candies-(k*(k+1)/2);
        int[] ans=new int[num_people];
        
        for(int i=0;i<k;i++)
        {
            ans[i%num_people]+=i+1;
        }
        
        ans[k%num_people]+=remain;
        return ans; */
        
        
          int[] res = new int[num_people];
        for (int i = 0; candies > 0; ++i) {
            res[i % num_people] += Math.min(candies, i + 1);
            candies -= i + 1;
        }
        return res;
        }
}
__________________________________________________________________________________________________
