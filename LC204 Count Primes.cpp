class Solution {
public:
    int countPrimes(int n) {
        if(n < 3) return 0;
        double c = sqrt(n);
        bool *b = new bool[n];
        for(int i = 3; i <= c; i += 2)
        {
            if(!b[i])
            {
                for(int j = i * i, k = i << 1; j < n; j += k)
                {
                    b[j] = true;
                }
            }
        }
        
        int count = 1;
        
        for(int i = 3; i < n; i += 2)
        {
            if(!b[i]) count++;
        }
        
        return count;
    }
};