#include <iostream>
#include <stdlib.h>
#include <time.h>
#include<queue>

#define MIN 1            //���������Сֵ
#define MAX 9           //����������ֵ
#define INF 1000         //�����

using namespace std;

void random_matrix(int **m,int n){                //����һ��������󣬾�����Ԫ��������[MIN,MAX]���������
                                                   //m[i][j]��ʾ��i�������j��������·����Ȩ�أ�m[i][j]��ʾ�������㲻ֱ������
    int i,j;
    srand((unsigned)time(NULL));                  //�����������������Ϊ��ǰʱ��
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            if (i == j) {
               m[i][j]=0;                             //�Խ��ߵ�Ԫ��Ĭ��Ϊ0�����ɵ�����ͼû�л�.
            }
            else if(i<j){
                m[i][j] = MIN+rand()%(MAX-MIN+1);   //����Ԫ����[MIN,MAX]�������������
            }
            else m[i][j] = m[j][i];                 //���ɵ�������ͼ�����m[i][j]=m[j][i]
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
    cout<<"\nfloyd������ʱ��Ϊ"<<totaltime<<"��"<<endl;
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
    cout<<"\nSPFA������ʱ��Ϊ"<<totaltime<<"��"<<endl;
}

int main()
{
    int i,n = 5,**m;
    cout << "ͼ�Ķ�����Ϊ:" << n << endl;
    m = new int*[n];
    for(i=0;i<n;i++){
        m[i]=new int[n];
    }

    random_matrix(m,n);
    cout << "ԭʼͼ��" << endl;
    printfArr(m,n);
    cout << endl << "floyd�㷨��" << endl;
    floyd(m,n);
    cout << endl << "SPFA�㷨��" << endl;
    SPFA(m,n);

    return 0;
}
