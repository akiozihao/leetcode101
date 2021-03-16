#include <vector>
using namespace std;
class Solution {
   public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));
        int num = 1;
        int l = 0, r = n - 1, u = 0, d = n - 1;
        while (true) {
            for (int j = l; j <= r; ++j) {
                res[u][j] = num++;
            }
            if (++u > d) break;
            for (int i = u; i <= d; ++i) {
                res[i][r] = num++;
            }
            if (--r < l) break;
            for (int j = r; j >= l; --j) {
                res[d][j] = num++;
            }
            if (--d < u) break;
            for (int i = d; i >= u; --i) {
                res[i][l] = num++;
            }
            if (++l > r) break;
        }
        return res;
    }
};