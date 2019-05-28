__________________________________________________________________________________________________
sample 35040 kb submission
public class Solution {
    public String convertToTitle(int columnNumber) {
        StringBuilder columnName = new StringBuilder(); 
        while (columnNumber > 0){
            int rem = columnNumber % 26; 
  
            if (rem == 0){ 
                columnName.append("Z"); 
                columnNumber = (columnNumber / 26) - 1; 
            }else{ 
                columnName.append((char)((rem - 1) + 'A')); 
                columnNumber = columnNumber / 26; 
            } 
        } 

        return columnName.reverse().toString();
    }
}
__________________________________________________________________________________________________
sample 35044 kb submission
class Solution {
    public String convertToTitle(int n) {
        StringBuilder builder = new StringBuilder();

        while (n > 0) {
            n--;
            builder.insert(0, (char) (n % 26 + 'A'));
            n /= 26;
        }
        
        return builder.toString();
    }
}
__________________________________________________________________________________________________
