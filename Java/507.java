__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public boolean checkPerfectNumber(int num) {
    int primes[]= new int[]{2,3,5,7,13,19,31};
        for (int prime: primes) {
            if(merseenePrimes(prime) == num)
                return true;
        }

        return false;

    }

    public int merseenePrimes(int p){
        return (1 << (p -1)) * ((1 << p) - 1 );
    }
}
__________________________________________________________________________________________________
sample 31792 kb submission
class Solution {
    public boolean checkPerfectNumber(int num) {
        	int sum=0;
        
        if(num==0) return false;
for(int i=1;i<=num/2;i++)
{
	if(num%i==0)
	{
		sum+=i;
	}
}
  if(sum==num)
  {
	 return true;
  }
  else
  {
	  return false;
  }
  
    }
}
__________________________________________________________________________________________________
