__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public int integerReplacement(int n) {
        if(n==Integer.MAX_VALUE) return 32; //n = 2^31-1;
    int count = 0;
    while(n>1){
        if(n%2==0) n/=2;
        else{
            if((n+1)%4==0&&(n-1!=2)) n+=1;
            else n-=1;
        }
        count++;
    }
    return count;
    }
}
__________________________________________________________________________________________________
sample 31468 kb submission
class Solution {
    
    public int integerReplacement(int n) {
        if(n == 2147483647)
            return 32;
        
        int count = 0;
        while(n != 1) {
        	if(n%2 == 0){
            	n = n/2;
            } else {
        	   if((n-1) % 4 == 0 || (n - 1 == 2) ) //!!!!!!!!
                   n--;
        	   else 
                   n++;
        	}
            count++;
        }
        return count;
    }
}
__________________________________________________________________________________________________
