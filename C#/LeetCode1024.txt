__________________________________________________________________________________________________
92ms
public class Solution {
		public int VideoStitching(int[][] clips, int T)
		{
			int[] dp = new int[T + 1];
			dp = dp.Select(x => T + 1).ToArray();
			dp[0] = 0;

			for (int i = 0; i <= T; i++)
			{
				foreach (int[] clip in clips)
				{
					if (i >= clip[0] && i <= clip[1]) dp[i] = Math.Min(dp[i], dp[clip[0]] + 1);

				}
				if (dp[i] == T + 1) return -1;
			}

			return dp[T];
		}
}
__________________________________________________________________________________________________
96ms
public class Solution {
    public int VideoStitching(int[][] clips, int T) 
    {
         clips = clips.OrderBy(c => c[0])
                .ThenBy(c => c[1] - c[0])
                .ToArray();
        
        int start = 0;
        int end = T;
        int segments = 0;
        
        for (int i = 0; i < clips.Length; i++)
        {
            //Console.WriteLine($"Start is: {start} and i is: {i}");
            
            int maxStep = -1;
            while (true)
            {
                if (i >= clips.Length)
                    break;
                
                int[] clip = clips[i];
                
                if (start < clip[0])
                    break;
                
                if (start >= clip[0] && start < clip[1])
                {
                    var step = clip[1] - start;
                    if (step > maxStep)
                    {
                        maxStep = step;
                    }
                }
                
                i++;
            }
            
            //Console.WriteLine($"Max Step = {maxStep}");
            
            if (maxStep == -1)
                break;
            
            start += maxStep;
            segments++;
            //Console.WriteLine("Start is now " + start.ToString());
            
            if (start >= end)
                return segments;
            
            // Decrement i, since we already incremented it once
            i--;   
            
            //Console.WriteLine("i is now " + i.ToString());
        }
    
        return -1;
    }
}
__________________________________________________________________________________________________
100ms
public class Solution
    {
        Dictionary<int, int> memo = null;

        public int VideoStitching(int[][] clips, int T)
        {
            Array.Sort<int[]>(clips, (a, b) => a[0].CompareTo(b[0]));
            var minCount = int.MaxValue;
            
            memo = new Dictionary<int, int>();

            for (var i = 0; i < clips.Length; ++i)
            {
                if (clips[i][0] == 0)
                {
                    minCount = Math.Min(minCount, DFS(clips, i, T));
                }
            }

            return minCount == int.MaxValue ? -1 : minCount;
        }

        private int DFS(int[][] clips, int i, int max)
        {
            if (memo.ContainsKey(i))
            {
                return memo[i];
            }

            if (clips[i][1] >= max)
            {
                memo[i] = 1;
            }
            else
            {
                memo[i] = int.MaxValue;

                for (var j = i + 1; j < clips.Length; ++j)
                {
                    if (AreOverlapping(clips[i], clips[j]))
                    {
                        var count = DFS(clips, j, max);
                        if (count != int.MaxValue)
                        {
                            memo[i] = Math.Min(memo[i], count);
                        }
                    }
                }

                if (memo[i] != int.MaxValue)
                {
                    ++memo[i];
                }
            }

            return memo[i];
        }

        private bool AreOverlapping(int[] a, int[] b)
        {
            if (a[1] == b[0]) return true;
            return a[0] < b[1] && b[0] < a[1];
        }
    }
__________________________________________________________________________________________________
104ms
public class Solution {
    public int VideoStitching(int[][] clips, int T) {
        var matr = new int[clips.Length, T+1];
        for (int i = 0; i < clips.Length; i++) {
            for (int j = clips[i][0]; j < clips[i][1] && j <= T; j++) {
                matr[i, j] = clips[i][1] - j;
            }
        }
        
        var count = 0;
        var time = 0;
        while (time < T) {
            var max = 0;
            for (int i = 0; i < clips.Length; i++) {
                max = Math.Max(max, matr[i, time]);
            }
            if (max == 0) return -1;
            time += max;
            count++;
        }
        
        return count;
    }
}
__________________________________________________________________________________________________
108ms
public class Solution
{
    int[,,] dp = new int[2, 101, 101];

    public int VideoStitching(int[][] clips, int T)
    {
        int rs = GetSplit(0, -1, T, clips);
        return rs < int.MaxValue / 2 ? rs : -1;
    }

    private int GetSplit(int t, int v, int T, int[][] clips)
    {
        if (v != -1 && (clips[v][1] < t || clips[v][0] > t))
            return int.MaxValue / 2;

        if (t == T)
        {
            // Console.WriteLine(str);
            return 0;
        }

        if (v != -1 && dp[0, t, v] == 1)
            return dp[1, t, v];

        int best = int.MaxValue / 2;
        for (int i = 0; i < clips.Length; ++i)
        {
            if (clips[i][1] < t || clips[i][0] > t)
                continue;
            if (i == v)
                best = Math.Min(best, GetSplit(t + 1, i, T, clips));
            else
                best = Math.Min(best, GetSplit(t + 1, i, T, clips) + 1);
        }

        if (v != -1)
        {
            dp[0, t, v] = 1;
            dp[1, t, v] = best;
        }
        return best;
    }
}
__________________________________________________________________________________________________
112ms
public class Solution {
    public int VideoStitching(int[][] clips, int T) {
     if (T == 0)
                return 0;
            int start = 0, end = 0, ans = 0;
            Dictionary<int, int> maxLenDict = new Dictionary<int, int>();
            foreach (var clip in clips)
            {
                int tempLen = -1;
                maxLenDict.TryGetValue(clip[0], out tempLen);
                if (tempLen < clip[1])
                    maxLenDict[clip[0]] = clip[1];
            }

            while (end < T)
            {
                ans++;
                var temp = end;
                for (int i = start ; i <= end; i++)
                {
                    if (maxLenDict.ContainsKey(i))
                        temp = temp > maxLenDict[i] ? temp : maxLenDict[i];
                }

                if (temp == end)
                    break;
                start = end;
                end = temp;
            }

            return end >= T ? ans : -1;
    }
}
__________________________________________________________________________________________________