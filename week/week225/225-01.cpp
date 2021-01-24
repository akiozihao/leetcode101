//
// Created by akio on 2021/1/23.
//

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string maximumTime(string time) {
        for (int i = 0; i < time.size(); ++i) {
            if (i == 0 && time[i] == '?') {
                if (time[1] != '?' && time[1] >= '4') {
                    time[0] = '1';
                } else
                    time[0] = '2';
            }
            if (i == 1 && time[i] == '?') {
                if (time[0] == '2') time[1] = '3';
                else time[1] = '9';
            }
            if (i == 2 && time[i] == '?') {
                time[i] = '5';
            }
            if (i == 3 && time[i] == '?') {
                time[i] = '9';
            }
        }
        return time;
    }

    string maximumTime2(string time) {
        for (int h = 23; h >= 0; --h) {
            for (int m = 59; m >= 0; --m) {
                string t = time;
                t[0] = h / 10 + '0';
                t[1] = h % 10 + '0';
                t[3] = m / 10 + '0';
                t[4] = m % 10 + '0';
                int ok = 1;
                for (int i = 0; i < 5; ++i) {
                    if (time[i] != '?' && time[i] != t[i]) {
                        ok = 0;
                        break;
                    }
                }
                if (ok) return t;
            }
        }
        return "";
    }

};