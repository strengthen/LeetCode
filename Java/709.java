__________________________________________________________________________________________________
0ms
class Solution {
    public String toLowerCase(String str) {
        /*//solution1
        str=str.toLowerCase();
        return str;*/

        /*solution2
        char[] newStr = str.toCharArray();
        for(int i = 0; i < newStr.length; i++)
        {
            if(newStr[i] >= 'A' && newStr[i] <= 'Z')
            {
                newStr[i] += 32;
            }
        }
        return new String(newStr);
        */
        
        //solution3
        if(str.length() == 1)
        {
            char tmp[] = str.toCharArray();
            if(tmp[0] >= 'A' && tmp[0] <= 'Z')
            {
                tmp[0] += 32;
            }
            return new String(tmp);
        }else{
            int mid = str.length()/2;
            String str1 = "", str2 = "";
            str1 = str.substring(0, mid);
            str2 = str.substring(mid);
            return toLowerCase(str1)+toLowerCase(str2);
        }
    }
}
__________________________________________________________________________________________________
sample 33272 kb submission
class Solution {
    public String toLowerCase(String str) {
        return Stream.of(str).map(String::toLowerCase).collect(Collectors.joining(""));

    }
}
__________________________________________________________________________________________________
