__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    private int min = Integer.MAX_VALUE, max = 0;
    
    public List<String> wordBreak(String s, List<String> wordDict) {
        HashSet<String> set = new HashSet<String>();
        for(String word:wordDict){
            set.add(word);
            int curLen = word.length();
            min = (curLen<min)? curLen:min;
            max = (curLen>max)? curLen:max;
        }
        List<String> result = new ArrayList<String>();
        boolean[] invalid  = new boolean[s.length()]; //invalid[i]: [i:] is unbreakable
        seperate(s, result, new StringBuilder(), 0, set, invalid);
        return result;
    }
    
    public boolean seperate(String s,List<String> res, StringBuilder tmp, int index,HashSet<String> set, boolean[] invalid){
        if(index == s.length()){
            res.add(tmp.toString().trim());
            return true;
        }
        boolean breakable = false;
        int prelen = tmp.length();
        
        int rightbound = Math.min(s.length(),index+max);
        for(int end = index+1; end<=rightbound; end++){
            int curLen = end-index;
            if(end<s.length()&&invalid[end]){
                continue;
            }
            String cur = s.substring(index, end);
            if(set.contains(cur)){

                tmp.append(" ").append(cur);
                breakable |= seperate(s,res,tmp,end,set, invalid);
                tmp.setLength(prelen);
            }
        }
        invalid[index] = !breakable;
        return breakable;
    }
}
__________________________________________________________________________________________________
sample 34792 kb submission
/*
像这种返回结果要列举所有情况的题，十有八九都是要用递归来做的!!!。
当我们一时半会没有啥思路的时候，先不要考虑代码如何实现，如果就给你一个s和wordDict，不看Output的内容，你会怎么找出结果。比如对于例子1，博主可能会先扫一遍wordDict数组，看有没有单词可以当s的开头，那么我们可以发现cat和cats都可以，比如我们先选了cat，那么此时s就变成了 "sanddog"，我们再在数组里找单词，发现了sand可以，最后剩一个dog，也在数组中，于是一个结果就出来了。然后回到开头选cats的话，那么此时s就变成了 "anddog"，我们再在数组里找单词，发现了and可以，最后剩一个dog，也在数组中，于是另一个结果也就出来了。那么这个查询的方法很适合用递归来实现，因为s改变后，查询的机制并不变，很适合调用递归函数。
再者，我们要明确的是，如果不用记忆数组做减少重复计算的优化，那么递归方法跟brute force没什么区别，大概率无法通过OJ。所以我们要避免重复计算!!!!!
，如何避免呢，还是看上面的分析，如果当s变成 "sanddog"的时候，那么此时我们知道其可以拆分成sand和dog，当某个时候如果我们又遇到了这个 "sanddog"的时候，我们难道还需要再调用递归算一遍吗，当然不希望啦，所以我们要将这个中间结果保存起来，由于我们必须要同时保存s和其所有的拆分的字符串，那么可以使用一个HashMap，来建立二者之间的映射，那么在递归函数中，我们首先检测当前s是否已经有映射，有的话直接返回即可，如果s为空了，我们如何处理呢，题目中说了给定的s不会为空，但是我们递归函数处理时s是会变空的，这时候我们是直接返回空集吗，这里有个小trick，我们其实放一个空字符串返回，为啥要这么做呢？我们观察题目中的Output，发现单词之间是有空格，而最后一个单词后面没有空格，所以这个空字符串就起到了标记当前单词是最后一个，那么我们就不要再加空格了。接着往下看，我们遍历wordDict数组，如果某个单词是s字符串中的开头单词的话，我们对后面部分调用递归函数，将结果保存到rem中，然后遍历里面的所有字符串，和当前的单词拼接起来，这里就用到了我们前面说的trick。for循环结束后，记得返回结果res之前建立其和s之间的映射，方便下次使用，

*/
//这道题的主要一点就是要在递归的时候避免重复计算，因为会超时，所以需要用map纪录每个word 开头以后，后面能被分成的状况
class Solution {
    public List<String> wordBreak(String s, List<String> wordDict) {
        return DFS(s, wordDict, new HashMap<String, List<String>>());
    }
    private List<String> DFS(String s, List<String> wordDict, Map<String, List<String>> map) {
        //这说明s后面的分成情况之前就已经计算过，所以只要直接拿来就可以
        if (map.containsKey(s)) return map.get(s);
        //若不是之前就计算过的，那么subRes就是该s分割以后的结果情况
        List<String> subRes = new ArrayList<>();
        //说明上一层分割的是最后一个，那么我们需要在他的subRes中加个空，告诉上一层已经没有了
        if (s.length() == 0) {
            subRes.add("");
            return subRes;
        }
        //因为分割到哪个部分都需要重新过dict中的word，因为不知道是从哪里起头的
        for (String w : wordDict) {
            if (s.startsWith(w)) {
                //s.substring(w.length())，表示的是取idx为w.length()开始，到结束的字符串
                List<String> subString = DFS(s.substring(w.length()), wordDict, map);
                //因为res 是List<String>的形式，所以只能一个一个string的往上加，不能直接加一个List<String>的subString结果
                for (String sub : subString) {
                    
                    subRes.add(w + (sub.isEmpty() ? "" : " ") + sub);
                }
            }            
        }
        //每一层递归结束后把该层递归开始的s，以及其后面的分割情况加入map中纪录起来
        map.put(s, subRes);
        return subRes;
    }
}
__________________________________________________________________________________________________
