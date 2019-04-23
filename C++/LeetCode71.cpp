__________________________________________________________________________________________________
4ms
class Solution {
public:
    string simplifyPath(string path) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);

        int len = path.length();
        vector<string>Path;
        string now;
        for(int i = 0; i < len; i++) {
            if(path[i] == '/') continue;
            if(path[i] == '.') {
                if(i + 1 < len && path[i + 1] == '.' && (i + 2 >= len || path[i + 2] == '/')) {
                    if(!Path.empty()) {
                        // cout<<"POP\n";
                        Path.pop_back();
                    }
                    i++;
                    continue;
                }else if(i + 1 >=len || path[i+1] == '/') {
                    continue;
                }
            }
            now = "";
            while(i < len && path[i] != '/') {
                now += path[i]; i ++;
            } 
            // cout<<now<<endl;
            Path.push_back(now);
        }
        string ans = "/";
        len = Path.size();
        // cout<<"len: "<<len<<endl;
        for(int i = 0; i < len - 1; i++) {
            ans += Path[i];
            ans += "/";
        }
        if(len) ans += Path[len - 1];
        return ans;
    }
};
__________________________________________________________________________________________________
9216 kb
static const auto speedup = []() {std::ios::sync_with_stdio(false); std::cin.tie(NULL); return 0; }();
class Solution {
public:
	string simplifyPath(string path) {
		string ret;
		bool is_last_dir = false;
		int period_len = 0;	// .的长度
		for (int i = 0; i < path.length(); i++)
		{
			if (path[i] == '.') {
				bool tmp = isRelativePath(path, i, is_last_dir, period_len);
				if (tmp) {	//是相对路径
					++i;
					if (is_last_dir) {	//表示上层目录
						del_eol(ret);
						ret.erase(ret.find_last_of('/') + 1);
						++i;
					}
				}
				else {
					ret += path.substr(i, period_len);
					i = i + period_len - 1;
				}
				continue;
			}
			else if (path[i] == '/') {
				if (i + 1 < path.length() && path[i + 1] == '/') {
					for (size_t j = i + 1; i < path.length(); j++){
						if (path[j] != '/') { i = j - 1; break;}
					}
				}
				if(ret.length() == 0 || ret[ret.length() - 1] != '/') ret += '/';
				continue;
			}
			ret += path[i];
		}
		del_eol(ret);
		return ret;
	}

private:
	//去掉字符串结尾的 '/'
	void del_eol(string & ret) {
		if (ret.length() > 1) {
			int i = ret.length() - 1;
			for (; i > 0; --i)
				if (ret[i] != '/')
					break;
			ret.erase(i + 1);
		}
	}
	
	//遇到.时，判断是否为 相对路径
	//is_last_dir 表示是否为 上层目录(必须先判断方法的返回结果，再判断该值)
	bool isRelativePath(string &path, int &i, bool &is_last_dir, int &period_len) {
		period_len = 0;
		is_last_dir = false;
		for (int j = i; j < path.length(); j++, period_len++)
		{
			if (path[j] != '.') {
				if (path[j] == '/' && period_len <= 2) {
					is_last_dir = period_len == 2 ? true : false;
					return true;
				}
				return false;
			}
		}
		//这里表示的是.一直到结尾都是.
		is_last_dir = period_len == 2 ? true : false;
		return period_len <= 2;
	}
};
__________________________________________________________________________________________________
