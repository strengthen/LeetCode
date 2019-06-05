__________________________________________________________________________________________________
sample 0 ms submission
public class Solution {
    public String decodeString(String s) {
        int n = s.length();
        char[] ss = s.toCharArray();
        Stack<Integer> counts = new Stack<Integer>();
        Stack<String> strings = new Stack<String>();
        StringBuilder result = new StringBuilder();
        int count = 0;
        //当前需要解码，但是还没有遇到]暂存的
        String currentString = "";
        for(int i=0;i<n;i++){
            if(ss[i]>='0' && ss[i]<='9'){
                count = count * 10;
                count = count + ss[i] -'0';
            } else if(ss[i] == '['){
                counts.push(count);
                count = 0;
                strings.push(currentString);
                currentString = "";
            }else if(ss[i] >='a' && ss[i]<='z' ||ss[i] >='A' && ss[i]<='Z'){
                //注意栈空与否很重要
                if(!counts.isEmpty())
                    currentString += ss[i];
                else result.append(ss[i]);
            } else if(ss[i] == ']'){
                int times = counts.pop();
                if(counts.isEmpty()){
                    for(int j=0;j<times;j++)
                        result.append(currentString);
                     currentString=strings.pop();
                } else {
                    String tmp = "";
                    for(int j=0;j<times;j++)
                        tmp+=currentString;
                    currentString = strings.pop()+tmp;
                }

            }
        }
        return result.toString();
    }
}
__________________________________________________________________________________________________
sample 34528 kb submission
class Solution {
  
  private int idx;
  public String decodeString(String s) {
    
    char[] charArr = s.toCharArray();
    
    StringBuilder str = new StringBuilder();
    while (idx < charArr.length) {
      
      if (charArr[idx] >= '0' && charArr[idx] <= '9') {
        str.append(makeString(charArr));
      } else {
        str.append(charArr[idx++]);
      }
    }
    
    return str.toString();
  }
  
  private String makeString(char[] charArr) {
    
    // get times
    StringBuilder num = new StringBuilder();
    int times;
    while (charArr[idx] >= '0' && charArr[idx] <= '9') {
      num.append(charArr[idx++]);
    }
    times = Integer.valueOf(num.toString());
    
    // skip '[' useless character
    idx++;
    
    // get encoded String
    StringBuilder output = new StringBuilder();
    while (charArr[idx] != ']') {
      if (charArr[idx] >= '0' && charArr[idx] <= '9') {
        output.append(makeString(charArr));    
      } else {
        output.append(charArr[idx++]);
      }
    }
    
    // skip ']' character
    idx++;
    
    return Collections.nCopies(times, output.toString()).stream().collect(Collectors.joining(""));
  }
}
__________________________________________________________________________________________________
