#include <iostream>
#include <set>
#include <bitset>
using namespace std;

int main() {
    cout << 3.14 + 1e20 - 1e20 << endl;
    cout << 3.14 + (1e20-1e20) <<endl;
    printf("%x\n",'c');
    cout << sizeof(long) << endl;
    cout << bitset<32>('c') << endl;
    cout << hex << (int)'z' << endl;
}