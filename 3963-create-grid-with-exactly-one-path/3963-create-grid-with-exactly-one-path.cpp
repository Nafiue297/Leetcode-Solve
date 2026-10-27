class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> res;

        for (int i = 0; i < m-1; i++) {
            string row = "";

            for (int j = 0; j < n; j++) {
                if (j % 2 == 1)
                    row += '#';
                else
                    row += '.';
            }

            res.push_back(row);
        }
      for(int i=1; i<2; i++)
      {
        res.push_back(string(n,'.'));
      }
        return res;
    }
};