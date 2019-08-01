__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    private String upperRow = "qwertyuiop";
    private String middleRow = "asdfghjkl";
    private String lowerRow = "zxcvbnm";

    private boolean isMadeFromRow(String s, String row) {
        for(int i = 0; i < s.length(); i++) {
            if(row.indexOf(s.charAt(i)) == -1) {
                return false;
            }
        }

        return true;
    }

    private boolean isValid(String s)
    {
        s = s.toLowerCase();

        return isMadeFromRow(s, lowerRow) || isMadeFromRow(s, middleRow) || isMadeFromRow(s, upperRow);
    }

    public String[] findWords(String[] words) {
        ArrayList<String> list = new ArrayList<String>();
        String[] result;

        for(int i = 0; i < words.length; i++) {
            if(isValid(words[i])) {
                list.add(words[i]);
            }
        }

        result = new String[list.size()];

        for(int i = 0; i < list.size(); i++) {
            result[i] = list.get(i);
        }

        return result;
    }
}
__________________________________________________________________________________________________
sample 34484 kb submission
class Solution {
    public String[] findWords(String[] words) {
        
        List<Set<String>> rowMap = new ArrayList<>();
        createRowMap(rowMap);
        
        List<String> result = new ArrayList<>();
        //each word
        for(String word: words){
            //check each keyboard row
            for(Set<String> row: rowMap){
                    
                if(whetherExistInRow(word, row)){
                    result.add(word);
                    break;
                }
            }
            
        }
        
        return result.stream().toArray(String[]::new);
    }
    
    private boolean whetherExistInRow(String word, Set<String> row){
        
        //check characters
        for(int i =0; i < word.length(); i++){
            String ch = word.substring(i,i+1).toLowerCase();
            if(!row.contains(ch)){
                return false;
            }
        }
        
        return true;
    }
    
    private void createRowMap(List<Set<String>> rowMap){
        Set<String> row1 = new HashSet<>();
        row1.add("q");
        row1.add("w");
        row1.add("e");
        row1.add("r");
        row1.add("t");
        row1.add("y");
        row1.add("u");
        row1.add("i");
        row1.add("o");
        row1.add("p");
        
        rowMap.add(row1);
        
        Set<String> row2 = new HashSet<>();
        row2.add("a");
        row2.add("s");
        row2.add("d");
        row2.add("f");
        row2.add("g");
        row2.add("h");
        row2.add("j");
        row2.add("k");
        row2.add("l");
        
        rowMap.add(row2);
        
        Set<String> row3 = new HashSet<>();
        row3.add("z");
        row3.add("x");
        row3.add("c");
        row3.add("v");
        row3.add("b");
        row3.add("n");
        row3.add("m");
        
        rowMap.add(row3);
    }
}
__________________________________________________________________________________________________
