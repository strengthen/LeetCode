__________________________________________________________________________________________________
sample 153 ms submission
class TimeMap {

    /** Initialize your data structure here. */
    List<dsImp> listDS = new ArrayList<dsImp>();
    public TimeMap() {
        
    }
    
    public class dsImp {
        public String key;
        public String value;
        public int timestamp;
        dsImp(String inkey, String invalue, int intimestamp) {
            key = inkey;
            value = invalue;
            timestamp = intimestamp;
        }
    }
    
    public void set(String key, String value, int timestamp) {
        listDS.add(new dsImp(key,value,timestamp));
    }
    
    public String get(String key, int timestamp) {
        if (listDS.isEmpty())
            return "";
        if (listDS.get(0).timestamp > timestamp)
            return "";
        int pos = 0;
        if (listDS.get(listDS.size()-1).timestamp > timestamp)
        {
        pos = this.bin(0, listDS.size(), timestamp, listDS);
        boolean b = true;
        while(b)
        {
            if (listDS.size() > pos+1)
            {
                if(listDS.get(pos).timestamp == listDS.get(pos+1).timestamp)
                {
                    pos++;
                }
                else
                    b = false;
            }
            else
                b= false;
        }
        }
        else
            pos = listDS.size()-1;
        if (pos == listDS.size())
            pos--;
        while(pos >= 0)
        {
            if (listDS.get(pos).key.equals(key))
                return listDS.get(pos).value;
            pos--;
        }
        return "";
    }
    public  int bin(int min, int max, int t, List<dsImp> listDS) {
        int half = (min + max)/2;
        if (t == listDS.get(half).timestamp)
            return half;
        if (min == max-1)
            return max-1;
        if (t < listDS.get(half).timestamp)
            return bin(min, half,t,listDS);
        else
            return bin(half, max,t,listDS);
    }
}

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap obj = new TimeMap();
 * obj.set(key,value,timestamp);
 * String param_2 = obj.get(key,timestamp);
 */
__________________________________________________________________________________________________
sample 125088 kb submission
import java.util.*;
import javafx.util.Pair;

// my origin solution, pretty good, can be better with binary search
// "The timestamps for all TimeMap.set operations are strictly increasing." means no need to sort while inserting
// "1 <= timestamp <= 10^7" means we can use timestamp as array index, won't overflow
// mistakes made: 1) tried to use Map<key, String[]>
//                   String[] with timestamp as index and value as value 
//                   so every key will have an 10^7 lenth array, memory limit exceed
//                2) tried to use Map<key, ArrayList<timestamp, value>>
//                   we can't add value as values.add(timestamp, value)
//                   we can at most add(list.length, value), otherwise it's outOfBound
//                   so there's nowhere to store the timestamp during set()
// 用嵌套hashmap来保存key, timestamp, value
// 查找时直接用输入的timestamp来向下遍历查找，直到对应的time-value map中有值为止
// 但如果给的timestamp很大，就造成很多次无用查找，这里可以使用binary search来提高效率，见下一个class
class TimeMap1 {    
    /** Initialize your data structure here. */
    Map<String, Map<Integer,String>> store;
    public TimeMap1() {
        store = new HashMap<>();
    }
    
    public void set(String key, String value, int timestamp) {
        if(!store.containsKey(key)){
            store.put(key, new HashMap<Integer,String>());
        }
        store.get(key).put(timestamp,value);   
    }
    
    public String get(String key, int timestamp) {
        String value = "";
        if(store.containsKey(key)){
            for(int i=timestamp; i>=0; i--){
                if(store.get(key).containsKey(i)){
                    value = store.get(key).get(i);
                    break;
                }
            }            
        }
        return value;
    }
}


// 二分查找改进
// 我们用Map<key,List<Pair<timestamp,value>>>来纪录，用List来控制插入顺序，之前用的Map是无序的
// 由于set()的timestamp是严格增加的，所以我们的time-value list是升序的，可以直接进行二分查找
class TimeMap {    
    /** Initialize your data structure here. */
    Map<String, List<Pair<Integer,String>>> store;
    public TimeMap() {
        store = new HashMap<>();
    }
    
    public void set(String key, String value, int timestamp) {
        if(!store.containsKey(key)){
            store.put(key, new ArrayList<Pair<Integer,String>>());
        }
        store.get(key).add(new Pair(timestamp,value));
    }
    
    public String get(String key, int timestamp) {
        String value = "";
        // store contains key means time_value_pairs.size()>0
        if(store.containsKey(key)){          
            List<Pair<Integer,String>> time_value_pairs = store.get(key); 
            int index = binarySearch(time_value_pairs, timestamp);
            // 这里的判断比较复杂，首先考虑空list的情况，只要store contains key，对应的list的size就>0
            // 然后考虑index为0的情况，因为我们后面可能有index-1的操作
            // index==0: 一种情况是没找到，target比所有数都小，返回0代表应该在0处插入，不做操作，直接返回""
            //           一种情况是index=0对应的time刚好等于target，此时返回对应value
            // index!=0: 此时如果index与size相等(说明target比所有数都大)，index--
            //           或者如果index对应time不等于target(说明没找到，要在此处插入)，index--
            //           这里要先判断index与size相等的情况，否则去看list(index)会outOfBound
            //           其他的情况说明index对应time等于target，不需调整index，直接求value即可
            if(index==0 && time_value_pairs.get(index).getKey()==timestamp){
                value = time_value_pairs.get(index).getValue();
            }
            if(index!=0){
                if(index==time_value_pairs.size() ||
                time_value_pairs.get(index).getKey()!=timestamp){
                   index--;    
                }
                value = time_value_pairs.get(index).getValue();
            }
               
        }
        return value;
    }
    
    // 由于time-value list中timestamp没有重复
    // 我们的binarySearch如果找到timestamp就会返回相应的index
    // 如果没有找到则会返回应该插入的位置index (timestamp小于所有item会返回0，大于所有会返回list.size())
    // *函数input里需要specify List<Pair<Integer,String>>，否则time_value_pairs.get(mid)只会返回object
    public int binarySearch1(List<Pair<Integer,String>> time_value_pairs, int timestamp){
        int left = 0;
        int right = time_value_pairs.size();
        while(left < right){
            int mid = left + (right-left)/2;
            int curr_time = time_value_pairs.get(mid).getKey();

            if(curr_time == timestamp) return mid;
            else if(curr_time > timestamp) right = mid;
            else left = mid + 1;
        }
        return left;
    }
    
    // binary search 模板2
    public int binarySearch(List<Pair<Integer,String>> time_value_pairs, int timestamp){
        int left = 0;
        int right = time_value_pairs.size()-1;
        while(left <= right){
            int mid = left + (right-left)/2;
            int curr_time = time_value_pairs.get(mid).getKey();

            if(curr_time == timestamp) return mid;
            else if(curr_time > timestamp) right = mid-1;
            else left = mid + 1;
        }
        return left;
    }
}

// there's another solution using tree map, seems very simple
// may learn later

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap obj = new TimeMap();
 * obj.set(key,value,timestamp);
 * String param_2 = obj.get(key,timestamp);
 */
__________________________________________________________________________________________________
