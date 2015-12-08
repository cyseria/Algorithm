# include <stdio.h>
# include <algorithm>
using namespace std;

int n,k;

/*
void printfStone(int stone[])
{
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%d,",stone[i]);
    }
}
*/

//最高得分
int maxNum(int *stone)
{
    sort(stone, stone+n);
    int sum = stone[n-1],     //合并后的和,初始值为最大的石堆
        total = 0;            //合并的总分值（sum相加）

    for (int i = n-2; i >= 0; i--) {
        sum += stone[i];
        total += sum;
    }
    return total;
}

//最低得分
int minNum(int *stone)
{
    int a[100];
    for (int i = 0; i < n; i++) {
        a[i] = stone[i];
    }
    //假设石头每堆个数放于stone[1]~stone[n],且stone[n]之后最多k-1个数组单元为可写;
    //合并之前添加若干个为0的虚拟堆，目的为凑成的堆数保证每次都能有k堆合并（包括最后一次）最后合并为1堆。
    while (n % (k - 1) != 1) {
        a[n++]=0;
    }
    sort(a, a+n);
    int sum = 0;
    for (int i = 0; i <= n - k; i += k-1) {
        for (int j = 0; j < k - 1; j++) {
            a[i+k-1] += a[i+j];
        }
        sum += a[i+k-1];
        sort(a, a+n);
    }
    return sum;
}


int main()
{
    scanf("%d%d",&n,&k);
    int *stone = new int[n];
    for (int i = 0; i < n; i++) {
        scanf("%d",&stone[i]);
    }

    printf("%d %d",minNum(stone),maxNum(stone));
    return 0;
}
