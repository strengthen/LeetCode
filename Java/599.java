__________________________________________________________________________________________________
sample 5 ms submission
class Solution {
    public String[] findRestaurant(String[] list1, String[] list2) {
        if(list1.length == 0 || list2.length == 0) return new String[0];
        if(list1.length > list2.length) return findRestaurant(list2,list1);
        
        Map<String,Integer> map = new HashMap();
        for(int i = 0; i < list1.length;i++){
            map.put(list1[i],i);
        }
        int minSum = list1.length + list2.length;
        int count = 0;
        for(int i = 0; i < list2.length && i <= minSum; i++){
            Integer idx1 = map.get(list2[i]);
            if(idx1 != null){
                int sum = idx1+i;
                if(minSum > sum) {
                    count = 0;
                    minSum = sum;
                    list1[count++] = list2[i];
                }else if(minSum == sum){
                    list1[count++] = list2[i];
                }
            }
        }
        return Arrays.copyOfRange(list1,0,count);
    }
}
__________________________________________________________________________________________________
sample 37304 kb submission
class Solution {
    public String[] findRestaurant(String[] list1, String[] list2) {
        
        int minSum = Integer.MAX_VALUE;
        Map<String, Integer> map1 = new HashMap<>();
        
        
        for(int i = 0 ; i < list1.length; i++){
            if(!map1.containsKey(list1[i])){
                map1.put(list1[i], i);
            }
        }
        
        // map1.forEach((k,v) -> System.out.println(k + " -> "+ v));
        List<String> out = new ArrayList<>();
        for(int i = 0 ; i < list2.length; i++){
            
            if(map1.containsKey(list2[i])){
                int sum = map1.get(list2[i]) + i;
                if(sum < minSum){
                    minSum = sum;
                    out.clear();
                             out.add(list2[i]);
                } else if( sum == minSum){
                    out.add(list2[i]);
                }
            }
        }
        
        // out.forEach(e -> System.out.println(e));
        
        return out.stream().toArray(String[]::new);
    }
}
__________________________________________________________________________________________________
