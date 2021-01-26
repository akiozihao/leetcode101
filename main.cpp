#include <iostream>
#include <set>
#include <bitset>
using namespace std;

int main() {
    string s("/\\");
    cout << (--s.begin() == s.end()) ;
}