__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public String alphabetBoardPath(String target) {
        StringBuilder ans = new StringBuilder();
        char cur = 'a';
        for (char ch : target.toCharArray()) {
            move(ans, cur - 'a', ch - 'a');
            ans.append('!');
            cur = ch;
        }
        return ans.toString();
    }

    private void move(StringBuilder sb, int from, int to) {
        int[] posFrom = getPos(from);
        int[] posTo = getPos(to);
        if (from <= to) {
            if (posFrom[1] < posTo[1]) {
                move(sb, 'R', posFrom[1], posTo[1], 1);
            }
            else {
                move(sb, 'L', posFrom[1], posTo[1], -1);
            }
            if (posFrom[0] < posTo[0]) {
                move(sb, 'D', posFrom[0], posTo[0], 1);
            }
            else {
                move(sb, 'U', posFrom[0], posTo[0], -1);
            }
        }
        else {
            if (posFrom[0] < posTo[0]) {
                move(sb, 'D', posFrom[0], posTo[0], 1);
            }
            else {
                move(sb, 'U', posFrom[0], posTo[0], -1);
            }
            if (posFrom[1] < posTo[1]) {
                move(sb, 'R', posFrom[1], posTo[1], 1);
            }
            else {
                move(sb, 'L', posFrom[1], posTo[1], -1);
            }
        }
    }

    private void move(StringBuilder sb, char direction, int from, int to, int inc) {
        int i = from;
        while (i != to) {
            i += inc;
            sb.append(direction);
        }
    }

    private int[] getPos(int from) {
        int x = from / 5;
        int y = from % 5;
        return new int[] { x, y };
    }
}
__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public String alphabetBoardPath(String target) {
        int l=target.length(),i,c=0,p=0,zp,zc;
        String st="";
        
        for(i=0;i<l;i++)
        {
            c=target.charAt(i)-97;
            zc=c/5;
            zp=p/5;
                if(c==25)
                {
                    while(p!=c)
                    {
                   while(zp<4)
                    {
                    st+="D";
                    zp++;p+=5;
                    } 
                    while(p>20)
                    {
                    st+="L";
                    p--;
                    }
                    st+="D";p+=5;
                    }
                }
                else
                {
                    while(p!=c)
                    {
                    while(zp>zc)
                    {
                    st+="U";
                    p-=5;zp--;
                
                    }
                    while(zp<zc)
                    {
                    st+="D";
                    zp++;p+=5;
                    }
                    while(p>c)
                    {
                    st+="L";
                    p--;    
                    }
                    while(p<c)
                    {
                    st+="R";
                    p++;
                    }
                        //st+="!";
                    }
                }
            st+="!";
            
            }
        return st;
    }
}
__________________________________________________________________________________________________
sample 2 ms submission
class Solution {
    public String alphabetBoardPath(String target) {
        return helper(0,0,target,0,"");
    }
    
    private String helper(int curi, int curj, String target, int index, String res){
        if (index == target.length()) return res;
        char ch = target.charAt(index);
        int nexti = (ch-'a')/5, nextj = (ch-'a')%5;
        if(nexti == curi && curj == nextj){
            res += "!";
            index ++;
        }else{
           while(curj > nextj){
                res += "L";
                curj--;
            } 
            
           while(curi > nexti){
                res += "U";
                curi --;
            }
            
            while(curj < nextj){
                res += "R";
                curj++;
            }
            
            while(curi < nexti){
                res += "D";
                curi++;
            }
        }
        
        return helper(nexti,nextj,target,index,res);
    }
}