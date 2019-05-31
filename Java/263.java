__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public boolean isUgly(int num) {
        
        if(num==0)
            return false;
        
        if(num==1)
            return true;
        while(num%2==0)
            num=num/2;
        while(num%3==0)
            num=num/3;
        while(num%5==0)
            num=num/5;
        return num==1;   
    }
}
__________________________________________________________________________________________________
sample 32024 kb submission
class Solution {
    public boolean isUgly(int num) {
		while (num > 1) {
			boolean flag = true;
			if (num % 5 == 0) {
				num /= 5;
				flag = false;
			}
			if (num % 3 == 0) {
				num /= 3;
				flag = false;
			}
			if (num % 2 == 0) {
				num /= 2;
				flag = false;
			}
			if (flag) {
				return false;
			}
		}
		if (num == 1) {
			return true;
		}
		return false;
    }
}
__________________________________________________________________________________________________
