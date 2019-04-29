__________________________________________________________________________________________________
sample 296 ms submission
class TopVotedCandidate {
public:
    TopVotedCandidate(vector<int> persons, vector<int> times) {
        assert(persons.size() == times.size() && "SHABI");
        
        this->times = times;
        winners.assign(times.size(), -1);
        unordered_map<int, int> votes;
        int cur_winner = -1;
        int cur_winner_votes = 0;
        
        for (int i = 0; i < persons.size(); ++i) {
            int vote = persons[i];
            ++votes[vote];
            if (votes[vote] >= cur_winner_votes) {
                cur_winner_votes = votes[vote];
                cur_winner = vote;
            }
            winners[i] = cur_winner;
        }
    }
    
    int q(int t) {
        // Binary search for finding nearest value
        int start = 0, end = times.size() - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (times[mid] < t) {
                start = mid + 1;
            } else if (times[mid] > t) {
                end = mid - 1;
            } else {
                return winners[mid];
            }
        }
        
        // End is now less than start, 
        // so should be the smaller target
        return winners[end];
    }
    
private:
    vector<int> winners;
    vector<int> times;
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */

static auto speedup = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
__________________________________________________________________________________________________
sample 74940 kb submission
class TopVotedCandidate {
public:
    vector<int> Persons;
    vector<int> Times;
    TopVotedCandidate(vector<int> persons, vector<int> times) {
        Persons = persons;
        Times = times;
    }
    
    int q(int t) {
        int T = Times.size();
        int left = 0, right = T-1, mid;
        while(left < right) {
            mid = (left+right)/2;
            if(t < Times[mid]) {
                if(right == mid)
                    break;
                right = mid;
            }
            else {
                if(left == mid)
                    break;
                left = mid;
            }
        }
        if(mid+1 < T && t >= Times[mid+1])
            mid = mid+1;
        int n = Persons.size();
        int arr[n+33] = {}, M = 0, index;
        for(int i=0; i<=mid; i++) {
            arr[Persons[i]] ++;
            if(arr[Persons[i]] >= M)
                M = arr[Persons[i]], index = Persons[i];
        }
        return index;
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj.q(t);
 */
__________________________________________________________________________________________________
