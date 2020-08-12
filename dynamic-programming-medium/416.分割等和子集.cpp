/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 *
 * https://leetcode-cn.com/problems/partition-equal-subset-sum/description/
 *
 * algorithms
 * Medium (48.76%)
 * Likes:    353
 * Dislikes: 0
 * Total Accepted:    47.3K
 * Total Submissions: 96.7K
 * Testcase Example:  '[1,5,11,5]'
 *
 * 给定一个只包含正整数的非空数组。是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
 * 
 * 注意:
 * 
 * 
 * 每个数组中的元素不会超过 100
 * 数组的大小不会超过 200
 * 
 * 
 * 示例 1:
 * 
 * 输入: [1, 5, 11, 5]
 * 
 * 输出: true
 * 
 * 解释: 数组可以分割成 [1, 5, 5] 和 [11].
 * 
 * 
 * 
 * 
 * 示例 2:
 * 
 * 输入: [1, 2, 3, 5]
 * 
 * 输出: false
 * 
 * 解释: 数组不能分割成两个元素和相等的子集.
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum%2==1){
            return false;
        }
        bool dp[500][30000];
        for(int i=0;i<=nums.size();i++){
            dp[i][0]=false;
        }
        for(int j=0;j<=sum/2;j++){
            dp[0][j]=false;
        }
        dp[0][0]=true;
        for(int i=1;i<=nums.size();i++){
            for(int j=1;j<=sum/2;j++){
                dp[i][j]=dp[i-1][j];
                if(j>=nums[i-1])
                    dp[i][j]=dp[i][j]||dp[i-1][j-nums[i-1]];
            }
        }
        for(int i=1;i<=nums.size();i++){
            if(dp[i][sum/2])
                return true;
        }
        return false;
    }
};
// @lc code=end

