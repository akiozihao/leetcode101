#include <iostream>
#include <set>
#include <bitset>
using namespace std;

int main() {
    string s("/\\");
    for(char c:s){
        cout << c << endl;
    }
    cout << s.size() << endl;
}