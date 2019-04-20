__________________________________________________________________________________________________
40ms
public class Solution
{
    public int Reverse(int x)
    {
        int res = 0;
        while (x != 0)
        {
            int t = res * 10 + x % 10;
            if ((t - x % 10) / 10 != res) return 0;
            res = t;
            x /= 10;
        }
        return res;
    }
}
__________________________________________________________________________________________________
44ms
public class Solution {
    public int Reverse(int x) {
        bool isNumberNegative = x < 0 ? true : false;
        int copyX = x;
        int counter = 0;
        int a = 0;
        List<int> ints = new List<int>();
        String s = "";
        
        if(isNumberNegative){
            x = x * -1;
            copyX = copyX * -1;
        }
        
        while(x > 0){
            x  = x / 10;
            counter++;
        }
        
        while(copyX > 0){
            a = copyX % 10;
            ints.Add(a);
            copyX = copyX / 10;
            counter--;
        }
        
        foreach(int i in ints){
            //Console.WriteLine("Int:"+i);
            s += i.ToString();
        }
        
        //Console.WriteLine("String : "+s);
        try{
            checked{
                int final = 0;
                if(!string.IsNullOrEmpty(s)){
                    if(isNumberNegative)
                        final = Convert.ToInt32(s) * -1;
                    else
                        final = Convert.ToInt32(s);

                }
                //Console.WriteLine("Final String:"+final);
                return final;
            }
        } catch{
            return 0;
        }
    }
}
__________________________________________________________________________________________________
48ms
public class Solution {
    public int Reverse(int x) {
        
        if(x >= Int32.MaxValue || x <= Int32.MinValue){
            return 0; 
        }
        
        bool negative = x < 0;
        
        x = negative ? -1 * x : x;
        Console.WriteLine("x="+ x);
       
        
        var str = Convert.ToString(x, 10);
        Console.WriteLine("Str =" + str);
        var stk = new Stack();
        foreach(var s in str){
            if(s != '-')
            stk.Push(s);
        }
        str = "";
        while(stk.Count > 0){
            str = str + stk.Pop();
        }
        Console.WriteLine(str);
        
        int result;
        if(Int32.TryParse(str, out result)){
            return negative ? -1 * (int)  result: result;      
        }
        return 0;        
        
    }
}
__________________________________________________________________________________________________
12916 kb
public class Solution {
    public int Reverse(int x) {
            if (x == 0) return x;
            bool neg = x < 0;

            long num = Math.Abs((long)x);
            long res = 0;
            while (num > 0)
            {
                res *= 10;
                res += num % 10;
                num /= 10;
                if (res > int.MaxValue) return 0;
            }

            if (neg) res = -res;
            return (int)res;
       }    
}
__________________________________________________________________________________________________
12920 kb
public class Solution {
    public int Reverse(int x) {
         long tmp = x,re=0;
        if(x<0) tmp *= -1;
        while(tmp!=0){
            re = re*10 + tmp%10;
            tmp/=10;
        }
        if(re>2147483647 || re<-2147483647) return 0;
        if(x<0) re *= -1;
        return (int)re;
    }
}
__________________________________________________________________________________________________
