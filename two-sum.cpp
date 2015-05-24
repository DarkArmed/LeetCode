// #include <iostream>
// #include <vector>
// #include <map>

// using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> index;
        int len = nums.size();
        vector<int> ans(2);
        
        for(int i = 0; i < len; ++i)
        {
            if(index.find(target - nums[i]) != index.end())
            {
                ans[0] = index[target - nums[i]] + 1;
                ans[1] = i + 1;
                break;
            }
            index[nums[i]] = i;
        }
        
        return ans;
    }
};

// int main()
// {
//   Solution s;

//   int a[] = {2, 7, 11, 15};
//   std::vector<int> nums(a, a + 4);

//   s.twoSum(nums, 22);

//   return 0;
// }
