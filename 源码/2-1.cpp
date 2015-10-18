#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

int total = 0;
inline void Swap(char &a, char &b)
{
    char temp = a;
    a = b;
    b = temp;
}
int isRepeat (char str[], int a, int b)
{
    for (int i = a; i < b; i++) {
        if (str[i] == str[b])
            return FALSE;
    }
    return TRUE;
}
int Perm(char list[], int k, int m)
{

    //产生list[k:m]的所有排列

    if (k == m) {
        for (int i = 0; i <= m; i++) {
             printf("%c",list[i]);
        }
        printf("\n");
        total ++;
    }
    else {
        for (int i = k; i <= m; i++) {
            if (isRepeat(list, k, i)) {
                Swap(list[k], list[i]);
                Perm(list, k+1, m);
                Swap(list[k],list[i]);
            }

        }
    }
    return total;
}

int main()
{
    int LENGTH = 0,i;
    scanf("%d\n",&LENGTH); //元素个数： >=1 && <=15
    char str[LENGTH];
    for (i = 0; i < LENGTH; i++) {
        scanf("%c",&str[i]);
    }
    printf("%d\n",Perm(str,0,LENGTH-1));
    return 0;
}
