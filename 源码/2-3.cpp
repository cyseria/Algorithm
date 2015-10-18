#include <stdio.h>
#include <stdlib.h>

int fun1 (int n)
{
    int result;
    if (n == 1) {
        return 1;
    }
    else if (n == 2) {
        return 2;
    }
    else if (n == 3) {
        return 2;
    }
    else {
        result = fun1(n/2)* 2;
        return result;
    }
}
int fun2 (int n, int m)
{
    int s = 0;
    for(int i = 2; i <= n; i++) {
         s = (s + m) % i;
    }
    return s + 1;
}
int main()
{
    int m, n;
    scanf("%d %d",&n,&m);//n个人,第m个人退出
    printf("%d %d",fun1(n),fun2(n,m));
    return 0;
}
