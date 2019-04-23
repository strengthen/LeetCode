__________________________________________________________________________________________________
244ms
public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        Dictionary<int,int>dictionary=new Dictionary<int,int>();
        for(int i=0;i<nums.Length;i++){
            if (dictionary.ContainsKey(target-nums[i])){
                return new int[]{dictionary[target-nums[i]],i};
            }
            else{
                dictionary[nums[i]]=i;
            }
        }
        return null;  
    }
}
__________________________________________________________________________________________________
248ms
public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        int[] result = null;
        Dictionary<int,int> d = new Dictionary<int,int>();
        
        for(int i = 0; i < nums.Length; i++)
        {
            if(d.ContainsKey(target - nums[i]))
            {
                int val = d[target - nums[i]];
                result = new int[] {val, i};
                return result;
            }
            else
            {
                d[nums[i]] = i;
            }
        }
        
        return result;
    }
}
__________________________________________________________________________________________________
260ms
public class Solution {
    public int[] TwoSum(int[] nums, int target) 
    {
         Hashtable map = new Hashtable();

            for (int i = 0; i < nums.Length; i++)
            {
                try
                {
                map.Add(nums[i], i);
                }
                catch{}
            }
            for (int i = 0; i < nums.Length; i++)
            {
                int complement = target - nums[i];
                if (map.ContainsKey(complement) && (int)map[complement] != i)
                {
                    return new int[] { i, (int)map[complement] };
                }
            }
            throw new Exception("No two sum solution");
    }
}
__________________________________________________________________________________________________
264ms
public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        
        Dictionary<int, int> dict = new Dictionary<int, int>();
        
        for (int i = 0; i < nums.Length; i++)
        {
            int remain = target - nums[i];
            
            if (dict.ContainsKey(remain))
            {
                return new int[] {dict[remain], i};
            }
            
            if (!dict.ContainsKey(nums[i]))
            {
                dict.Add(nums[i], i);
            }            
        }
        
        return null;
    }
}
__________________________________________________________________________________________________
28324 kb
public class Solution {
    public int[] TwoSum(int[] nums, int target)
        {
            var l = 0;
            var u = nums.Length - 1;
            
            for (var i = 0; i < nums.Length; ++i)
                for (var j = i + 1; j < nums.Length; ++j)
                    if (nums[i] + nums[j] == target)
                        return new int[] { i, j };
        
            return null;
        }
}
__________________________________________________________________________________________________
