
#include <stdio.h>
#include <stdlib.h>
int countNum = 0;
void count (int num)
{
    int i;
    for (i = num - 1; i > 1; i--) {
        if (num % i == 0)  {
            countNum ++;
            count(num/i);
        }
    }
}
int main()
{
    int num;
    scanf("%d",&num);
    if(num != 0) {
        count(num);
        printf("%d\n",countNum+1);
    }
    return 0;
}