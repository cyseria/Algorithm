#include <iostream>
#include <stdlib.h>
#include <time.h>
#include<queue>

#define MIN 1            //顶点距离最小值
#define MAX 9           //顶点距离最大值
#define INF 1000         //无穷大

using namespace std;

void random_matrix(int **m,int n){                //生产一个随机矩阵，矩阵内元素在区间[MIN,MAX]中随机生成
                                                   //m[i][j]表示第i个点与第j个点相连路径的权重，m[i][j]表示这两个点不直接相连
    int i,j;
    srand((unsigned)time(NULL));                  //把随机函数种子设置为当前时间
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            if (i == j) {
               m[i][j]=0;                             //对角线的元素默认为0，生成的网络图没有环.
            }
            else if(i<j){
                m[i][j] = MIN+rand()%(MAX-MIN+1);   //矩阵元素在[MIN,MAX]区间内随机生成
            }
            else m[i][j] = m[j][i];                 //生成的是无向图，因此m[i][j]=m[j][i]
        }
    }
}

void printfArr(int **m, int n)
{
    for(int i=0; i < n; i++){
        for(int j=0; j<n; j++)
            cout << m[i][j] << " ";
        cout << endl;
    }
}

void pritfDis(int *dis, int n)
{
    for (int i = 0; i < n; i++) {
        cout << dis[i] << " ";
    }
    cout << endl;
}

void floyd(int **m, int n)
{
    clock_t start,finish;
    double totaltime;
    start = clock();

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (m[i][j] > m[i][k] + m[k][j] ) {
                    m[i][j] = m[i][k] + m[k][j];
                }
            }
        }
    }
    printfArr(m,n);

    finish=clock();
    totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<"\nfloyd的运行时间为"<<totaltime<<"秒"<<endl;
}



void init_SPFA_arr(int *dis, int *vertex, bool *isInQueue,int n,int num)
{
    for (int j = 0; j < n; j++) {
        if (j == num) {
            dis[j] = 0;
            isInQueue[j] = true;
        } else {
            dis[j] = INF;
            isInQueue[j] = false;
        }
        vertex[j] = j;
    }
}

void SPFA(int **m, int n)
{
    clock_t start,finish;
    double totaltime;
    start = clock();

    queue<int> q;
    int *dis = new int[n],
        *vertex = new int[n];
    bool *isInQueue = new bool[n];

    for (int i = 0; i < n; i++) {
        init_SPFA_arr(dis,vertex,isInQueue,n,i);
        q.push(i);
        while (!q.empty()) {
            for (int k = 0; k < n; k++) {
                int point = vertex[k],
                    qfront = q.front(),
                    newDis = m[qfront][k] + dis[qfront];
                if (m[qfront][k] > 0 && newDis < dis[k] ) {
                    dis[k] = newDis;
                    if (!isInQueue[point]) {
                        q.push(point);
                        isInQueue[point] = true;
                    }
                }
            }
            isInQueue[q.front()] = false;
            q.pop();
        }
        pritfDis(dis, n);
    }

    finish=clock();
    totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<"\nSPFA的运行时间为"<<totaltime<<"秒"<<endl;
}

int main()
{
    int i,n = 5,**m;
    cout << "图的顶点数为:" << n << endl;
    m = new int*[n];
    for(i=0;i<n;i++){
        m[i]=new int[n];
    }

    random_matrix(m,n);
    cout << "原始图：" << endl;
    printfArr(m,n);
    cout << endl << "floyd算法：" << endl;
    floyd(m,n);
    cout << endl << "SPFA算法：" << endl;
    SPFA(m,n);

    return 0;
}
