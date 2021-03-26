#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};
        int m = matrix.size(), n = matrix[0].size();
        int l = 0, r = n - 1, u = 0, d = m - 1;
        vector<int> res;
        while (true) {
            for (int j = l; j <= r; ++j) {
                res.push_back(matrix[u][j]);
            }
            if (++u > d) break;
            for (int i = u; i <= d; ++i) {
                res.push_back(matrix[i][r]);
            }
            if (--r < l) break;
            for (int j = r; j >= l; --j) {
                res.push_back(matrix[d][j]);
            }
            if (--d < u) break;
            for (int i = d; i >= u; --i) {
                res.push_back(matrix[i][l]);
            }
            if (++l > r) break;
        }
        return res;
    }
};