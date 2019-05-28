__________________________________________________________________________________________________
sample 3 ms submission
class Solution {
    public List<String> findRepeatedDnaSequences(String s) {
        char cs[] = s.toCharArray();
        int l = cs.length;
        if(l<=10){
            return new ArrayList<>();
        }
        byte d[] = new byte[85];

        d['C'] = 1;
        d['G'] = 2;
        d['T'] = 3;

        BitSet st = new BitSet(1048576);
        int v = 0;
        for(int i=0;i<10;++i){
            v = (v << 2)|d[cs[i]];
        }
        st.set(v);
        BitSet added = new BitSet(1048576);
        List<String> sta = new ArrayList<>(l>>1);
        for(int i=10; i< l ; ++i ){
            v = ((v << 2)&0xFFFFF)|d[cs[i]];     
            if(st.get(v)){
                if(!added.get(v)){
                    sta.add(new String(cs,i-9,10));
                    added.set(v);
                }
            }else {
                st.set(v);
            }
        }
        return sta;
    }
}
__________________________________________________________________________________________________
sample 36444 kb submission
class Solution {
    public List<String> findRepeatedDnaSequences(String s) {
        List<String> res = new ArrayList<>();
        if(s==null || s.length()<11) {
            return res;
        }
        
        int start = 0;
        BitSet bs = new BitSet();
        BitSet exists = new BitSet();
        for(int end=10; end<=s.length(); end++) {
            String str = s.substring(start, end);
            int val = getBitVal(str);
            if(bs.get(val) && !exists.get(val)) {
                res.add(str);
                exists.set(val);
            }
            bs.set(val);
            start++;
        }
        
        return res;
    }
    
    private int getBitVal(String str) {
        StringBuilder sb = new StringBuilder();
        for(int i=0; i<str.length(); i++){
            sb.append(getBinary(str.charAt(i)));
        }
        
        return Integer.parseInt(sb.toString(), 2);
    }
    
    private String getBinary(char c) {
        switch(c) {
            case 'A':
                return "00";
            case 'C':
                return "01";
            case 'G':
                return "10";
            case 'T':
                return "11";
        }
        
        return null;
    }
}
__________________________________________________________________________________________________
