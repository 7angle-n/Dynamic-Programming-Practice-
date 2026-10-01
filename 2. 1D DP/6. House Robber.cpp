// Problem: https://leetcode.com/problems/house-robber/
class Solution {
    int rob_house(int i, vector<int> &nums, vector<int> &memo){
        if(i >= nums.size()) return 0;
        if(memo[i] != -1) return memo[i];
        int ans = max(rob_house(i + 1, nums, memo), rob_house(i + 2, nums, memo) + nums[i]);
        return memo[i] = ans;
    }
public:
    int rob(vector<int>& nums) {
        vector<int> memo(nums.size() + 1, -1);
        return rob_house(0, nums, memo);
    }
};
