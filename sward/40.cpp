#include <queue>
using namespace std;

class Solution {
   public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> res(k, 0);
        if (k == 0) return res;
        priority_queue<int> pq;
        for (int i = 0; i < k; ++i) {
            pq.push(arr[i]);
        }
        for (int i = k; i < arr.size(); ++i) {
            if (arr[i] < pq.top()) {
                pq.pop();
                pq.push(arr[i]);
            }
        }
        for (int i = 0; i < k; ++i) {
            res[i] = pq.top();
            pq.pop();
        }
        
        return res;
    }
};