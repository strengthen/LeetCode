__________________________________________________________________________________________________
sample 40 ms submission
struct Node{
    int q;
    double ratio;
    bool operator < (const Node &o) const
    {
        if (fabs(ratio - o.ratio) < 1e-7) return q < o.q;
        else return ratio < o.ratio;
    }
}nodes[10010];


class Solution {
private:
    priority_queue<int, vector<int>, less<int> > Q;
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        while(!Q.empty()) Q.pop();
        int N = quality.size();
        for (int i = 0; i < N; i ++)
        {
            nodes[i].q = quality[i];
            nodes[i].ratio = 1.0 * wage[i] / quality[i];
        }
        sort(nodes, nodes + N);
        int sum = 0;
        double ans = 1e20;
        for (int i = 0; i < K - 1; i ++)
        {
            sum += nodes[i].q;
            Q.push(nodes[i].q);
        }
        for(int i = K - 1; i < N; i ++)
        {
            ans = min(ans, nodes[i].ratio*(sum + nodes[i].q));
            if (!Q.empty() && Q.top() > nodes[i].q)
            {
                int qt = Q.top();
                sum -= qt;
                sum += nodes[i].q;
                Q.pop();
                Q.push(nodes[i].q);
            }
        }
        return ans;
    }
};
__________________________________________________________________________________________________
sample 11140 kb submission
class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K)
    {
        vector<int> factor(quality.size());
        
        for (int i = 0; i < factor.size(); ++i)
            factor[i] = i;
        
        std::sort(factor.begin(), factor.end(), [&](int a, int b)
                  {return wage[a]/(double)quality[a] < wage[b]/(double)quality[b];});
        
        priority_queue<int> qualityQueue;
        double totalQuality = 0;
        double minCost = std::numeric_limits<double>::max();
        
        for (int i : factor)
        {
            //cout << "i = " << i << " " << wage[i] << " " << quality[i] << " " << wage[i]/quality[i] << endl;
            qualityQueue.push(quality[i]);
            totalQuality += quality[i];
            //cout << totalQuality << endl;
            
            if (qualityQueue.size() > K)
            {
                totalQuality -= qualityQueue.top();
                //cout << ">K " << totalQuality << endl;
                //cout << qualityQueue.top() << endl;
                qualityQueue.pop();
            }
            
            if (qualityQueue.size() == K)
            {
                //cout << "==K " << totalQuality << endl;
                double cost = totalQuality * wage[i] / quality[i];
                minCost = min(minCost, cost);
            }
            
            //cout << "size = " << qualityQueue.size() << endl;
        }

        return minCost;
    }
};
__________________________________________________________________________________________________
