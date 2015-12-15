#include <iostream>
#include <queue>
using namespace std;

typedef struct point
{
    int x;
    int y;
    int dep;
}point;
int board[12][12]; //棋盘，-1为障碍，0为通路
int p[][2]={{-1,-2},{-2,-1},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2}};
point start, end;
//棋盘初始化
void initBoard()
{
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            board[i][j] = -1;
        }
    }
    //除去两个的围栏其他都为通路
    for (int i = 2; i < 10; i++) {
        for (int j = 2; j < 10; j++) {
            board[i][j] = 0;
        }
    }
}

int bfs()
{
    queue<point> Q; //存储跳过的点队列
    Q.push(start);
    while (!Q.empty()) {
        // 从起点开始，检查该位置所能跳的周围8个位置
        for (int i = 0; i < 8; i++) {
            point cur = Q.front();
            //通路
            if (board[cur.x + p[i][0]][cur.y + p[i][1]] == 0) {
                //到达终点
                if (cur.x + p[i][0] == end.x && cur.y + p[i][1] == end.y) {
                    end.dep = cur.dep + 1;
                    return end.dep;
                }
                board[cur.x + p[i][0]][cur.y + p[i][1]] = 1;
                point temp;
                temp.x = cur.x + p[i][0];
                temp.y = cur.y + p[i][1];
                temp.dep = cur.dep + 1;
                Q.push(temp);
            }
        }
        Q.pop();
    }
    return 0;
}

int main()
{
    int b, n = 1; //障碍物格子数,board的个数
    while(cin >> b && b != -1) {
        initBoard();
        //输入障碍
        string a;
        for (int i = 0; i < b; i++) {
            cin >> a;
            board[a[0]-'a'+2][a[1]-'1'+2] = -1;
        }
        //起点
        cin >> a;
        start.x = a[0]-'a'+2;
        start.y = a[1]-'1'+2;
        start.dep = 0;
        //终点
        cin >> a;
        end.x = a[0]-'a'+2;
        end.y = a[1]-'1'+2;

        int dep = bfs();
        if (dep == 0) {
            cout << "board " << n++ << ":" << "not reachable" << endl;
        } else {
            cout << "board " << n++ << ":" << dep << " moves" << endl;
        }

    }
    return 0;
}
