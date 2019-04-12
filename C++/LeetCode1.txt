Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,
Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
_____________________________________________________________________________________________________________
给定一个整数数组和一个目标值，找出数组中和为目标值的两个数。你可以假设每个输入只对应一种答案，且同样的元素不能被重复利用。
示例:

给定 nums = [2, 7, 11, 15], target = 9
因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]
_____________________________________________________________________________________________________________
法1：暴力法。遍历每个元素x，并查找是否存在一个值与 target - xtarget−x 相等的目标元素。
 1 class Solution {
 2     func twoSum(_ nums: [Int], _ target: Int) -> [Int] {
 3         //创建一个初始化数据为空的数组用于返回
 4         var targetArray:[Int]=[Int]()
 5         //获取数组长度，减2用于遍历数组,注意最后一个的情况
 6         for addOne in 0...nums.count-2
 7         {
 8             //该值之后向后遍历，不支持运算符<..
 9             for addTwo in (addOne+1)...nums.count-1
10             {
11                 if(nums[addOne]+nums[addTwo]==target)
12                 {
13                     targetArray.append(addOne)
14                     targetArray.append(addTwo)
15                     break                   
16                 }               
17             }
18         }
19         return targetArray
20     }
21 }
_____________________________________________________________________________________________________________
法2：一遍哈希表
为了对运行时间复杂度进行优化，我们需要一种更有效的方法来检查数组中是否存在目标元素。如果存在，我们需要找出它的索引。保持数组中的每个元素与其索引相互对应的最好方法是什么？哈希表。

通过以空间换取速度的方式，我们可以将查找时间从 O(n) 降低到 O(1)。哈希表正是为此目的而构建的，它支持以 近似 恒定的时间进行快速查找。我用“近似”来描述，是因为一旦出现冲突，查找用时可能会退化到 O(n)。但只要你仔细地挑选哈希函数，在哈希表中进行查找的用时应当被摊销为 O(1)。

一个简单的实现使用了两次迭代。在第一次迭代中，我们将每个元素的值和它的索引添加到表中。然后，在第二次迭代中，我们将检查每个元素所对应的目标元素（target - nums[i]target−nums[i]）是否存在于表中。注意，该目标元素不能是 nums[i]nums[i] 本身！

 事实证明，我们可以一次完成。在进行迭代并将元素插入到表中的同时，我们还会回过头来检查表中是否已经存在当前元素所对应的目标元素。如果它存在，那我们已经找到了对应解，并立即将其返回。

 1 class Solution {
 2     func twoSum(_ nums: [Int], _ target: Int) -> [Int] {
 3         var table: [Int:Int] = [Int:Int]()
 4         
 5         for (index, num) in nums.enumerated() {
 6             var res: Int = target - num
 7             if let secondIndex = table[res] {
 8                 return [secondIndex, index]
 9             } else {
10                 table[num] = index
11             }
12         }
13 
14         return [0,0]
15     }
16 }
_____________________________________________________________________________________________________________
16ms

 1 class Solution {
 2     func twoSum(_ nums: [Int], _ target: Int) -> [Int] {
 3         var dict = [Int:Int]()
 4         
 5         for index in 0..<nums.count {
 6             dict[nums[index]] = index 
 7         }
 8         //print(dict)
 9         for i in 0..<nums.count {
10             
11             var complement = target - nums[i]
12             
13             if let complementIndex = dict[complement] {
14                 if complementIndex == i {
15                     continue
16                 } else {
17                     return [i,complementIndex]
18                 }
19             }  
20         }
21         return []
22     }
23 }
_____________________________________________________________________________________________________________
20ms

 1 class Solution {
 2     func twoSum(_ nums: [Int], _ target: Int) -> [Int] {
 3         var d = [Int: Int]()
 4         d.reserveCapacity(nums.count)
 5         for (n, m) in nums.enumerated() {
 6             d[m] = n
 7         }
 8         
 9         for (i, m) in nums.enumerated() {
10             let diff = target - m
11            if let j = d[diff] {
12                if i != j {
13                 return [i, j]
14                }
15             }
16         }
17         
18         return []
19     }
20 }
_____________________________________________________________________________________________________________
48ms

 1 class Solution {
 2     func twoSum(_ nums: [Int], _ target: Int) -> [Int] {
 3         guard nums.count > 2 else { return [0,1] }
 4         
 5         var indexTracker: [Int : Int] = [Int : Int]()
 6         for (i, num) in nums.enumerated() {
 7             indexTracker[num] = i
 8         }
 9         for (indx, num) in nums.enumerated() {
10             let diff = target - num
11             guard indexTracker[diff] != nil else { continue }
12                 let j = indexTracker[diff]!
13             guard j != indx else { continue }
14                 return [indx, j]
15         }
16         return [Int]()
17     }
18 }