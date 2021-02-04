//
// Created by akio on 2021/2/3.
//
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class DualHeap {
    // 大根堆
    priority_queue<int> small;
    // 小跟堆
    priority_queue<int, vector<int>, greater<>> large;
    // 延迟删除
    unordered_map<int, int> delayed;

    int k;
    int smallSize, largeSize;
public:
    DualHeap(int _k) : k(_k), smallSize(0), largeSize(0) {}

private:
    template<class T>
    void prune(T &heap) {
        while (!heap.empty()) {
            int num = heap.top();
            if (delayed.count(num)) {
                --delayed[num];
                if (!delayed[num]) {
                    delayed.erase(num);
                }
                heap.pop();
            } else {
                break;
            }
        }
    }

    void makeBalance() {
        if (smallSize > largeSize + 1) {
            large.push(small.top());
            small.pop();
            --smallSize;
            ++largeSize;
            prune(small);
        } else if (smallSize < largeSize) {
            small.push(large.top());
            large.pop();
            ++smallSize;
            --largeSize;
            prune(large);
        }
    }

public:
    void insert(int num) {
        if (small.empty() || num <= small.top()) {
            small.push(num);
            ++smallSize;
        } else {
            large.push(num);
            ++largeSize;
        }
        makeBalance();
    }

    void erase(int num) {
        ++delayed[num];
        if (num <= small.top()) {
            --smallSize;
            if (num == small.top()) {
                prune(small);
            }
        } else {
            --largeSize;
            if (num == large.top()) {
                prune(large);
            }
        }
        makeBalance();
    }

    double getMedian() {
        return k & 1 ? small.top() : ((double) small.top() + large.top()) / 2 ;
    }
};

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int> &nums, int k) {
        DualHeap dh(k);
        for (int i = 0; i < k; ++i) {
            dh.insert(nums[i]);
        }
        vector<double> res = {dh.getMedian()};
        for (int i = k; i < nums.size(); ++i) {
            dh.insert(nums[i]);
            dh.erase(nums[i - k]);
            res.push_back(dh.getMedian());
        }
        return res;
    }
};