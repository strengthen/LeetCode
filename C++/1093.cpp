__________________________________________________________________________________________________
using VI = vector< int >;
using VD = vector< double >;
class Solution {
public:
    VD sampleStats( VI& cnt ){
        double mind{ 256.0 }, maxd{ -1.0 }, mode{ 0.0 }, sum{ 0.0 };
        const auto N = cnt.size();
        auto totalCnt{ 0 }, modeCnt{ 0 };
        for( auto i{ 0 }; i < N; ++i ){
            if( cnt[ i ] == 0 )
                continue;
            if( mind > i ) mind = i;
            if( maxd < i ) maxd = i;
            if( modeCnt < cnt[ i ] ){
                modeCnt = cnt[ i ];
                mode = i;
            }
            sum += i * cnt[ i ];
            totalCnt += cnt[ i ];
        }
        auto mean = sum / totalCnt;
        auto median = getMedian( cnt, totalCnt );
        return{ mind, maxd, mean, median, mode };
    }
private:
    double getMedian( const VI& cnt, int totalCnt, double median=0.0 ){
        auto T1 = totalCnt / 2,
             T2 = T1 + 1;
        auto isEven = totalCnt % 2 == 0;
        totalCnt = 0;
        auto i{ 0 };
        const auto N = cnt.size();
        for(; i < N; ++i ){
            totalCnt += cnt[ i ];
            if( totalCnt >= T1 ){
                median = i;
                break;
            }
        }
        if( isEven ){
            if( totalCnt >= T2 ){
                median += i;
                median /= 2.0;
            } else {
                for( ++i; i < N; ++i ){
                    totalCnt += cnt[ i ];
                    if( totalCnt >= T2 ){
                        median += i;
                        median /= 2.0;
                        break;
                    }
                }
            }
        }
        return median;
    }
};
__________________________________________________________________________________________________

__________________________________________________________________________________________________
