//
// Created by akio on 2021/1/11.
//

class Solution {
public:
    bool isHappy(int n) {
        int slow = n;
        int fast = getNext(n);
        while (slow != 1 && slow != fast) {
            slow = getNext(slow);
            fast = getNext(getNext(fast));
        }
        return fast == 1;
    }

private:
    int getNext(int n) {
        int res = 0;
        while (n) {
            res += n % 10 * (n % 10);
            n /= 10;
        }
        return res;
    }
};