__________________________________________________________________________________________________
0ms
class Solution {
    // there is this info: size. and we know only size number of can be possible value there. 
    public int firstMissingPositiveV1(int[] nums) {
        int n = nums.length; 
        
        // put the value into the valueth index. Keep doing that until the value get all positioned into the right poisition. Like: [3,1,6] => [1,1,3]
        for (int i = 0; i < n; ++i) {
            int temp = nums[i];
            while(temp >= 1 && temp <= n && nums[temp - 1] != temp) {
                int newTemp = nums[temp - 1];
                nums[temp - 1] = temp;
                temp = newTemp;
            }
        }
        
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        
        return n + 1;
    }
    
    
    // or using swap. 
    public int firstMissingPositive(int[] nums) {
        int n = nums.length; 
        
        for (int i = 0; i < n; ++i) {
            
            while(nums[i] >= 1 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                int temp = nums[i];
                nums[i] = nums[nums[i] - 1];
                nums[temp - 1] = temp;   
            }
        }
        
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        
        return n + 1;
    }
}
__________________________________________________________________________________________________
2ms
class Solution {
    public int firstMissingPositive(int[] nums) {
        Set<Integer> set = new HashSet<>();
        for(int n : nums) { 
            set.add(n);              
        }
        int min = 1;
        while(set.contains(min)) {
                set.remove(min);
                min++;       
        }
        return min;
    }
}
__________________________________________________________________________________________________
4ms
class Solution {

    public int firstMissingPositive(int[] a) {
        if(a.length == 0)
            return 1;
        //move new and zero back;
        int st =0; 
        int end = a.length -1;
        
        while(st<= end) {
            if(a[st] >= 1)
                st++;
            else {
                swap(a, st, end);
                end--;
            }
        }
      //   System.out.println("st " + st);
        for(int i =0; i< st; i++) {
            //duplicate, greator than
            int current = getInt(a, i);
            if(current == i || current >= st) {
                continue;
            }else {
                //dupliate
                int next = getInt(a, current);
                if(next == current)
                    continue;
                swap(a, current, i);
                i--;
            }    
        }
        
        int i =1;
        System.out.println(Arrays.toString(a));
        for(i = 0; i< st; i++) {
            if(a[i] == i + 1)
                continue;
            else {
                return i +1;
            }
        }
        return st +1;
    }
    
    int getInt(int[] a, int i) {
        return a[i] -1;
    }
    
    void swap(int[] a, int i, int j) {
        int tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
    }
}
__________________________________________________________________________________________________
34236 kb
class Solution {
    public int firstMissingPositive(int[] nums) {
      int n = nums.length; 
        for (int i = 0; i < n; i++) {
            int cur = nums[i]; 
            while (cur > 0 && cur <= n && nums[cur - 1] != cur) {
                int next = nums[cur - 1]; 
                nums[cur - 1] = cur;
                cur = next; 
            }
        }
        for (int i = 0; i < n; i++) 
            if (nums[i] != i + 1) return i + 1; 
        return n + 1; 
    }
}
__________________________________________________________________________________________________
34332 kb
class Solution {
    public int firstMissingPositive(int[] nums) {
        int min=1;
        int i=0,tail=nums.length-1;
        while(i<=tail){
            if(nums[i]<=0||nums[i]-1>=nums.length) { swap(nums,i,tail); tail--;}
            else if(nums[i]==nums[nums[i]-1]) i++;
            else swap(nums,i,nums[i]-1);
        }
        for(int n:nums){
            if(n!=min) return min;
            min++;
        }
        return min;
    }
    
    private void swap(int[] nums, int i, int end) {
        int temp = nums[i];
        nums[i] = nums[end];
        nums[end] = temp;
    }
}
__________________________________________________________________________________________________