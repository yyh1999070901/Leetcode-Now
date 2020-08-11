/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 *
 * https://leetcode-cn.com/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (42.76%)
 * Likes:    548
 * Dislikes: 0
 * Total Accepted:    128.3K
 * Total Submissions: 299.9K
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * 给出一个区间的集合，请合并所有重叠的区间。
 * 
 * 示例 1:
 * 
 * 输入: [[1,3],[2,6],[8,10],[15,18]]
 * 输出: [[1,6],[8,10],[15,18]]
 * 解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
 * 
 * 
 * 示例 2:
 * 
 * 输入: [[1,4],[4,5]]
 * 输出: [[1,5]]
 * 解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。
 * 
 */

// @lc code=start
class Solution {
public:
    struct node{
        int start;
        int end;
        node(int start,int end):start(start),end(end){};
    };
    static bool cmp(node x,node y)
    {
        if(x.start==y.start)
        {
            return x.end<y.end;
        }
        return x.start<y.start;
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        if(intervals.size()==0){
            return ans;
        }
        vector<node>v;
        for(int i=0;i<intervals.size();i++)
        {
            int x = intervals[i][0];
            int y = intervals[i][1];
            v.push_back(node(x,y));
        }
        sort(v.begin(),v.end(),cmp);
        stack<node>s;
        s.push(v[0]);
        for(int i=1;i<v.size();i++)
        {
            node temp = s.top();
            if(temp.end>=v[i].start)
            {
                node temp1(s.top().start,max(v[i].end,s.top().end));
                s.pop();
                s.push(temp1);
            }
            else
            {
                s.push(v[i]);
            }
        }

        while(!s.empty())
        {
            node temp = s.top();
            s.pop();
            int xx = temp.start;
            int yy = temp.end;
            vector<int>vv;
            vv.push_back(xx);
            vv.push_back(yy);
            ans.push_back(vv);                
        }
        vector<vector<int>>realans;
        for(int i=ans.size()-1;i>=0;i--){
            realans.push_back(ans[i]);
        }
        return realans;
    }
};
// @lc code=end

