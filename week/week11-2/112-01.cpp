//
// Created by akio on 2020/11/15.
//
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class OrderedStream {
private:
    vector<string> memo;
    vector<bool> flag;
    int ptr = 1;
public:
    OrderedStream(int n) : memo(n + 1), flag(n + 1) {

    }

    vector<string> insert(int id, string value) {
        memo[id] = value;
        flag[id] = true;
        int last = ptr;
        while (last < memo.size() && flag[last])
            ++last;
        cout << id << '-' << last << ' ' << ptr;
        vector<string> res = {memo.begin() + ptr, memo.begin() + last};
        ptr = last;
        return res;
    }
};

int main() {
    OrderedStream stream(5);
    stream.insert(3, "ccccc");
}