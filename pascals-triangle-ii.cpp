class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row = {1};
        for(int k = 0; k < rowIndex; ++k) {
            row.push_back(1);
            for(int i = k; i > 0; --i) {
                row[i] += row[i - 1];
            }
        }
        
        return row;
    }
};