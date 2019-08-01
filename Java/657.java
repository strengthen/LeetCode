__________________________________________________________________________________________________
sample 1 ms submission
class Solution
{
    public boolean judgeCircle(String moves)
	{
        int countU = count(moves, 'U');
        int countD = count(moves, 'D');
        int countL = count(moves, 'L');
        int countR = count(moves, 'R');
        if (countU == countD && countL == countR)
        {
           return true;
        }
        return false;    
    }
    
    public int count(String moves, char a)
    {
        int count = 0;
        for(char ch : moves.toCharArray())
        {
            if(ch == a )
            {
                count++;
            }
        }
        return count;
    }
}
__________________________________________________________________________________________________
sample 37140 kb submission
import static java.util.stream.Collectors.*;

class Solution {
    
    static Map<Integer, Function<Integer, Integer>> horMoves = new HashMap<>();
    static {
        horMoves.put((int)'U', x -> x);
        horMoves.put((int)'D', x -> x);
        horMoves.put((int)'L', x -> x - 1);
        horMoves.put((int)'R', x -> x + 1);
    }
    static Map<Integer, Function<Integer, Integer>> vertMoves = new HashMap<>();
    static {
        vertMoves.put((int)'U', x -> x + 1);
        vertMoves.put((int)'D', x -> x - 1);
        vertMoves.put((int)'L', x -> x);
        vertMoves.put((int)'R', x -> x);
    }

    
    public boolean judgeCircle(String moves) {
        int i = 0; int j = 0;
        for (Integer move : (Iterable<Integer>)moves.chars()::iterator) {
            i = horMoves.get(move).apply(i);
            j = vertMoves.get(move).apply(j);
        }
        return i == 0 && j == 0;
    }
}
__________________________________________________________________________________________________
