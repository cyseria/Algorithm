#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10000

int x[MAXSIZE],y[MAXSIZE],k;

int fun(int xBeg, int xEnd, int yBeg, int yEnd)
{
    int xMid = xBeg + ( xEnd - xBeg ) / 2,
        yMid = yBeg + ( yEnd - yBeg ) / 2,
        lMid = xMid - xBeg + yMid - yBeg + 2; //x,y数组分半之后的总长度
    if (xBeg > xEnd)
        return y[yBeg + k - 1];
    if (yBeg > yEnd)
        return x[xBeg + k - 1];

    if (x[xMid] < y[yMid]) {
        if (k < lMid) {
            return fun(xBeg, xEnd, yBeg, yMid - 1);
        }
        else {
            k = k - ( xMid - xBeg + 1);
            return fun(xMid + 1, xEnd, yBeg, yEnd);
        }
    }
    else {
        if (k < lMid) {
            return fun(xBeg, xMid - 1, yBeg, yEnd);
        }
        else {
             k = k - (yMid - yBeg + 1);
            return fun(xBeg, xEnd, yMid + 1, yEnd);
        }
    }


}

int main()
{
    int m,n,i;
    scanf("%d %d %d",&m,&n,&k);
    for (i = 0; i < m; i++) {
        scanf("%d",&x[i]);
    }
    for (i = 0; i < n; i++) {
        scanf("%d",&y[i]);
    }
    printf("%d",fun(0,m-1,0,n-1));
    return 0;
}
