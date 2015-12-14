#include <iostream>

using namespace std;

int n,           //工作量n
    cost = 0,            //总花费
    x[100] = {0},        //X[j]，第j号工作是否被分配,0表示没有，1表示有
    worker1[100],worker2[100],        //表示第1个工作分配给第2个人，第2个工作分配给第1个人，第3个工作分配给第3个人
    c[100][100]; //c[i][j] i号工人完成j号工作的价钱

//sum：费用总和
//i：第i号工人
void work(int i, int sum)
{
    if (i > n && sum < cost) {
        cost = sum;
        for (int i = 1; i <= n; i++) {
            worker2[i] = worker1[i];
        }
        return;
    }
    for (int j = 1; j <= n; j++) {
        if (x[j] == 0) {
            x[j] = i;
            worker1[i] = j; //第i个人的工作为j;
            //cout << "工作" << j << "被分给第" << i <<"人" << endl;
            work(i+1, sum + c[i][j]);
            x[j] = 0;
        }
    }
}

int main()
{
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> c[i][j];
        }
        cost += c[i][i];
        worker2[i] = i;
    }
    work(1,0);
    cout << cost << endl;
    for (int i = 1; i<=n ; i++) {
        cout << worker2[i] << " ";
    }

    return 0;
}
