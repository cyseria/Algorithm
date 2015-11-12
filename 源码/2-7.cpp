#include <stdio.h>

int huafen(int n, int m)
{
    if (m < 1 || n < 1)
        return 0;
    if (m == 1 || n == 1)
        return 1;
    if (m > n)
        return huafen(n,n);
    if (m == n) {
        return 1 + huafen(n,m-1);
    }
    return huafen(n,m-1) + huafen(n-m,m);

}
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    printf("%d",huafen(n,m));

    return 0;
}
