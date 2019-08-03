__________________________________________________________________________________________________
sample 3 ms submission
class Solution {
  public int numUniqueEmails(String[] emails) {
    Set<String> set = new HashSet<String>();
    for(String e: emails) {
      set.add(normalize(e));
    }
    return set.size();
  }
  
  String normalize(String email) {
    char[] str = email.toCharArray();
    int len = 0;
    boolean localname = true;
    boolean ignore = false;
    for(char c: str) {
      if (c == '@') localname = false;
      if (localname) {
        if (ignore || c == '.') continue;
        if (c == '+') {
          ignore = true;
          continue;
        }
      }
      str[len++] = c;

    }
    //System.out.println(new String(str, 0, len));
    return new String(str, 0, len);
  }
}
__________________________________________________________________________________________________
sample 36136 kb submission
class Solution {
    public int numUniqueEmails(String[] emails) {
        int len = emails.length;
        if(len<1) return 0;
        HashMap<String, Set<String>> map = new HashMap<>();
        for(String s : emails){
            // s empty
            if(s.length()<1) continue;
            String[] ss = s.split("@");
            String front = ss[0];
            String domain = ss[1];
            //'+'
            String[] removepluss = front.split("\\+");
            String prefix = removepluss[0];
            //'.' 
            String[] removedot = prefix.split("\\.");
            StringBuilder cur = new StringBuilder();
            for(String i : removedot){
                cur.append(i);
            }
            String pre = cur.toString();
            if(map.containsKey(pre)){
                map.get(pre).add(domain);
            }
            else map.computeIfAbsent(pre,func->new HashSet<String>()).add(domain);
            
            
        }
        int count =0;
        for(String key : map.keySet()){
            count+=map.get(key).size();
        }
        return count;
    }
}
__________________________________________________________________________________________________
