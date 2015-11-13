#include <stdio.h>

int Odd(int i,int j);
int Even(int i, int j);
//Even(I,J)表示I划分为J个正偶数的划分数.
int Even(int i,int j)
{
    if (j > i || j <= 0)
        return 0;
    if ((i == 1 && j == 1) || (i == 2 && j == 2))
        return 0;
    if (i == 2 && j == 1)
        return 1;
    return Odd(i-j,j); //每个偶加数减掉1变为奇加数
}
//Odd(I,J)表示I划分为J个正奇数的划分数
int Odd(int i, int j)
{

    if ((i == 1 && j == 1)||(i == 2 && j == 2))
        return 1;
    if (i == 2 && j == 1)
        return 0;
    if (j > i || j < 0)
        return 0;
    return Odd(i-1,j-1) + Even(i-j,j); //加数含1的方式数 + 加数不含1的方式数
}


int huafen1(int n, int m)
{
    if (m < 1 || n < 1)
        return 0;
    if (m == 1 || n == 1)
        return 1;
    if (m > n)
        return huafen1(n,n);
    if (m == n) {
        return 1 + huafen1(n,m-1);
    }
    return huafen1(n,m-1) + huafen1(n-m,m);

}
int main()
{
    int n,m;
    int i = 0,res1 = 0, res2 = 0;
    scanf("%d %d",&n,&m);
    res1 = huafen1(n,m);
    for (i = 1; i <= n; i++) {
        res2 += Odd(n,i);
    }
    printf("%d %d %d %d", res1,res1,res2,res2);
    return 0;
}
