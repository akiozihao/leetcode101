//
// Created by akio on 2020/12/26.
//
#include <vector>
#include <queue>
#include <stack>
using namespace std;
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        if(sandwiches.empty()) return students.size();
        queue<int> queue({students.begin(),students.end()});
        stack<int> stk({sandwiches.rbegin(),sandwiches.rend()});
        int cnt = 0;
        while(!stk.empty() && cnt < queue.size()){
            if(queue.front()!=stk.top()){
                int t = queue.front();
                queue.pop();
                queue.push(t);
                ++cnt;
            }else{
                stk.pop();
                queue.pop();
                cnt = 0;
            }
        }
        return queue.size();
    }
};