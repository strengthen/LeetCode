__________________________________________________________________________________________________
sample 2 ms submission
class Solution {
public int[][] merge(int[][] intervals) {
        int length=intervals.length;
        if(length<=1)
            return intervals;
    
        int[] start = new int[length];
        int[] end = new int[length];
        for(int i=0;i<length;i++){
            start[i]=intervals[i][0];
            end[i]=intervals[i][1];
        }
        Arrays.sort(start);
        Arrays.sort(end);
        int startIndex=0;
        int endIndex=0;
        List<int[]> result = new LinkedList<>();
        while(endIndex<length){
            //as endIndex==length-1 is evaluated first, start[endIndex+1] will never hit out of index
            if(endIndex==length-1 || start[endIndex+1]>end[endIndex]){
                result.add(new int[]{start[startIndex],end[endIndex]});
                startIndex=endIndex+1;
            }
            endIndex++;
        }
        return result.toArray(new int[result.size()][]);
    }
}
__________________________________________________________________________________________________
sample 36624 kb submission
/**
 * Definition for an interval.
 * public class Interval {
 *     int start;
 *     int end;
 *     Interval() { start = 0; end = 0; }
 *     Interval(int s, int e) { start = s; end = e; }
 * }
 */
class Solution{
    public List<Interval> merge(List<Interval> intervals) {
        
        
        if(intervals.size() == 0)
            return Collections.emptyList();
        if(intervals.size() == 1)
            return intervals;
        // heap sort the thing
        
        build_heap(intervals);
        heap_sort(intervals);
        
        
        int start_num = intervals.get(0).start;
        int end_num = intervals.get(0).end;
        List<Interval> return_list = new ArrayList<>();
        
        for(int i=1; i<intervals.size(); i++){
            if(end_num >= intervals.get(i).start){
                end_num = intervals.get(i).end > end_num ? intervals.get(i).end : end_num;
            } 
            else{
                return_list.add(new Interval(start_num, end_num));  
                start_num = intervals.get(i).start;
                end_num = intervals.get(i).end;
            }
        }
        return_list.add(new Interval(start_num, end_num));
        
        return return_list;
    }
    
    public void heap_sort(List<Interval> intervals){
        for(int i=intervals.size()-1; i>=0; i--){
            swap(intervals, 0, i);
            max_heapify(intervals,0,i-1);
        }
    }
    
    
    public void build_heap(List<Interval> intervals){
        Double largest_non_leaf_double = Math.floor((intervals.size() - 2) / 2);
        int largest_non_leaf = largest_non_leaf_double.intValue();
        
        for(int i = largest_non_leaf; i >= 0; i--){
            max_heapify(intervals, i, intervals.size()-1);
        }
    }
    
    public void max_heapify(List<Interval> intervals, int root_index, int max_index){
        
        int max_child_index = -1;
        
        int left_index = root_index * 2 + 1;
        int right_index = left_index + 1;
        
        if(left_index <= max_index && right_index <= max_index){
            if(intervals.get(left_index).start > intervals.get(root_index).start || intervals.get(right_index).start > intervals.get(root_index).start){
                max_child_index = intervals.get(left_index).start > intervals.get(right_index).start ? left_index : right_index;
                swap(intervals, root_index, max_child_index);
                max_heapify(intervals, max_child_index, max_index);
            }
        }
        else if(left_index <= max_index){
            if(intervals.get(left_index).start > intervals.get(root_index).start)
                swap(intervals, root_index, left_index);
        }else if(right_index <= max_index){
            if(intervals.get(right_index).start > intervals.get(root_index).start)
                swap(intervals, root_index, right_index);
        }
    }
    
    
    public void swap(List<Interval> intervals, int a_index, int b_index){
        Interval temp = intervals.get(a_index);
        intervals.set(a_index, intervals.get(b_index));
        intervals.set(b_index, temp);
    }
}
__________________________________________________________________________________________________
