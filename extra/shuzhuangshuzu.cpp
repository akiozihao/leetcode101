//
// Created by akio on 2021/2/17.
//
#include <vector>

using namespace std;

class FenwickTree {
public:
    FenwickTree(vector<int> &nums) {
        n = (int) nums.size();
        tree.resize(n + 1);
        for (int i = 0; i < n; ++i) {
            update(i, nums[i]);
        }
    }

    FenwickTree(int _n) {
        n = _n;
        tree.resize(n);
    }

    // 单点更新 下标i + delta
    void update(int i, int delta) {
        while (i < n) {
            tree[i] += delta;
            i += lowbit(i);
        }
    }

    // 前缀和查询
    int query(int i) {
        int sum = 0;
        while (i > 0) {
            sum += tree[i];
            i -= lowbit(i);
        }
    }

private:
    vector<int> tree;
    int n;
private:
    int lowbit(int i) {
        return i & (-i);
    }
};