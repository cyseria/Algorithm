
#include <stdio.h>


//一维数组求最大子段
int maxSum1(int *arr, int n)
{
    int sum = 0, b = 0;
    for (int i = 0; i < n; i++) {
        if (b > 0) {
            b += arr[i];
        } else {
            b = arr[i];
        }
        if (b > sum) {
            sum = b;
        }
    }
    return sum;
}

//二维数组最大子段,m行,n列
int maxSum2(int **arr, int m, int n)
{
    int sum = 0;
    int *b = new int[n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            b[j] = 0;
        }
        for (int k = i; k < m; k++) {
            for (int j = 0; j < n; j++) {
                b[j] += arr[k][j];
            }
            int max = maxSum1(b,n);
            if (max > sum) {
                sum = max;
            }
        }
    }
    return sum;
}

//三维数组
int maxSum3(int ***a, int m, int n, int p)
{
    int sum = 0;
    //建立m*n的矩阵
    int **b = new int*[n];
    for (int i = 0; i < n; i++) {
        b[i] = new int[p];
    }

    for (int i = 0; i < m; i++) {
        //数组初始化
        for (int j = 0; j < n ; j++) {
            for (int k = 0; k < p; k++) {
                b[j][k] = 0;
            }
        }

        for (int ii = i; ii < m; ii++) {
            //上下矩阵相加
            for (int jj = 0; jj < n; jj++)
                for (int kk = 0; kk < p; kk++)
                    b[jj][kk] += a[ii][jj][kk];

            int max = maxSum2(b,n,p);
            if (max > sum) {
                sum = max;
            }
        }
    }
    return sum;
}

int main()
{

    int m,n,p;
    scanf("%d %d %d", &m,&n,&p);
    int ***a=new int **[m];
    for(int i = 0; i < m; i++)
    {
        a[i] = new int *[n];
        for (int j = 0; j < n; j++)
            a[i][j] = new int [p];
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            for (int k = 0; k < p; k++) {
                scanf("%d",&a[i][j][k]);
            }
    }


    printf("%d",maxSum3(a, m, n, p));

    return 0;
}
