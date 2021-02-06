#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, num;
    vector<int> v(101);
    while (cin >> n && n) {
        for(int i=0;i<n;++i){
            cin >> num;
            v[i] = num;
        }
        sort(v.begin(), v.begin()+n, [](int &a, int &b) {
            return abs(a) > abs(b);
        });
        cout << v[0];
        for (int i = 1; i < n; ++i) {
            cout << " " << v[i];
        }
        cout << endl;
    }
    return 0;
}