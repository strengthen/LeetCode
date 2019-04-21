__________________________________________________________________________________________________
6ms
class Solution {
    int[] hash = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 47, 53, 59, 67, 71, 83, 89, 101, 107, 109, 113, 127, 131};
    public List<List<String>> groupAnagrams(String[] strs) {
        List<List<String>> res = new ArrayList();
        Map<Integer, List<String>> map = new HashMap();
        for(String s : strs){
            int hash = getHash(s);
            if(!map.containsKey(hash)){
                List<String> group = new ArrayList();
                map.put(hash, group);
                res.add(group);
            }
            map.get(hash).add(s);
        }
        return res;
    }
    private int getHash(String s){
        int hashValue = 1;
        for(int i = 0; i < s.length(); i++){
            hashValue *= hash[s.charAt(i) - 'a'];
        }
        return hashValue;
    }
}
__________________________________________________________________________________________________
7ms
class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        HashMap<String, List<String>> map = new HashMap<>();
        List<List<String>> anagramList = new ArrayList<>();
        for (String str : strs) {
            char[] arr = str.toCharArray();
            Arrays.sort(arr);
            String sorted = new String(arr);
            List<String> list = map.get(sorted);
            if (list == null) {
                list = new ArrayList<>();
                map.put(sorted, list);
                anagramList.add(list);
            }
            list.add(str);
        }
        return anagramList;
    }
}
__________________________________________________________________________________________________
8ms
class Solution {
    // sort the characters of the string to make them the same
    public List<List<String>> groupAnagrams(String[] strs) {
        List<List<String>> res = new ArrayList<>();
        if(strs == null || strs.length == 0)
        {
            return res;
        }
        Map<String, List<String>> map = new HashMap<String, List<String>>();
        for(String tmpStr : strs)
        {
            char[] tmpArr = tmpStr.toCharArray();
            Arrays.sort(tmpArr);
            String keyStr = String.valueOf(tmpArr);
            if(map.containsKey(keyStr))
            {
                map.get(keyStr).add(tmpStr);
            }
            else
            {
                map.put(keyStr, new ArrayList<>());
                map.get(keyStr).add(tmpStr);
            }
        }
        return new ArrayList(map.values());
    }
}
__________________________________________________________________________________________________
38392 kb
class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
    Map<String,List<String>> map = new HashMap<>();
    
        for(int i=0;i<strs.length;i++){
           char[] ch = strs[i].toCharArray();
            Arrays.sort(ch);
            
            List<String> nl = map.getOrDefault(new String(ch),new ArrayList<String>());
            nl.add(strs[i]);
            map.put(new String(ch),nl);
        }
        List<List<String>> result = new ArrayList<>(map.values());

     return result;
    }
}
__________________________________________________________________________________________________
38436 kb
class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        
        List<List<String>> result = new LinkedList<>();
        
        Map<String, List<String>> map = new HashMap<>();
        
        for(String str : strs)
        {
            char[] arr = new char[26];
            for(int i =0; i<str.length(); i++)
            {
                arr[str.charAt(i) - 'a']++;
            }
            
            String ns = new String(arr);
            
            if(!map.containsKey(ns))
            {
                List<String> al = new LinkedList<String>();
                map.put(ns, al);
                
            }
            
            map.get(ns).add(str);
        }
        result.addAll(map.values());
        
        return result;
    }
}
__________________________________________________________________________________________________