__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
public:
    
    bool consume_letter_pool(const string& word, vector<int8_t>& letter_count_vec) {
        bool valid = true;
        for (int i = 0; i < word.size(); ++i) {
            if (--letter_count_vec[word[i] - 'a'] < 0) {
                valid = false;
            }
        }    
        return valid;
    }
    
    void restore_letter_pool(const string& word, vector<int8_t>& letter_count_vec) {
        for (int i = 0; i < word.size(); ++i) {
            ++letter_count_vec[word[i] - 'a'];
        }
    }
    
    void maxScoreWordsHelper(const vector<string>& words, const vector<int>& word_score_vec, int cur_word_idx, vector<int8_t>& letter_count_vec, int cur_sum_score, int& global_max_sum_score) {
        if (cur_word_idx == words.size()) {
            if (global_max_sum_score < cur_sum_score) {
                global_max_sum_score = cur_sum_score;
            }
            return;
        }
        
        // choose cur word
        bool can_form = consume_letter_pool(words[cur_word_idx], letter_count_vec);
        if (can_form) {
            maxScoreWordsHelper(words, word_score_vec, cur_word_idx + 1, letter_count_vec, cur_sum_score + word_score_vec[cur_word_idx], global_max_sum_score);
        }
        restore_letter_pool(words[cur_word_idx], letter_count_vec);
        
        // not choose cur word
        maxScoreWordsHelper(words, word_score_vec, cur_word_idx + 1, letter_count_vec, cur_sum_score, global_max_sum_score);
    }
    
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int ret = 0;
        vector<int8_t> letter_count_vec(26, 0);
        for (int i = 0; i < letters.size(); ++i) {
            ++letter_count_vec[letters[i] - 'a'];
        }
        
        vector<int> word_score_vec(words.size(), 0);
        for (int word_idx = 0; word_idx < words.size(); ++word_idx) {
            const string& cur_word = words[word_idx];
            int sum_score = 0;   
            for (int i = 0; i < cur_word.size(); ++i) {
                sum_score += score[cur_word[i] - 'a'];
            }
            word_score_vec[word_idx] = sum_score;
        }
        
        maxScoreWordsHelper(words, word_score_vec, 0, letter_count_vec, 0, ret);
        
        return ret;
    }
};
__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
    int getMax(vector<string>& words, vector<int> & V, vector<int>& score, int i){
	    if(i >= words.size()) return 0;
        int gainwocur = getMax(words, V, score, i+1);
        vector<int> nV(V.begin(), V.end());
        int g = 0;
        for(char ch:words[i]) {
            if(nV[ch-'a'] == 0) return gainwocur;
            nV[ch-'a']--;
            g += score[ch-'a'];
        }
        int gainwicur = g + getMax(words, nV, score, i+1);
        return (gainwicur>gainwocur?gainwicur:gainwocur);
    }
    
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> V(26, 0);
        for(char ch: letters) V[ch-'a']++;
        return getMax(words, V, score, 0);
    }
};
__________________________________________________________________________________________________
