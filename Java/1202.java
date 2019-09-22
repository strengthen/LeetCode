__________________________________________________________________________________________________
class Solution {
    public String smallestStringWithSwaps(String s, List<List<Integer>> pairs) {
        int n = s.length();
        int[] index = new int[n];
        //intialize index 
        for(int i = 0; i < n; i++){
            index[i] = i;
        }
		//union all pairs 
        for(List<Integer> pair : pairs){
            int root1 = find(index, pair.get(0));
            int root2 = find(index, pair.get(1));
            if(root1 != root2){
                //union pair
                index[root1] = root2;
            }
        }
        //find all components and stored in map  
        Map<Integer, List<Integer>> map = new HashMap<>();
        for(int i = 0; i < n; i++){
            int root = find(index, i);
            if(!map.containsKey(root)){
                map.put(root, new ArrayList<>());
            }
            map.get(root).add(i);
        }
	
        char[] res = new char[n];
		//for each component, sort characters and place to res array 
        for(List<Integer> set : map.values()){
            List<Character> temp = new ArrayList<>();
            for(int i : set){
                temp.add(s.charAt(i));
            }
            Collections.sort(temp);
            int start = 0;
            for(int i : set){
                res[i] = temp.get(start);
                start++;
            }
        }
        return new String(res);
    }
	
    public int find(int[] index, int p){
        while(index[p] != p){
            index[p] = index[index[p]];
            p = index[p];
        }
        return p;
    }
}
__________________________________________________________________________________________________
sample 56 ms submission
class Solution {
    class DSU{
        int[] parent;

        public DSU(int N) {
            parent = new int[N];
            for (int i = 0; i < N; ++i) {
                parent[i] = i;
            }
        }

        public int find(int x) {
            if (parent[x] != x) parent[x] = find(parent[x]);
            return parent[x];
        }

        public void union(int x, int y) {
            parent[find(x)] = find(y);
        }
    }

    public String smallestStringWithSwaps(String str, List<List<Integer>> pairs) {
        int len = str.length();
        DSU uf = new DSU(len);
        for (List<Integer> i : pairs){
            uf.union(i.get(0), i.get(1));
        }
        char[] arr = str.toCharArray();
        Map<Integer, List<Integer>> map = new HashMap<>();
        for (int i = 0; i < len; ++i){
            if (!map.containsKey(uf.find(i))){
                map.put(uf.find(i), new ArrayList<>());
            }
            map.get(uf.find(i)).add(i);
        }
        for (int i : map.keySet()){
            List<Character> tmp = new ArrayList<>();
            for (int j : map.get(i)){
                tmp.add(arr[j]);
            }
            Collections.sort(tmp);
            Iterator<Character> iter = tmp.iterator();
            for (int j : map.get(i)){
                arr[j] = iter.next();
            }
        }
        return String.valueOf(arr);
    }
}
__________________________________________________________________________________________________
