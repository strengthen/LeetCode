__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public int minRefuelStops(int target, int startFuel, int[][] stations) {
        int stop = 0;
        int result = 0;
        int j;
        int[] t;
        for(int i = 0; i < stations.length && startFuel < target; i++) {
            if (startFuel < stations[i][0]) {
                while(stop > 0 && startFuel < stations[i][0]) {
                    startFuel += stations[0][1];
                    stop--;
                    result++;
                    stations[0] = stations[stop];
                    j = 0;
                    while(2*j + 1 < stop) {
                        if (stations[j][1] < stations[2*j + 1][1]) {
                            if (2*j + 2 < stop && stations[2*j + 2][1] > stations[2*j + 1][1]) {
                                t = stations[j];
                                stations[j] = stations[2*j + 2];
                                stations[2*j + 2] = t;
                                j = 2*j + 2;
                            }else {
                                t = stations[j];
                                stations[j] = stations[2*j + 1];
                                stations[2*j + 1] = t;
                                j = 2*j + 1;
                            }
                        }else if (2*j + 2 < stop && stations[2*j + 2][1] > stations[j][1]) {
                            t = stations[j];
                            stations[j] = stations[2*j + 2];
                            stations[2*j + 2] = t;
                            j = 2*j + 2;
                        }else {
                            break;
                        }
                    }
                }
                if (startFuel < stations[i][0]) {
                    return -1;
                }
            }
            j = stop++;
            if (j < i) {
                stations[j] = stations[i];
            }
            while(j > 0 && stations[j][1] > stations[(j - 1) / 2][1]) {
                t = stations[j];
                stations[j] = stations[(j - 1) / 2];
                stations[(j - 1) / 2] = t;
                j = (j - 1) / 2;
            }
        }
        while(stop > 0 && startFuel < target) {
            startFuel += stations[0][1];
            stop--;
            result++;
            stations[0] = stations[stop];
            j = 0;
            while(2*j + 1 < stop) {
                if (stations[j][1] < stations[2*j + 1][1]) {
                    if (2*j + 2 < stop && stations[2*j + 2][1] > stations[2*j + 1][1]) {
                        t = stations[j];
                        stations[j] = stations[2*j + 2];
                        stations[2*j + 2] = t;
                        j = 2*j + 2;
                    }else {
                        t = stations[j];
                        stations[j] = stations[2*j + 1];
                        stations[2*j + 1] = t;
                        j = 2*j + 1;
                    }
                }else if (2*j + 2 < stop && stations[2*j + 2][1] > stations[j][1]) {
                    t = stations[j];
                    stations[j] = stations[2*j + 2];
                    stations[2*j + 2] = t;
                    j = 2*j + 2;
                }else {
                    break;
                }
            }
        }
        if (startFuel >= target) {
            return result;
        }
        return -1;
    }
}
__________________________________________________________________________________________________
sample 39712 kb submission
class Solution {
	public int minRefuelStops(int target, int startFuel, int [] [] stat)
	{
		if(startFuel >= target) return 0;
		int N = stat.length;
		long [] dp = new long[N + 1];
		Arrays.fill(dp, startFuel);


		for(int i = 1; i <= N; i++)
		{
			long [] newR = new long[N + 1];
			for(int j = 1; j <= N; j++)
			{
				newR[j] = newR[j - 1];
				if(dp[j - 1] >= stat[j - 1][0])
				{
					newR[j] = Math.max(newR[j], dp[j - 1] + stat[j - 1][1]);
				}

				if(newR[j] >= target) return i;
			}
			dp = newR;
		}
		return -1;
	}
}
__________________________________________________________________________________________________
