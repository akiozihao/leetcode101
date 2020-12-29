#include <iostream>
#include <climits>
#include <queue>
using namespace std;
int main() {
    priority_queue<int,vector<int>,less<>> pq;
    pq.push(0);
    pq.push(1);
    cout << pq.top() <<endl;
    return 0;
}
