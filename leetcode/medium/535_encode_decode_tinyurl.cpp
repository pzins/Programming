class Solution {
public:
    map<string, string> dec;
    int cnt = 0;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string cnt_str = to_string(cnt);
        dec[cnt_str] = longUrl;
        cnt++;
        return cnt_str;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return dec[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
