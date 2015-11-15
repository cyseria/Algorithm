
#include <stdio.h>

int same[20];

int p(int n,int same[]){
    int sum = 0;

    if(n == 1){
        return 1;
    }
    if(n>1)
    for(int i = 1;i<n;i++){
        if(same[i] == 0)
            same[i] = p(i,same);
        if(same[n-i] == 0)
            same[n-i] = p(n-i,same);
        sum = sum + same[i]*same[n-i];
    }

    return sum;
}

int main()
{
    int n;
    scanf("%d",&n);
    printf("%d",p(n,same));
    return 0;

}
