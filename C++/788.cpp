__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    int rotatedDigits(int N) {
        vector<int> res(N+1, 0);
        int count = 0;
        for(int i = 0; i <= N; ++i){
            if(i < 10){
                if(i == 0 || i == 1 || i == 8)
                    res[i] = 1;
                else if(i == 2 || i == 5 || i == 6 || i == 9)
                {
                    res[i] = 2;
                    ++count;
                }
            }else{
                int a = res[i/10], b = res[i%10];
                if(a == 1 && b == 1)
                    res[i] = 1;
                else if(a >= 1 && b >= 1)
                {
                    res[i] = 2;
                    ++count;
                }
            }
        }
        return count;
    }
};
__________________________________________________________________________________________________
sample 8268 kb submission
class Solution {
public:
    int rotatedDigits(int N) 
    {
    int count=0;
     for(int i=0;i<N;i++)
     {
         int temp=i+1;
         bool flag=true;
         int cnt=0;
         while(temp!=0)
         {
             int rem=temp%10;
             if(rem==1 || rem==0 || rem==8 || rem==2 || rem==5 || rem==6 || rem==9)
             {flag=true;}
             else
             {flag=false;break;}
             
             if(rem==2 || rem==5 || rem==6 || rem==9)
             {cnt++;}
             temp=temp/10;
         }
         
         if(cnt > 0 && flag==true)
         {count++;}
     }
        
        return count;
    }
};
__________________________________________________________________________________________________
