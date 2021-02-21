#include<bits/stdc++.h>

using namespace std;

int main() {
    priority_queue<int,vector<int>,greater<>> small;
    priority_queue<int,vector<int>,greater<>> large;
    small.push(1);
    small.push(2);
    cout << small.top() << endl;
}