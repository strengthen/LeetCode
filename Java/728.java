__________________________________________________________________________________________________
sample 1 ms submission
class Solution {    
    public List<Integer> selfDividingNumbers(int left, int right) {
        List<Integer> selfDivNums = new ArrayList<>();
        for (int i = left; i <= right; i++) {
            if(checkSelfDiv(i)) {
                //System.out.println(i);
                selfDivNums.add(i);
            }
        }
        return selfDivNums;
    }
    
    public boolean checkSelfDiv(int number) {
        if (number < 10 && number > 0) return true;
        int res = number;
        while (res > 0) {
            int temp = res % 10;
            if (temp == 0) return false;
            //System.out.println(temp);
            if(!(number % temp == 0)) {
                return false;
            }
            res/= 10;
        }
        return true;
    }
}
__________________________________________________________________________________________________
sample 32348 kb submission
class Solution {
    public List<Integer> selfDividingNumbers(int left, int right) {
        
        List ans = new ArrayList();
        
        for(int i = left; i <= right; i++)
        {
            
            int num = i; 
            boolean x = false;
            while(num > 0){
                int temp = num%10;
                if(temp == 0)
                {
                    x = false;
                    break;
                }
                x = i%temp ==0 ? true : false;
                if (!x)
                {
                    x = false;
                    break;
                }
                num/=10;
            }
            if(x)
                ans.add(i);
        }
        
        return ans;
        
    }
}
__________________________________________________________________________________________________
