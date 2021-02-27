#include <string>
#include <vector>
using namespace std;
class Codec {
public:
    string encode(vector<string> &strs) {
        string res;
        for (auto s : strs) {
            res.append(to_string(s.size())).append("/").append(s);
        }
        return res;
    }
    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        while (i < s.size()) {
            auto found = s.find("/", i);
            int len = stoi(s.substr(i,found-i));
            res.push_back(s.substr(found+1,len));
            i = found + len + 1;
        }
        return res;
    }
};