__________________________________________________________________________________________________
//runtime: 0ms, memory: 2.5MB

impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        use std::collections::HashMap;
        let mut hash = HashMap::new();
        for i in 0..nums.len() {
            if !hash.contains_key(&(target - nums[i])) {
                hash.insert(nums[i], i);
            } else {
                return vec![hash[&(target - nums[i])] as i32, i as i32];
            }
        }
        return vec![];
    }
}
__________________________________________________________________________________________________

__________________________________________________________________________________________________
