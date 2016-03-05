class NumArray {
private:
    vector<int> sum;
public:
    NumArray(vector<int> &nums) {
        sum = vector<int>(nums);
        for(int i = 1; i < sum.size(); ++i) {
            sum[i] += sum[i - 1];
        }
    }

    int sumRange(int i, int j) {
        return i == 0 ? sum[j] : sum[j] - sum[i - 1];
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);