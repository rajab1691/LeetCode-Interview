/*
  The time complexity of this algorithm is O(MN)
*/


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& a) {
        vector<int>res;
        int n = a.size();
        int m = a[0].size();
        int srow = 0, scol = 0, erow = n - 1, ecol = m - 1;

        while (srow <= erow and scol <= ecol) {
            for (int i = scol; i <= ecol; i++) {
                res.push_back(a[srow][i]);
            }
            srow++;

            for (int i = srow; i <= erow; i++) {
                res.push_back(a[i][ecol]);
            }
            ecol--;

            if (srow <= erow) {
                for (int i = ecol; i >= scol; i--) {
                    res.push_back(a[erow][i]);
                }
                erow--;
            }

            if (scol <= ecol) {
                for (int i = erow; i >= srow; i--) {
                    res.push_back(a[i][scol]);
                }
                scol++;
            }
        }
        return res;
    }

};
