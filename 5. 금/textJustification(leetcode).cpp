class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int n = words.size(), i = 0;
        
        while (i < n) {
            int j = i, lenWords = 0;
            while (j < n && lenWords + (j - i) + (int)words[j].size() <= maxWidth) {
                lenWords += words[j].size();
                ++j;
            }
            
            int numWords = j - i, numGaps = numWords - 1;
            string line;
            
            if (j == n || numGaps == 0) {
                for (int k = i; k < j; ++k) {
                    if (k > i) line.push_back(' ');
                    line += words[k];
                }
                while ((int)line.size() < maxWidth) {
                    line.push_back(' ');
                }
            } else {
                int totalSpaces = maxWidth - lenWords;
                int base = totalSpaces / numGaps;
                int extra = totalSpaces % numGaps;
                for (int k = i; k < j; ++k) {
                    line += words[k];
                    if (k == j - 1) break; 
                    int spaces = base + ( (k - i) < extra ? 1 : 0 );
                    line.append(spaces, ' ');
                }
            }
            
            ans.push_back(line);
            i = j;
        }
        
        return ans;
    }
};
