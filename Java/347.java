__________________________________________________________________________________________________
sample 7 ms submission
class Solution {
    public List<Integer> topKFrequent(int[] nums, int k) {
        Comparator<Value> comparator = new Comparator<Value>() {
            @Override
            public  int compare(Value int1, Value int2){
                return -(int1.times - int2.times);
            }
        };
        
        PriorityQueue<Value> heap = new PriorityQueue<>(nums.length, comparator);
        
        Arrays.sort(nums);
        int lastNum = nums[0];
        int total = 0;
        for(int num : nums){
            if(lastNum == num){
                total++;
            } else {
                heap.add(new Value(lastNum, total));
                total = 1;
                lastNum = num;
            }   
        }
        heap.add(new Value(lastNum, total));
        
        List<Integer> ans = new ArrayList<>();
        while(k > 0){
            ans.add(heap.remove().num);
            k--;
        }
        return ans;
        
        
    }
    
    class Value {
        int num;
        int times;
        
        Value(int num,int times){
            this.num = num;
            this.times = times;
        }
        
    }
}
__________________________________________________________________________________________________
sample 36496 kb submission
class Solution {
    public List<Integer> topKFrequent(int[] nums, int k) {
        
        HashMap<Integer, Integer> map = new HashMap();
        
        for(int i=0;i<nums.length;i++){
            if(!map.containsKey(nums[i]))
                map.put(nums[i], 1);
            else
                map.put(nums[i], map.get(nums[i])+1);
        }
        
        List<Map.Entry<Integer, Integer>> list = new ArrayList<>(map.entrySet()); 
        System.out.println(list);
        
        Collections.sort(list, (a,b)-> b.getValue()-a.getValue());
        
        System.out.println(list);
        
        List<Integer> temp = new ArrayList<>();
        for(int i=0;i<k;i++){
            temp.add(list.get(i).getKey());
        }
        
        System.out.println(temp);
        return temp;
    }
}
__________________________________________________________________________________________________
