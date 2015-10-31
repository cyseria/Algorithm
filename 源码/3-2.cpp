#include <stdio.h>

//最长上升子串
int longSub(int *a, int n)
{
    int *b = new int[n];
    int maxSub = 1;
    b[0] = 1;
    for (int i = 1; i < n; i++) {
        b[i] = 1;
        for (int j = 0; j < i; j++) {
            if (a[i] > a[j] && (b[j] + 1) > b[i]) {
                b[i] = b[j] + 1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (b[i] > maxSub) {
            maxSub = b[i];
        }
    }
    return maxSub;
}

int main()
{
    int n;
    scanf("%d",&n);
    while(n != 0) {
        int *arr = new int[n];
        for (int i = 0; i < n; i++) {
            scanf("%d",&arr[i]);
        }
        printf("%d\n",longSub(arr,n));
        scanf("%d",&n);
    }
    return 0;
}
