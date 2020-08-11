/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 *
 * https://leetcode-cn.com/problems/surrounded-regions/description/
 *
 * algorithms
 * Medium (40.51%)
 * Likes:    331
 * Dislikes: 0
 * Total Accepted:    62.1K
 * Total Submissions: 148.4K
 * Testcase Example:  '[["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]'
 *
 * 给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。
 * 
 * 找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。
 * 
 * 示例:
 * 
 * X X X X
 * X O O X
 * X X O X
 * X O X X
 * 
 * 
 * 运行你的函数后，矩阵变为：
 * 
 * X X X X
 * X X X X
 * X X X X
 * X O X X
 * 
 * 
 * 解释:
 * 
 * 被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。 任何不在边界上，或不与边界上的 'O' 相连的 'O'
 * 最终都会被填充为 'X'。如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。
 * 
 */

// @lc code=start
class Solution {
public:
    int top;
    int down;
    int right;
    int left;
    int vis[1000][10000];
    struct node{
        int x;
        int y;
        node(int x,int y):x(x),y(y){};
    };
    int xx_dir[4] = {-1,1,0,0};
    int yy_dir[4] = {0,0,1,-1};
    queue<node>q;
    vector<node>v;
    void solve(vector<vector<char>>& board) {
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board.size();j++)
            {
                vis[i][j]=0;
            }
        }
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[i].size();j++)
            {
                if(board[i][j]=='O'&&vis[i][j]==0)
                {
                    //cout<<"i"<<i<<endl;
                    //cout<<"j"<<j<<endl;
                    vis[i][j]=1;
                    top = i;
                    down = i;
                    right = j;
                    left = j;
                    q.push(node(i,j));
                    while(!q.empty())
                    {
                        //cout<<"si"<<q.size()<<endl;
                        node n = q.front();
                        q.pop();
                        v.push_back(n);
                        vis[n.x][n.y]=1;
                        for(int k=0;k<4;k++)
                        {
                            int xx = n.x+xx_dir[k];
                            int yy = n.y+yy_dir[k];
                            //vis[xx][yy]=1;
                            if(xx>=0 && yy>=0 && xx<board.size()&&yy<board[0].size()&&board[xx][yy]=='O')
                            {
                                //cout<<"xx"<<xx<<endl;
                                //cout<<"yy"<<yy<<endl;
                                //cout<<vis[xx][yy]<<endl;
                                if(vis[xx][yy]==0)
                                {
                                    //cout<<"jinlia"<<endl;
                                    q.push(node(xx,yy));
                                    vis[xx][yy]=1;
                                    //cout<<vis[xx][yy]<<"vis"<<endl;
                                    top=min(top,xx);
                                    down = max(down,xx);
                                    right = max(right,yy);
                                    left = min(left,yy);
                                }
                            }
                        }
                        //cout<<"size"<<q.size()<<endl;
                    }
                    if(top>0&&down<board.size()-1&&left>0&&right<board[0].size()-1)
                    {
                        for(int k= 0;k<v.size();k++)
                        {
                            int xx = v[k].x;
                            int yy = v[k].y;
                            board[xx][yy]='X';
                        }
                    }   
                    v.clear();
                }

            }
        }
    }
};
// @lc code=end

