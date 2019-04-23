__________________________________________________________________________________________________
0ms
class Solution {
    public String countAndSay(int n) {
        String current = "1";
        for (int i = 1; i < n; i++)
            current = counter(current);
        return current;
    }

    public String counter(String n) {
        char[] digits = n.toCharArray();

        StringBuilder sb = new StringBuilder();
        char prev = '\0';
        int counter = 0;
        for (char digit : digits) {
            if (digit == prev) {
                counter++;
            } else {
                if (prev != '\0')
                    sb.append(counter).append(prev);
                prev = digit;
                counter = 1;
            }
        }

        return sb.append(counter).append(prev).toString();
    }

    public static void main(String[] args) {
        System.out.println(new Solution().countAndSay(1024));
    }
}
__________________________________________________________________________________________________
1ms
public class Solution {
    public String countAndSay(int n) {
        if (n <= 0) {
            return "";
        }
        StringBuilder sb = new StringBuilder();
        sb.append(1);
        while (--n > 0) {
            char[] prev = sb.toString().toCharArray();
            sb.setLength(0);
            for (int i = 0; i < prev.length; ++i) {
                int cnt = 1;
                while (i + 1 < prev.length && prev[i] == prev[i+1]) {
                    i++;
                    cnt++;
                }
                sb.append(cnt);
                sb.append(prev[i]);
            }
        }
        return sb.toString();
    }
}
__________________________________________________________________________________________________
2ms
class Solution {
    public String countAndSay(int n) {
        String str = "1";
        for (int i = 2; i <= n; i++) {
            StringBuilder builder = new StringBuilder();
            int count = 1;
            char currentCh = str.charAt(0);
            for (int j = 1; j < str.length(); j++) {
                if (currentCh == str.charAt(j)) {
                    count++;
                } else {
                    builder.append(String.valueOf(count));
                    builder.append(currentCh);
                    currentCh = str.charAt(j);
                    count = 1;
                }
            }
            builder.append(String.valueOf(count));
            builder.append(currentCh);
            str = builder.toString();
        }
        return str;
    }
}
__________________________________________________________________________________________________
34264 kb
public class Solution {
    public String countAndSay(int n) {
        String s = "1";
        for(int i = 1; i < n; i++){
            s = countIdx(s);
        }
        return s;
    }
    
    public String countIdx(String s){
        StringBuilder sb = new StringBuilder();
        char c = s.charAt(0);
        int count = 1;
        for(int i = 1; i < s.length(); i++){
            if(s.charAt(i) == c){
                count++;
            }
            else
            {
                sb.append(count);
                sb.append(c);
                c = s.charAt(i);
                count = 1;
            }
        }
        sb.append(count);
        sb.append(c);
        return sb.toString();
    }
}
__________________________________________________________________________________________________
36416 k
class Solution {
    public String countAndSay(int n) {
        String cur = "1";
        while(--n>0){
            int count = 1;
            StringBuilder sb = new StringBuilder();
            for(int i = 0; i<cur.length(); i++){
                if(i==cur.length()-1 || cur.charAt(i)!=cur.charAt(i+1)){
                    sb.append(count).append(cur.charAt(i));
                    count=1;
                }else{
                    count++;
                }
            }
            cur = sb.toString();
        }
        return cur;
    }
}
__________________________________________________________________________________________________