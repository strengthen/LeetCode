__________________________________________________________________________________________________
class Solution {
    public int minimumMoves(int[][] grid) {
	int n = grid.length;
	boolean[][][] mem = new boolean[n][n][2];
	Queue<Pos> q = new LinkedList<>();
	q.offer(new Pos(0, 0, 0, 0));
	while (!q.isEmpty()) {
		Pos cur = q.poll();
		if (cur.s == 0 && cur.x == n - 1 && cur.y == n - 2) {
			return cur.step;
		}

		for (int i = 0; i < 4; i++) {
			if (canMove(cur, i, grid, mem)) {
				Pos next = move(cur, i);
				mem[next.x][next.y][next.s] = true;
				q.offer(next);
			}
		}
	}

	return -1;
}
	
private boolean canMove(Pos cur, int s, int[][] grid, boolean[][][] mem) {
	int n = grid.length, x = cur.x, y = cur.y;
	if (s == 0) {
		if (cur.s == 0) {
			return y + 2 < n && !mem[x][y + 1][0] && grid[x][y + 2] != 1;
		} else {
			return y + 1 < n && !mem[x][y + 1][1] && grid[x][y + 1] != 1 && grid[x + 1][y + 1] != 1;
		}
	} else if (s == 1) {
		if (cur.s == 0) {
			return x + 1 < n && !mem[x + 1][y][0] && grid[x + 1][y] != 1 && grid[x + 1][y + 1] != 1;
		} else {
			return x + 2 < n && !mem[x + 1][y][1] && grid[x + 2][y] != 1;
		}
	} else if (s == 2) {
		if (cur.s != 0) {
			return false;
		}
		return x + 1 < n && !mem[x][y][1] && grid[x + 1][y] != 1 && grid[x + 1][y + 1] != 1;
	} else {
		if (cur.s != 1) {
			return false;
		}
		return y + 1 < n && !mem[x][y][0] && grid[x][y + 1] != 1 && grid[x + 1][y + 1] != 1;
	}
}

private Pos move(Pos cur, int s) {
	int x = cur.x, y = cur.y;
	int pp = cur.s;
	if (s == 0) {
		y++;
	} else if (s == 1) {
		x++;
	} else if (s == 2) {
		pp = 1;
	} else {
		pp = 0;
	}
	return new Pos(x, y, pp, cur.step + 1);
}


class Pos {
	int x;
	int y;
	int s;
	int step;

	public Pos(int x, int y, int s, int step) {
		this.x = x;
		this.y = y;
		this.s = s;
		this.step = step;
	}
}
}
__________________________________________________________________________________________________

__________________________________________________________________________________________________
