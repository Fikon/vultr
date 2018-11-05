/*
 * Description:
 * You are a professional robber planning to rob houses along
 * a street. Each house has a certain amount of money stashed,
 * the only constraint stopping you from robbing each of them
 * is that adjacent houses have security system connected and it
 * will automatically contact the police if two adjacent houses
 * were broken into on the same night.
 * Given a list of non-negative integers representing the amount
 * of money of each house, determine the maximum amount of money
 * you can rob tonight without alerting the police.
 *
 * Example:
 * Input: [1, 2, 3, 1]
 * Output: 4
 * Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
 *              Total amount you can rob = 1 + 3 = 4.
 *
 * 解题思路：
 * 动态规划模板题，用一个列表记录状态，然后遍历一边给定的house数组，对于
 * 每个house，偷或者不偷两种选择，由于记录了前面的状态，所以只需要比较两种
 * 选择对应的金额，然后取最大的选择即可，然后更新状态列表。
 *
 *
 */
class Solution{
    public:
        int max(int a, int b){
            return a > b ? a : b;
        }

        int rob(vector<int>& nums){
            if(nums.size() == 0){
                return 0;
            }
            if(nums.size() == 1){
                return nums[0];
            }
            vector<int> res(nums.zie(), 0);
            res[0] = nums[0];
            res[1] = max(nums[0], nums[1]);
            for(int i = 2; i < nums.size(); ++i){
                res[i] = max(res[i - 1], res[i - 2] + nums[i]);
            }
            return res[nums.size() - 1];
        }
};
