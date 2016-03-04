class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        int n = heights.size();
        int max = 0;
        stack<int> idx;
        for(int k = 0; k < n; ++k) {
            while(!idx.empty() && heights[idx.top()] > heights[k]) {
                int height = heights[idx.top()];
                idx.pop();
                int width = idx.empty() ? k : k - idx.top() - 1;
                int area = height * width;
                if(max < area) {
                    max = area;
                }
            }
            idx.push(k);
        }
        return max;
    }
};