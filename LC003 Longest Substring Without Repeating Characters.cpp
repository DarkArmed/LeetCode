class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> last(256, -1);
        int head = 0, longSub = 0;
        int len = s.length();
        for(int i = 0; i < len; ++i)
        {
             if(last[s[i]] < head)
             {
                 longSub = max(longSub, i - head + 1);
             }
             else
             {
                 head = last[s[i]] + 1;
             }
             last[s[i]] = i;
        }
        
        return longSub;
    }
};