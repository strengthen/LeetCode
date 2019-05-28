__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public int[] twoSum(int[] numbers, int target) {
        
        int first = 0, last = numbers.length-1;
        
        while(numbers[first] + numbers[last] != target) {
            if(numbers[first] + numbers[last] < target)
                first++;
            else
                last--;
        }
        
        return new int[]{first+1, last+1};
    }
}
__________________________________________________________________________________________________
sample 34776 kb submission
class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int[] answer = new int[2];
        Map<Integer, Integer> map = new HashMap<Integer, Integer>();
        for (int i = 0; i < numbers.length; i++) {
            if (map.containsKey(target - numbers[i])) {
                answer[0] = map.get(target - numbers[i]) + 1;
                answer[1] = i + 1;
            }
            map.put(numbers[i], i);
        }
        return answer;
    }
}
__________________________________________________________________________________________________
