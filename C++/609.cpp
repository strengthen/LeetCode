__________________________________________________________________________________________________
sample 84 ms submission
int any = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
	vector<vector<string>> findDuplicate(vector<string> &paths) {
		unordered_map<string, vector<string>> files;
		for (string &d : paths) {
			string::iterator b = find(d.begin(), d.end(), ' '), e = b;
			string dir(d.begin(), b);
			while (e != d.end()) {
				e = find(b + 1, d.end(), '(');
				string filename(b + 1, e);
				b = e + 1;
				e = find(b, d.end(), ')');
				string content(b, e);
				b = ++e;
				files[content].push_back(dir + "/" + filename);
			}
		}
		vector<vector<string>> duplicates;
		for (pair<const string, vector<string>> &p : files)
			if (p.second.size() > 1)
				duplicates.push_back(p.second);
		return duplicates;
	}
};
__________________________________________________________________________________________________
sample 37312 kb submission
class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        vector<vector<string>> result;
        static hash<string> hash_fn;
        unordered_map<size_t, vector<string>> files;

        string root;
        string s;
        for (const auto& path : paths) {
            istringstream ss(path);
            ss >> root;
            while (ss >> s) {
                string file_name = root + '/' + s.substr(0, s.find('('));
                size_t file_content = hash_fn(string(s, s.find('(') + 1, s.find(')') - s.find('(') - 1));
                files[file_content].push_back(std::move(file_name));
            }
        }

        for (auto& file : files) {
            if (file.second.size() > 1) {
                result.push_back(std::move(file.second));
            }
        }

        return result;
    }
};
__________________________________________________________________________________________________
