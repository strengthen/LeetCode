__________________________________________________________________________________________________
sample 108 ms submission
class TopVotedCandidate {
    List<Vote> A;
    public TopVotedCandidate(int[] persons, int[] times) {
        A = new ArrayList();
        Map<Integer, Integer> count = new HashMap();
        int leader = -1;  // current leader
        int m = 0;  // current number of votes for leader

        for (int i = 0; i < persons.length; ++i) {
            int p = persons[i], t = times[i];
            int c = count.getOrDefault(p, 0) + 1;
            count.put(p, c);

            if (c >= m) {
                if (p != leader) {  // lead change
                    leader = p;
                    A.add(new Vote(leader, t));
                }

                if (c > m) m = c;
            }
        }
    }

    public int q(int t) {
        int lo = 1, hi = A.size();
        while (lo < hi) {
            int mi = lo + (hi - lo) / 2;
            if (A.get(mi).time <= t)
                lo = mi + 1;
            else
                hi = mi;
        }

        return A.get(lo - 1).person;
    }
}

class Vote {
    int person, time;
    Vote(int p, int t) {
        person = p;
        time = t;
    }
}
__________________________________________________________________________________________________
sample 70876 kb submission
class TopVotedCandidate {
    
    //private TreeMap<Integer, Integer> votesStat;
    private int[] leads;
    private int[] times;
    
    
    public TopVotedCandidate(int[] persons, int[] times) {
        //votesStat = new TreeMap<>();
        this.times = times;
        this.leads = new int[times.length];
        Map<Integer, Integer> allVotes = new HashMap<>();
        int maxVote = Integer.MIN_VALUE;
        int maxPerson = -1;
        for (int i = 0; i < persons.length; i++) {
            int person = persons[i];
            int time = times[i];
            
            int newVote = allVotes.getOrDefault(person, 0) + 1;
            allVotes.put(person, newVote);
            if (newVote >= maxVote) {
                maxVote = newVote;
                maxPerson = person;
            }
            //votesStat.put(time, maxPerson);
            leads[i]=maxPerson;
            
        }
             
    }             
    public int q(int t) {
        int time = Arrays.binarySearch(times, t);
        if (time >=0) {
            return leads[time];
        } else {
            return leads[-time-2];
        }
        //return votesStat.floorEntry(t).getValue();
    }
}

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj.q(t);
 */
__________________________________________________________________________________________________
