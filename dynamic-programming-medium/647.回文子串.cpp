/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 *
 * https://leetcode-cn.com/problems/palindromic-substrings/description/
 *
 * algorithms
 * Medium (64.43%)
 * Likes:    350
 * Dislikes: 0
 * Total Accepted:    55.3K
 * Total Submissions: 85.8K
 * Testcase Example:  '"abc"'
 *
 * 给定一个字符串，你的任务是计算这个字符串中有多少个回文子串。
 * 
 * 具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入："abc"
 * 输出：3
 * 解释：三个回文子串: "a", "b", "c"
 * 
 * 
 * 示例 2：
 * 
 * 输入："aaa"
 * 输出：6
 * 解释：6个回文子串: "a", "a", "a", "aa", "aa", "aaa"
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 输入的字符串长度不会超过 1000 。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool dp[1005][1005];
    bool getDp(string s, int i, int j){
        if(i==j){
            //cout<<"i==j"<<endl;
            return true;
        }
        else if(i+1==j&&s[i]==s[j]){
            //cout<<"i+1=j"<<endl;
            return true;
        }
        else if(s[i]==s[j]&&dp[i+1][j-1]==true){
            //cout<<"s[i]==s[j]"<<endl;
            return true;
        }
        return false;
    }
    int countSubstrings(string s) {
        int ans = 0;
        for(int j=0;j<s.length();j++)
        {
            for(int i=0;i+j<s.length();i++){
                dp[i][i+j]=getDp(s,i,i+j);
                if(dp[i][i+j]==true){
                    ans++;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

