__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public List<String> fizzBuzz(int n) {
        List<String> s = new ArrayList<>();
        for(int  i = 1;i<=n;i++)
        {
            int number = i;
            if(number % 3 == 0 && number % 5 == 0)
            {
                s.add("FizzBuzz");
            }else
            if(number % 3 == 0)
            {
               s.add("Fizz"); 
            }
            else if(number % 5 == 0 )
            {
                s.add("Buzz");
            }
            
            else
            {
                String s1 = String.valueOf(number);
                s.add(s1);
            }
        }
        return s;
    }
}
__________________________________________________________________________________________________
sample 35484 kb submission
class Solution {
    public List<String> fizzBuzz(int n) {
        
        List<String> ans = new ArrayList<String>();
        for (int i = 1; i<=n; i++) {
            if (i%3 == 0 && i%5 == 0) {
                ans.add("FizzBuzz");
            } else if (i%3 == 0) {
                ans.add("Fizz");
            } else if (i%5 == 0) {
                ans.add("Buzz");
            } else {
                ans.add(String.valueOf(i));
            }
        }
        return ans;
        
    }
}
__________________________________________________________________________________________________
