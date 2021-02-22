#include <bits/stdc++.h>

#include <iostream>

using namespace std;

int main() {
  priority_queue<int, vector<int>, greater<>> small;
  priority_queue<int> large;

  large.push(1);
  large.push(2);
  small.push(1);
  small.push(2);
  cout << small.top() << endl;
  cout << large.top() << endl;
}