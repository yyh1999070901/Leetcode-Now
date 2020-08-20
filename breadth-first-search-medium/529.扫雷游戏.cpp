/*
 * @lc app=leetcode.cn id=529 lang=cpp
 *
 * [529] 扫雷游戏
 *
 * https://leetcode-cn.com/problems/minesweeper/description/
 *
 * algorithms
 * Medium (62.34%)
 * Likes:    104
 * Dislikes: 0
 * Total Accepted:    12.3K
 * Total Submissions: 19.7K
 * Testcase Example:  '[["E","E","E","E","E"],["E","E","M","E","E"],["E","E","E","E","E"],["E","E","E","E","E"]]\n' +
  '[3,0]'
 *
 * 让我们一起来玩扫雷游戏！
 * 
 * 给定一个代表游戏板的二维字符矩阵。 'M' 代表一个未挖出的地雷，'E' 代表一个未挖出的空方块，'B'
 * 代表没有相邻（上，下，左，右，和所有4个对角线）地雷的已挖出的空白方块，数字（'1' 到 '8'）表示有多少地雷与这块已挖出的方块相邻，'X'
 * 则表示一个已挖出的地雷。
 * 
 * 现在给出在所有未挖出的方块中（'M'或者'E'）的下一个点击位置（行和列索引），根据以下规则，返回相应位置被点击后对应的面板：
 * 
 * 
 * 如果一个地雷（'M'）被挖出，游戏就结束了- 把它改为 'X'。
 * 如果一个没有相邻地雷的空方块（'E'）被挖出，修改它为（'B'），并且所有和其相邻的未挖出方块都应该被递归地揭露。
 * 如果一个至少与一个地雷相邻的空方块（'E'）被挖出，修改它为数字（'1'到'8'），表示相邻地雷的数量。
 * 如果在此次点击中，若无更多方块可被揭露，则返回面板。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入: 
 * 
 * [['E', 'E', 'E', 'E', 'E'],
 * ⁠['E', 'E', 'M', 'E', 'E'],
 * ⁠['E', 'E', 'E', 'E', 'E'],
 * ⁠['E', 'E', 'E', 'E', 'E']]
 * 
 * Click : [3,0]
 * 
 * 输出: 
 * 
 * [['B', '1', 'E', '1', 'B'],
 * ⁠['B', '1', 'M', '1', 'B'],
 * ⁠['B', '1', '1', '1', 'B'],
 * ⁠['B', 'B', 'B', 'B', 'B']]
 * 
 * 解释:
 * 
 * 
 * 
 * 示例 2：
 * 
 * 输入: 
 * 
 * [['B', '1', 'E', '1', 'B'],
 * ⁠['B', '1', 'M', '1', 'B'],
 * ⁠['B', '1', '1', '1', 'B'],
 * ⁠['B', 'B', 'B', 'B', 'B']]
 * 
 * Click : [1,2]
 * 
 * 输出: 
 * 
 * [['B', '1', 'E', '1', 'B'],
 * ⁠['B', '1', 'X', '1', 'B'],
 * ⁠['B', '1', '1', '1', 'B'],
 * ⁠['B', 'B', 'B', 'B', 'B']]
 * 
 * 解释:
 * 
 * 
 * 
 * 
 * 
 * 注意：
 * 
 * 
 * 输入矩阵的宽和高的范围为 [1,50]。
 * 点击的位置只能是未被挖出的方块 ('M' 或者 'E')，这也意味着面板至少包含一个可点击的方块。
 * 输入面板不会是游戏结束的状态（即有地雷已被挖出）。
 * 简单起见，未提及的规则在这个问题中可被忽略。例如，当游戏结束时你不需要挖出所有地雷，考虑所有你可能赢得游戏或标记方块的情况。
 * 
 * 
 */

// @lc code=start
class Solution {

public:
    struct Node{
        int x;
        int y;
        Node(int x,int y):x(x),y(y){};
    };

    int vis[57][57];
    int dir_x[8] = {-1,-1,-1,0,0,1,1,1};
    int dir_y[8] = {-1,0,1,-1,1,-1,0,1};

    bool checkInside(int x,int y, vector<vector<char>>& board){
        if(x < board.size()  && x >= 0 && y < board[x].size() && y>= 0){
            return true;
        }
        return false;
    }

    int checkAround(int x,int y,vector<vector<char>>& board){
        int ans = 0;
        for(int i=0;i<8;i++){
            int x_new = x + dir_x[i];
            int y_new = y + dir_y[i];
            if(checkInside(x_new, y_new, board)&&board[x_new][y_new]=='M'){
                ans++;
            }
        }
        return ans;
    }

    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        memset(vis,0,sizeof(vis));

        int x = click[0];
        int y = click[1];
        int cnt = 0;

        if(board[x][y] == 'M'){
            board[x][y] = 'X';
        }
        else{
            queue<Node>q;
            q.push(Node(x,y));
            while(!q.empty()){
                Node temp = q.front();
                q.pop();
                //vis[temp.x][temp.y] = 1;
                int boomNumber = checkAround(temp.x,temp.y,board);
                if(boomNumber!=0){
                    board[temp.x][temp.y] = (char)(boomNumber+'0');
                }
                else{
                    board[temp.x][temp.y] = (char)'B';
                    for(int i=0;i<8;i++){
                        int xx = temp.x + dir_x[i];
                        int yy = temp.y + dir_y[i];
                        if(checkInside(xx,yy,board)&&vis[xx][yy]==0){
                            vis[xx][yy]=1;
                            q.push(Node(xx,yy));
                        }
                    }
                }
            }
        }
        return board;
    }
};
// @lc code=end

