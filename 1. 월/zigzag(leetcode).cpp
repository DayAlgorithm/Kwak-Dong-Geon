class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= (int)s.size()) return s;
        
        vector<string> rows(numRows);
        int row = 0;
        int step = 1;
        
        for (char c : s) {
            rows[row] += c;
            if (row == 0) step = 1;
            else if (row == numRows - 1) step = -1;
            row += step;
        }
        
        string ans;
        for (int i = 0; i < numRows; ++i) {
            ans += rows[i];
        }
        return ans;
    }
};
