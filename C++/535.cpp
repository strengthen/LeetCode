__________________________________________________________________________________________________
sample 4 ms submission
static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution
{
private:
    int tinyIndex = -1;
    vector<string> tiny2Url;
    unordered_map<string, int> url2Tiny;

public:
    // Encodes a URL to a shortened URL.
    string encode(const string &longUrl)
    {
        tinyIndex += 1;
        tiny2Url.push_back(longUrl);
        url2Tiny[longUrl] = tinyIndex;
        return "http://tinyurl.com/" + to_string(tinyIndex);
    }

    // Decodes a shortened URL to its original URL.
    string decode(const string &shortUrl)
    {
        int idx = shortUrl.rfind('/') + 1;
        return tiny2Url[stoi(shortUrl.substr(idx))];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
__________________________________________________________________________________________________
sample 8604 kb submission
class Solution {
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
       return longUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return shortUrl;
    }
    
private:
    vector<string> url;    
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
__________________________________________________________________________________________________
