__________________________________________________________________________________________________
sample 3 ms submission
class Solution {
    public String licenseKeyFormatting(String S, int K) {
        return solution2(S, K);
    }
    static StringBuilder sb=new StringBuilder();
    public String solution1(String s, int k) {
        int count=0; char c='0'; sb.setLength(0);
        for(int i=s.length()-1; i>-1; i--){
            c=s.charAt(i);
            if(c!='-') {
                sb.append(Character.toUpperCase(c));
                count++;
            }
            if(count==k) {
                sb.append('-');
                count=0;
            }
        }
        sb=sb.reverse();
        if(sb.length()!=0 && sb.charAt(0)=='-') 
            sb.deleteCharAt(0);
        return sb.toString();
    }
    public String solution2(String S, int K) {
         
        char[] original = S.toCharArray();
        
        int numberOfDashes = 0;
        for (int i = 0; i < original.length; i++) {
            char currentChar = original[i];
            if (currentChar == '-') {
                numberOfDashes++;
            }
        }
        int numberOfActualSymbols = S.length() - numberOfDashes;
        if (numberOfActualSymbols == 0) return "";
        int firstUnevenSubstringLength = numberOfActualSymbols % K;
        int numberOfNeededDashes = (numberOfActualSymbols / K - 1) 
            + (firstUnevenSubstringLength > 0 ? 1 : 0);
        
        char[] result = new char[numberOfActualSymbols + numberOfNeededDashes];
        
        int nextPositionToBeFilled = 0;
        int currentChunkLength = 0;

        int i = 0;     
        char currentChar;
        if (firstUnevenSubstringLength != 0) {
            for (; i < original.length; i++) {
                currentChar = original[i];
                if ('-' == currentChar) {
                    continue;
                }

                if (currentChar > 'Z') {
                    currentChar -= 32;
                }
                result[nextPositionToBeFilled] = currentChar;
                nextPositionToBeFilled++;
                currentChunkLength++;
                
                if (currentChunkLength == firstUnevenSubstringLength) {
                    currentChunkLength = 0;
                    i++;
                    break;
                }
            }
            
            if (nextPositionToBeFilled < result.length) {
                    result[nextPositionToBeFilled] = '-';
                    nextPositionToBeFilled++;
            }
        }

        for (; i < original.length; i++) {
            currentChar = original[i];
            if ('-' == currentChar) {
                continue;
            }
            if (currentChar > 'Z') {
                currentChar -= 32;
            }
            result[nextPositionToBeFilled] = currentChar;
            nextPositionToBeFilled++;
            currentChunkLength++;
            
            if (currentChunkLength == K 
                   && nextPositionToBeFilled < result.length) {
                result[nextPositionToBeFilled] = '-';
                nextPositionToBeFilled++;
                currentChunkLength = 0;
            } 
        }
        return String.valueOf(result);
    }
}
__________________________________________________________________________________________________
sample 37900 kb submission
class Solution {
    public String licenseKeyFormatting(String S, int K) {
        
         while (S.indexOf("-") >= 0) {
            S = S.replace("-", "");
        }
        StringBuilder s = new StringBuilder();
        char[] a = S.toCharArray();
        int firstDashIndex = a.length % K;
        for (int i=0; i < a.length; i++) {
            if (i != 0 && (i == firstDashIndex || (i-firstDashIndex)%K == 0))              s.append('-');
            s.append(Character.toUpperCase(a[i]));
        }
        return s.toString();  
        
    }
}
__________________________________________________________________________________________________
