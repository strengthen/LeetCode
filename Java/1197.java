__________________________________________________________________________________________________
class Solution {
	    public int minKnightMoves(int x, int y) {
	        return (int)knightDistance(x, y);
	    }
		public long knightDistance(long r, long c)
		{
			r = Math.abs(r); c = Math.abs(c);
			if(r + c == 0)return 0;
			if(r + c == 1)return 3;
			if(r == 2 && c == 2)return 4;
			
			long step = Math.max((r+1)/2, (c+1)/2);
			step = Math.max(step, (r+c+2)/3);
			step += (step^r^c)&1;
			return step;
		}
	}

__________________________________________________________________________________________________

__________________________________________________________________________________________________
