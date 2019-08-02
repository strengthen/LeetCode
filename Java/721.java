__________________________________________________________________________________________________
sample 19 ms submission
class Solution {
    Map<String, Integer> map = new HashMap<>();
    private int[] iParent;
    public List<List<String>> accountsMerge(List<List<String>> accounts) {
        List<List<String>> res = new ArrayList<>();

        iParent = new int[accounts.size()];
        for(int i = 0;i<iParent.length;i++)
            iParent[i] = i;

        int j = 0;
        for(List<String> acc:accounts){
            for(int i = 1, l = acc.size();i<l;i++){
                Integer v = map.putIfAbsent(acc.get(i),j);
                if(v != null)
                    union(v,j);
            }
            j++;
        }
        ArrayList<String>[] d= new ArrayList[accounts.size()];

        for(Map.Entry<String, Integer> e:map.entrySet())
        {
            int inx = getParent(e.getValue());
            if(d[inx] == null) {
                d[inx] = new ArrayList<>();
                //d[inx].add(accounts.get(inx).get(0));
            }
            d[inx].add(e.getKey());
        }

        for (int i = 0; i < d.length; i++) {
            if(d[i] != null){
                List<String> l = new ArrayList<>();
                l.add(accounts.get(i).get(0));
                Collections.sort(d[i]);
                l.addAll(d[i]);
                res.add(l);

            }
        }

        return res;
    }

    private void union(int v, int j){
        iParent[getParent(j)] = getParent(v);
    }

    private int getParent(int j){
        int p = iParent[j];
        while(p != iParent[p]){
            p = iParent[p];
            iParent[j] = p;
        }
        return p;        
    }
}
__________________________________________________________________________________________________
sample 41764 kb submission
class Solution {
    public List<List<String>> accountsMerge(List<List<String>> accounts) {
        List<List<String>> rst = new ArrayList<List<String>>();
        if (accounts == null || accounts.size() == 0) {
            return rst;
        }
        Map<String, String> owner = new HashMap<String, String>();
        Map<String, String> parent = new HashMap<String, String>();
        Map<String, TreeSet<String>> union = new HashMap<String, TreeSet<String>>();
        for (List<String> list : accounts) {
            for (int i = 1; i < list.size(); ++i) {
                parent.put(list.get(i), list.get(1));
                owner.put(list.get(i), list.get(0));
            }
        }
        for (List<String> list : accounts) {
            String key = find(list.get(1), parent);
            for (int i = 2; i < list.size(); ++i) {
                parent.put(find(list.get(i), parent), key);
            }
        }
        for (List<String> list : accounts) {
            String key = find(list.get(1), parent);
            for (int i = 1; i < list.size(); ++i) {
                union.computeIfAbsent(key, t->new TreeSet<String>()).add(list.get(i));
            }
        }
        for (String key : union.keySet()) {
            List<String> email = new ArrayList<String>(union.get(key));
            email.add(0, owner.get(key));
            rst.add(email);
        }
        return rst;
    }
    private String find(String str, Map<String, String> map) {
        if (map.get(str) != str) {
            map.put(str, find(map.get(str), map));
        }
        return map.get(str);
    }
}
__________________________________________________________________________________________________
