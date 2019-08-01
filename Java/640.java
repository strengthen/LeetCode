__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public String solveEquation(String equation) {
        int indexEqual = equation.indexOf("=");
        String leftString=equation.substring(0,indexEqual);
        String rightString=equation.substring(indexEqual+1);
        int[] leftParts=parse(leftString);
        int[] rightParts=parse(rightString);
        if(leftParts[0]==rightParts[0]){
            if(leftParts[1]==rightParts[1]){
                return "Infinite solutions";
            }
            else{
                return "No solution";
            }
        }
        else{
            
            //System.out.println(rightParts[0]+","+rightParts[1]);
            int x = leftParts[0]-rightParts[0];
            int y = leftParts[1]-rightParts[1];
            int result= -y/x;
            return "x="+result;
        }
        
    }
    private int[] parseParts(String str,int start,int end){
        int[] result = new int[2];
        String partStr = str.substring(start,end);
        //System.out.println(partStr);
        if(partStr.equals("")) return result;
        int index=1;
        int length=partStr.length();
        if(partStr.indexOf("x")!=-1){
            index=0;
            length--;
        }
        int num=0;
        for(int i=0;i<length;i++){
            int current=partStr.charAt(i);
            num=num*10+(current-'0');
        }
        if(index==0&&length==0){
            num=1;
        }
        result[index]=num;
        return result;
    }
    private int[] parse(String str){
       int start=0;
       int[] result = new int[2];
       boolean plusFlag=true;
       while(start<str.length()){
           int posMinus = str.indexOf("-",start);
           if(posMinus==-1) posMinus=str.length();
           int posPlus =str.indexOf("+",start);
           if(posPlus==-1) posPlus=str.length();
           int pos=Math.min(posMinus,posPlus);
           int[] parts = parseParts(str,start,pos);
           ///System.out.println(parts[0]+","+parts[1]);
           if(plusFlag){
               result[0]+=parts[0];
               result[1]+=parts[1];
           }
           else{
               result[0]-=parts[0];
               result[1]-=parts[1];
           }
           if(posMinus!=str.length()&&pos==posMinus){
               plusFlag=false;
           }
           else{
               plusFlag=true;
           }
           start=pos+1;
       
       } 
       return result; 
        
    }
}
__________________________________________________________________________________________________
sample 35384 kb submission
class Solution {
    public String solveEquation(String equation) {
        String[] equations = equation.split("=");
        
        int countX = 0;
        int countD = 0;
        
        int[] left = countXD(equations[0]);
        int[] right = countXD(equations[1]);
        
        countX = left[0] - right[0];
        countD = right[1] - left[1];
        
        if(countX == 0) {
            return countD == 0 ? "Infinite solutions" : "No solution";
        }
        
        return "x=" + String.valueOf(countD / countX);
    }
    
    private int[] countXD(String eq) {
        boolean posi  = true;
        int countX = 0;
        int countD = 0;
        int tempSum = 0;
        
        for(int i = 0; i < eq.length(); i++) {
            char cur = eq.charAt(i);
            
            if(Character.isDigit(cur)) {
                tempSum = tempSum * 10 + (cur - '0');
            } else if(cur == 'x') {
                if(posi) {
                    if(i == 0 || !Character.isDigit(eq.charAt(i - 1))) {
                        countX += 1;
                    } else {
                        countX += tempSum;
                    }
                } else {
                    if(i == 0 || !Character.isDigit(eq.charAt(i - 1))) {
                        countX -= 1;
                    } else {
                        countX -= tempSum;
                    }
                }
                tempSum = 0;
            } else if(cur == '+' || cur == '-') {
                if(posi) {
                    countD += tempSum;
                } else {
                    countD -= tempSum;
                }
                tempSum = 0;
                posi = cur == '+' ? true : false;
            }
        }
        
        //post processing
        if(tempSum != 0) {
           if(posi) {
                countD += tempSum;
            } else {
                countD -= tempSum;
            } 
        }
        
        int[] result = new int[2];
        result[0] = countX;
        result[1] = countD;
        return result;
    }
}
__________________________________________________________________________________________________
