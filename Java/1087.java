__________________________________________________________________________________________________
class Solution {		
    public String[] permute(String S) {
        char[] s = S.toCharArray();
        int pos = 0;
        List<String> ret = new ArrayList<>();
        ret.add("");
        while(pos < s.length){
            List<String> next = new ArrayList<>();
            if(s[pos] == '{'){
                pos++;
                while(true){
                    String w = "";
                    while(s[pos] != ',' && s[pos] != '}' && s[pos] != '{'){
                        w += s[pos];
                        pos++;
                    }
                    for(String r : ret){
                        next.add(r + w);
                    }
                    
                    if(s[pos] == ','){
                        pos++;
                    }else{
                        pos++;
                        break;
                    }
                }
            }else{
                String w = "";
                while(pos < s.length && s[pos] != ',' && s[pos] != '}' && s[pos] != '{'){
                    w += s[pos];
                    pos++;
                }
                for(String r : ret){
                    next.add(r + w);
                }
            }
            ret = next;
        }
        Collections.sort(ret);
        String[] res = new String[ret.size()];
        for(int i = 0;i < ret.size();i++){
            res[i] = ret.get(i);
        }
        return res;
    }
}
__________________________________________________________________________________________________

__________________________________________________________________________________________________
