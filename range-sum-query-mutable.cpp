class NumArray {
private:
    vector<int> A;
    vector<int> BIT;
    int N;
    
public:
    NumArray(vector<int> &nums) {
        N = nums.size();
        A = vector<int>(nums);
        BIT = vector<int>(N + 1);
        for(int k = 0; k < N; ++k) {
            edit(k + 1, A[k]);
        }
    }
    
    int lowbit(int x) {
        return x & (-x);
    }

    void edit(int i, int delta) {
        for(int k = i; k <= N; k += lowbit(k)) {
            BIT[k] += delta;
        }
    }

    void update(int i, int val) {
        edit(i + 1, val - A[i]);
        A[i] = val;
    }
    
    int sum(int n) {
        int ans = 0;
        for(int k = n; k > 0; k -= lowbit(k)) {
            ans += BIT[k];
        }
        return ans;
    }

    int sumRange(int i, int j) {
        return sum(j + 1) - sum(i);
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);