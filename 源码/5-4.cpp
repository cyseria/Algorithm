#include <iostream>
#include <algorithm>
using namespace std;

int n,m; //n个任务，m台机器

int x[100];
int bestx[100];
int best=0;

bool cmp(int a,int b)
{
  return a > b;
}

void printArr(int *arr, int n)
{
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

//贪心算法
void distribute_1(int *tasktime, int *mtime)
{
    sort(tasktime,tasktime+n,cmp);
    if (n <= m) { //任务数量小于机器数
        cout << tasktime[0] << endl;
    } else { //把任务给空闲的机器
        for (int i = 0; i < n; i++) {
            //printArr(mintime,m);
            *min_element(mtime, mtime+m) += tasktime[i];
        }
        cout << *max_element(mtime, mtime + m) << endl;
    }
}

//mtime是个数组：m个元素对应m台机的空闲时间，即第二种回溯算法在搜索过程中已探察过任务且针对某台机的完成时间和；

//回溯算法
void distribute_2(int dep, int *tasktime, int *mtime)
{
    if (dep == n) //叶子
    {
        int temp = *max_element(mtime, mtime + m); //计算走该路径所需时间
        if (temp < best) { //更新最小时间和最小时间路径
            best = temp;
        }
        return;
    }

    for(int i = 0; i < m; i++)
    {
        mtime[i] += tasktime[dep];
        if(mtime[i] < best) { //
            distribute_2(dep+1, tasktime, mtime);
        }
        mtime[i] -= tasktime[dep];
    }

}

//将机器运行时间默认置0
void initMtime(int *mtime)
{
    for (int i = 0; i < m; i++) {
        mtime[i] = 0;
    }
}

int main()
{
    cin >> n >> m;
    int *tasktime = new int[n]; //任务需要的时间
    int *mtime = new int[m]; //机器运行时间
    initMtime(mtime);
    for (int i = 0; i < n; i++) {
        cin >> tasktime[i];
        best += tasktime[i];
    }
    distribute_1(tasktime, mtime);
    initMtime(mtime);
    distribute_2(0,tasktime, mtime);

    cout << best << endl;
    return 0;
}

