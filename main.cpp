#include <iostream>
#include <climits>
#include <queue>
#include <bitset>

using namespace std;

int main() {
    int s = 20;
    while (s) {
        cout << bitset<8>(s) << endl;
        s = (s - 1) & 20;
    }
}
