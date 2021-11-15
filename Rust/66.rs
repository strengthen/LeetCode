__________________________________________________________________________________________________
//runtime: 0ms, memory: 2.1MB

impl Solution {
    pub fn plus_one(mut digits: Vec<i32>) -> Vec<i32> {
        let mut i = digits.len() - 1;
        loop {
            if digits[i] < 9 {
                digits[i] += 1;
                return digits;
            }
            digits[i] = 0;
            if i > 0 {
                i -= 1;
            } else if i == 0 {
                break;
            }
        }
        digits = vec![0; digits.len() + 1];
        digits[0] = 1;
        return digits;
    }
}
__________________________________________________________________________________________________

__________________________________________________________________________________________________
