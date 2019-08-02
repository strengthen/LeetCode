__________________________________________________________________________________________________
sample 5 ms submission
class Solution {
    final int MAX = 533744;
    public int containVirus(int[][] grid) {
        int result = 0, t,k,l,tem,tem2,f,c,d;
        boolean con;
        LinkedList<Integer> ll = new LinkedList();
        do{
            f=1;
            t=k=l=-1;
            con=false;
            for(int i=0;i<grid.length;++i)
                for(int j=0;j<grid[i].length;++j){
                    if(grid[i][j]==1){
                        con=true;
                        ++f;
                        tem=tem2=0;
                        ll.add(i);
                        ll.add(j);
                        grid[i][j]=f;
                        while(!ll.isEmpty()){
                            c=ll.poll();
                            d=ll.poll();
                            if(c-1>=0){
                                if(grid[c-1][d]<1){
                                    ++tem2;
                                    if(grid[c-1][d]!=-f){
                                        ++tem;
                                        grid[c-1][d]=-f;
                                    }
                                }else if(grid[c-1][d]==1){
                                    ll.add(c-1);
                                    ll.add(d);
                                    grid[c-1][d]=f;
                                }
                            }
                            if(c+1<grid.length){
                                if(grid[c+1][d]<1){
                                    ++tem2;
                                    if(grid[c+1][d]!=-f){
                                        ++tem;
                                        grid[c+1][d]=-f;
                                    }
                                }else if(grid[c+1][d]==1){
                                    ll.add(c+1);
                                    ll.add(d);
                                    grid[c+1][d]=f;
                                }
                            }
                            if(d-1>=0){
                                if(grid[c][d-1]<1){
                                    ++tem2;
                                    if(grid[c][d-1]!=-f){
                                        ++tem;
                                        grid[c][d-1]=-f;
                                    }
                                }else if(grid[c][d-1]==1){
                                    ll.add(c);
                                    ll.add(d-1);
                                    grid[c][d-1]=f;
                                }
                            }
                            if(d+1<grid[i].length){
                                if(grid[c][d+1]<1){
                                    ++tem2;
                                    if(grid[c][d+1]!=-f){
                                        ++tem;
                                        grid[c][d+1]=-f;
                                    }
                                }else if(grid[c][d+1]==1){
                                    ll.add(c);
                                    ll.add(d+1);
                                    grid[c][d+1]=f;
                                }
                            }
                        }
                        if(tem>t){
                            t=tem;
                            k=tem2;
                            l=f;
                        }
                    }
                }
            if(!con)break;
            result+=k;
            for(int i=0;i<grid.length;++i)
                for(int j=0;j<grid[i].length;++j){
                    if(grid[i][j]==l)grid[i][j]=MAX;
                    else if(grid[i][j]>1&&grid[i][j]<MAX){
                        grid[i][j]=1;
                        if(i-1>=0&&grid[i-1][j]<=0)grid[i-1][j]=1;
                        if(i+1<grid.length&&grid[i+1][j]<=0)grid[i+1][j]=1;
                        if(j-1>=0&&grid[i][j-1]<=0)grid[i][j-1]=1;
                        if(j+1<grid[i].length&&grid[i][j+1]<=0)grid[i][j+1]=1;
                    }
                }
            for(int i=0;i<grid.length;++i)
                for(int j=0;j<grid[i].length;++j)
                    if(grid[i][j]<0)grid[i][j]=0;
        }while(con);
        return result;
    }
}
__________________________________________________________________________________________________
sample 37816 kb submission
class Solution {
    public int containVirus(int[][] grid) {
        int res = 0, m = grid.length, n = grid[0].length;
		int[][] dirs = new int[][] { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };

		while (true) {
			HashSet<Integer> visited = new HashSet<Integer>();
			ArrayList<ArrayList<Integer>[]> all = new ArrayList<ArrayList<Integer>[]>();

			for (int i = 0; i < m; ++i) {
				for (int j = 0; j < n; ++j) {
					if (grid[i][j] == 1 && !visited.contains(i * n + j)) {

						Queue<Integer> q = new LinkedList<>();
						ArrayList<Integer> virus = new ArrayList<Integer>();
						ArrayList<Integer> walls = new ArrayList<Integer>();

						q.add(i * n + j);
						virus.add(i * n + j);
						visited.add(i * n + j);

						while (!q.isEmpty()) {
							int t = q.poll();

							for (int[] dir : dirs) {
								int x = (t / n) + dir[0], y = (t % n) + dir[1];

								if (x < 0 || x >= m || y < 0 || y >= n || visited.contains(x * n + y))
									continue;

								if (grid[x][y] == -1)
									continue;

								else if (grid[x][y] == 0)
									walls.add(x * n + y);

								else if (grid[x][y] == 1) {
									visited.add(x * n + y);
									virus.add(x * n + y);
									q.add(x * n + y);
								}
							}
						}

						ArrayList<Integer> cells = new ArrayList<Integer>();
						cells.add(new HashSet<Integer>(walls).size());
						all.add(new ArrayList[] { cells, walls, virus });
					}
				}
			}
			if (all.isEmpty())
				break;

			Collections.sort(all, (x, y) -> y[0].get(0) - x[0].get(0));

			for (int i = 0; i < all.size(); ++i) {
				if (i == 0) {
					ArrayList<Integer> virus = all.get(0)[2];

					for (int idx : virus)
						grid[idx / n][idx % n] = -1;

					res += all.get(0)[1].size();
				} else {
					ArrayList<Integer> wall = all.get(i)[1];

					for (int idx : wall)
						grid[idx / n][idx % n] = 1;
				}
			}
		}

		return res;
    }
}
__________________________________________________________________________________________________
