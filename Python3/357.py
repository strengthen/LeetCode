__________________________________________________________________________________________________
sample 20 ms submission
class Solution:
    def countNumbersWithUniqueDigits(self, n: int) -> int:
        
        
        if n==0:
            return 1;
        
        if n==1:
            return 10;
        
        
    
        mult=81;
        count=81+10;
        
        
    
        for k in range(3,n+1):
            
            mult=mult*(9-k+2);
            count+=mult;
            
            if k>10:
                return count;
            
            
        
        return count;
__________________________________________________________________________________________________
sample 12992 kb submission
class Solution:

    def countNumbersWithUniqueDigits(self, n: int) -> int:
        if n == 1:
            return 10
        if n == 0:
            return 1
        res = 10
        for cnt in range(2,n+1): # 2位数到n位数
            num = 9 #首位数有9种选择
            choice = 10 #一共十个数字
            while(cnt-1): #分别计算cnt位数的满足条件的个数
                num = num * (choice - 1) 
                choice = choice - 1
                cnt = cnt - 1
            res = res + num
        return res
__________________________________________________________________________________________________
