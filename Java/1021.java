__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public String removeOuterParentheses(String S) {
        // asusume S would not be null
        char[] sChar = S.toCharArray();
        
        StringBuilder builder = new StringBuilder();
        
        int count = 1; // the count of "("
        
        for(int i = 1 ; i < sChar.length ; i++) {
            char ch = sChar[i];
            if( ch == '(' ) {
                count++;
            } else { // ch == ')'
                count--;
            }
            
            if(count == 0) { // outer start and end index
                i++;
                count = 1;
                continue;
            } else {
                builder.append( ch );
            }
        }
        
        return builder.toString();
    }
}
__________________________________________________________________________________________________
sample 34804 kb submission
class Solution {
    public String removeOuterParentheses(String S) {
                List<String> primitives = new ArrayList();
        int counter = 0;
        //Stack<Character> paranthesisStack = new Stack<Character>();
        StringBuilder primitiveBuilder = new StringBuilder();
        for (char c : S.toCharArray()) {
            if(c == '(') {
                counter++;
                primitiveBuilder.append(c);
            }
            if(c == ')'){
                counter--;
                primitiveBuilder.append(c);
            }
            if(counter == 0) {
                //primitive identified
                primitives.add(primitiveBuilder.toString());
                primitiveBuilder.setLength(0);
            }
        }
        List<String> updatedPrimitives = primitives.stream()
                .map( string -> string.substring(1,string.length()-1))
                .collect(Collectors.toList());

        primitiveBuilder.setLength(0);
        updatedPrimitives.stream().forEach(string -> primitiveBuilder.append(string));

        return primitiveBuilder.toString();
    }
}
__________________________________________________________________________________________________
