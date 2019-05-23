__________________________________________________________________________________________________
sample 11 ms submission
class Solution {
   
    
  public List<List<String>> findLadders(String beginWord, String endWord, List<String> wordList) {
        List<List<String>> result = new ArrayList<>(); 
        if (wordList == null) {
            return result; 
        }
        Set<String> dicts = new HashSet<>(wordList);
        if (!dicts.contains(endWord)) {
            return result; 
        }
        Set<String> start = new HashSet<>();
        Set<String> end = new HashSet<>();
        Map<String, List<String>> map = new HashMap<>();
        start.add(beginWord);
        end.add(endWord);
        bfs(map, start, end, dicts, false);
        List<String> subList = new ArrayList<>();
        subList.add(beginWord); 
        dfs(map, result, subList, beginWord, endWord);
        return result;
    }
    private void bfs(Map<String, List<String>> map, Set<String> start, Set<String> end, Set<String> dicts, boolean reverse) {
        // Processed all the word in start
        if (start.size() == 0) {
            return; 
        }
        dicts.removeAll(start);
        Set<String> tmp = new HashSet<>();
        boolean finish = false; 
        for (String str : start) {
            char[] chars = str.toCharArray();
            for (int i = 0; i < chars.length; i++) {
                char old = chars[i];
                for (char n = 'a' ; n <='z'; n++) {
                    if(old == n) {
                        continue; 
                    }
                    chars[i] = n;               
                    String candidate = new String(chars);
                    if (!dicts.contains(candidate)) {
                        continue;
                    }
                    if (end.contains(candidate)) {
                        finish = true; 
                    } else {
                        tmp.add(candidate);
                    }
                    String key = reverse ? candidate : str;
                    String value = reverse ? str : candidate;
                    if (! map.containsKey(key)) {
                        map.put(key, new ArrayList<>());
                    }
                    map.get(key).add(value);
                }
                // restore after processing
                chars[i] = old; 
            }
        }
        if (!finish) {
            // Switch the start and end if size from start is bigger;
            if (tmp.size() > end.size()) {
                bfs(map, end, tmp, dicts, !reverse);
            } else {
                bfs(map, tmp, end, dicts, reverse);
            }           
        }
    }
    private void dfs (Map<String, List<String>> map, 
                      List<List<String>> result , List<String> subList, 
                      String beginWord, String endWord) {
        if(beginWord.equals(endWord)) {
            result.add(new ArrayList<>(subList));
            return; 
        }
        if (!map.containsKey(beginWord)) {
            return; 
        }
        for (String word : map.get(beginWord)) {
            subList.add(word);
            dfs(map, result, subList, word, endWord);
            subList.remove(subList.size() - 1);
        }
    }
}
__________________________________________________________________________________________________
sample 36928 kb submission
public class Solution {

    public  List<List<String>> findLadders(String beginWord, String endWord, List<String> wordList) {
                
        List<List<String>> res = new ArrayList();
        
        if(wordList == null || wordList.size() == 0) {
            return res;
        }
        
        Set<String> start = new HashSet<>();
        Set<String> end = new HashSet<>(); 
        Set<String> dic = new HashSet<>(wordList);
        Map<String, List<String>> map = new HashMap();
        
        if(!dic.contains(endWord)) {
            return res;
        }
        
        start.add(beginWord);
        end.add(endWord);
        buildMap(start, end, false, dic, map);
        
        List<String> path = new ArrayList();
        path.add(beginWord);
        wordLadders(beginWord, endWord, path, map, res);
        return res;
    }
    
    public void buildMap(Set<String> start, Set<String> end, boolean reverse, Set<String> dic, Map<String, List<String>> map) {
        if(start.size() == 0) {
            return;
        }
        
        if(start.size() > end.size()) {
            buildMap(end, start, !reverse, dic, map);
            return;
        }
        
        dic.removeAll(start);
        Set<String> next = new HashSet();
        boolean finish = false;
        
        for(String s : start) {
            char[] arr = s.toCharArray();
            for(int i = 0; i < arr.length; i++) {
                char tmp = arr[i];
                for(char c = 'a'; c <= 'z'; c++){
                    if(tmp == c) {
                        continue;
                    }
                    
                    arr[i] = c;
                    String newStr = new String(arr);
                    
                    if(dic.contains(newStr)) {
                        if(end.contains(newStr)) {
                            finish = true;
                        } else {
                            next.add(newStr);
                        }
                        
                        String key = reverse ? newStr : s;
                        String val = reverse ? s : newStr;
                        map.computeIfAbsent(key, a -> new ArrayList()).add(val);
                    }
                }
                arr[i] = tmp;
            }
        }
        
        if(!finish) {
            buildMap(next, end, reverse, dic, map);
        }
    }
    
    public void wordLadders(String start, String end, List<String> path, Map<String, List<String>> map, List<List<String>> res) {
        if(start.equals(end)) {
            res.add(new ArrayList<>(path));
            return;
        }
        
        if(!map.containsKey(start)) {
            return;
        }
        
        for(String s : map.get(start)) {
            path.add(s);
            wordLadders(s, end, path, map, res);
            path.remove(path.size() - 1);
        }
    }
}
__________________________________________________________________________________________________
