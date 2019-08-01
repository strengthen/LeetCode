__________________________________________________________________________________________________
sample 2 ms submission
class Solution {
    public String predictPartyVictory(String senate) {
        char[] arr = senate.toCharArray();
        int cntR = 0, cntD = 0, len = senate.length();
        for(char c : arr)
            if(c == 'R')
                cntR++;
            else
                cntD++;
        while(cntR > 0 && cntD > 0)
        {
            int killR = 0, killD = 0;
            for(int i=0; i<len; i++)
            {
                if(arr[i] == ' ')
                    continue;
                if(arr[i] == 'R')
                {
                    if(killR > 0)
                    {
                        cntR--;
                        killR--;
                        arr[i] = ' ';
                    }
                    else
                        killD++;
                }
                else
                {
                    if(killD > 0)
                    {
                        cntD--;
                        killD--;
                        arr[i] = ' ';
                        
                    }
                    else
                        killR++;
                }
            }
            if(killR > 0)
                for(int i=0; i<len && killR > 0; i++)
                    if(arr[i] == 'R')
                    {
                            cntR--;
                            killR--;
                            arr[i] = ' ';
                    }
            if(killD > 0)
                for(int i=0; i<len && killD > 0; i++)
                    if(arr[i] == 'D')
                    {
                            cntD--;
                            killD--;
                            arr[i] = ' ';
                    }
        }

        if(cntR > 0)
            return "Radiant";
        else
            return "Dire";
            
    }
}
__________________________________________________________________________________________________
sample 37280 kb submission
class Solution {
    public String predictPartyVictory(String senate) {
        int countR=0,countD=0;
        char[] chars=senate.toCharArray();
        for(char c:chars)
        {
            if(c=='R') countR++;
            else countD++;
        }
        
        while(countR!=0&&countD!=0)
        {
            int killR=0,killD=0;
            
            
            for(int i=0;i<chars.length;i++)
            {
                char c=chars[i];
                if(c==' ') continue;
                if(c=='R')
                {
                    if(killR>0)
                    {    
                        killR--;
                        chars[i]=' ';
                        countR--;
                    }
                    else
                        killD++;
                }
                else {
                    if(killD>0)
                    {    
                        killD--;
                        chars[i]=' ';
                        countD--;
                    }
                    else
                        killR++;
                }
            }
            
            if(killD>0)
            {    
                for(int i=0;i<chars.length&&killD>0;i++)
                {
                    if(chars[i]=='D') {
                        chars[i]=' ';
                        countD--;
                        killD--;
                    }
                }
            }   
            if(killR>0)
            {    
                for(int i=0;i<chars.length&&killR>0;i++)
                {
                    if(chars[i]=='R') {
                        chars[i]=' ';
                        countR--;
                        killR--;
                    }
                }
            }
            System.out.println(countR);
            
        }
        
        if(countR>0) return "Radiant";
        else return "Dire";
    }
}
__________________________________________________________________________________________________
