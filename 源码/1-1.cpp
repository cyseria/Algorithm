#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    double s=0;
    scanf("%d\n",&n);
    double arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%lf",&arr[i]);

    }
    for (int i = 0; i < n; i++) {
        s += arr[i];
        printf("%.2lf ", s / (i+1));
    }
    return 0;
}
