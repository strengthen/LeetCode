__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public List<String> removeComments(String[] source) {
        boolean open = false;
        List<String> res = new ArrayList<>();
        StringBuilder sb = new StringBuilder();
        for(int i=0; i<source.length; i++){
            
            for(int j=0; j<source[i].length(); j++){
                if(!open){
                    if(j+1<source[i].length() && source[i].charAt(j)=='/' &&
                      (source[i].charAt(j+1)=='/'|| source[i].charAt(j+1)=='*')){
                        if(source[i].charAt(j+1)=='/'){
                            if(sb.length()>0){
                                res.add(sb.toString());
                                sb = new StringBuilder();
                            }
                            break;
                        }else{
                            open = true;
                            j++;
                        }
                    }else{
                        //add to current string builder
                        sb.append(source[i].charAt(j));
                    }    
                }else{
                    //find close condition and close the comment
                    if(j+1<source[i].length() && source[i].charAt(j)=='*' && source[i].charAt(j+1)=='/'){
                        open = false;
                        j++;
                    }
                }
                if(!open && j==source[i].length()-1 && sb.length()!=0){
                    res.add(sb.toString());
                    sb = new StringBuilder();
                }
            }
        }
        return res;
    }
}
__________________________________________________________________________________________________
sample 36972 kb submission
class Solution {
    public List<String> removeComments(String[] source) {
        boolean inBlock = false;
        StringBuilder newline = new StringBuilder();
        List<String> res = new ArrayList();
        for (String line: source) {
            int i = 0;
            char[] chars = line.toCharArray();
            if (!inBlock) {
                newline = new StringBuilder();
            }
            while (i < line.length()) {
                if (!inBlock && i+1 < line.length() && chars[i] == '/' && chars[i+1] == '*') {
                    inBlock = true;
                    i++;
                } else if (inBlock && i+1 < line.length() && chars[i] == '*' && chars[i+1] == '/') {
                    inBlock = false;
                    i++;
                } else if (!inBlock && i+1 < line.length() && chars[i] == '/' && chars[i+1] == '/') {
                    break;
                } else if (!inBlock) {
                    newline.append(chars[i]);
                }
                i++;
            }
            if (!inBlock && newline.length() > 0) {
                res.add(new String(newline));
            }
        }
        return res;
    }
}
__________________________________________________________________________________________________
