__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
    public int totalFruit(int[] tree) {
        if(tree.length==0){
            return 0;
        }
        int present = tree[0];
        int present_index= 0;
        int index = 1, start=0, maxLen = 0;
        while(index<tree.length && tree[index]==present){
            index++;
        }
        if(index==tree.length){
            return index-start;
        }
        int previous = present;
        int previous_index = index-1;
        present = tree[index];
        present_index = index;
        while(index<tree.length){
            if(tree[index]==previous){
                previous = present;
                present = tree[index];
                present_index = index;
            }
            else if(tree[index]!=present){
                maxLen = Math.max(index-start, maxLen);
                start = present_index;
                previous = present;
                present = tree[index];
                present_index = index;
            }
            index++;
        }
        return Math.max(maxLen, index-start);
        
    }
}
__________________________________________________________________________________________________
sample 43216 kb submission
class Solution {
    
    /*
    add to j
    if map moe than 2
        then move i;
    update ans
    */
    
    public class CountMap {
        HashMap<Integer, Integer> map;
        
        public CountMap() {
            map = new HashMap();
        }
        
        public int size() {
            return map.size();
        }
        
        public int get(int k) {
            if(!map.containsKey(k)) {
                map.put(k,0);
            }
            return map.get(k);
        }
        
        public void put(int k, int v) {
            int val = get(k) + v;
            if (val == 0) {
                map.remove(k);
            } else {
                map.put(k, val);
            }
        }
    }
    public int totalFruit(int[] tree) {
        int ans = 0;
        int f = 0;
        CountMap map = new CountMap();
        for (int s = 0; s < tree.length; s++) {
            map.put(tree[s], 1);
            while(map.size() > 2) {
                map.put(tree[f++], -1);
            }
            ans = Math.max(ans, s-f+1);
        }
        return ans;
    }
    
    public int totalFruit(int[] tree, int i) {
        /*
        0 - 1
        1 - 2
        2 - 1
        
        
        
        */
        
        int a = Integer.MIN_VALUE, b = Integer.MIN_VALUE;
        int ans = 0;
        for (; i < tree.length; i++) {
            if (tree[i] == a || tree[i] == b)   {
                ans++;
                continue;
            }
            if (a == Integer.MIN_VALUE) {
                a = tree[i];
                ans++;
            } else if (b == Integer.MIN_VALUE) {
                b = tree[i];
                ans++;
            } else {
                break;
            }
        }
        
        return ans;
    }
}
__________________________________________________________________________________________________
