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

//��ߵ÷�
int maxNum(int *stone)
{
    sort(stone, stone+n);
    int sum = stone[n-1],     //�ϲ���ĺ�,��ʼֵΪ����ʯ��
        total = 0;            //�ϲ����ܷ�ֵ��sum��ӣ�

    for (int i = n-2; i >= 0; i--) {
        sum += stone[i];
        total += sum;
    }
    return total;
}

//��͵÷�
int minNum(int *stone)
{
    int a[100];
    for (int i = 0; i < n; i++) {
        a[i] = stone[i];
    }
    //����ʯͷÿ�Ѹ�������stone[1]~stone[n],��stone[n]֮�����k-1�����鵥ԪΪ��д;
    //�ϲ�֮ǰ������ɸ�Ϊ0������ѣ�Ŀ��Ϊ�ճɵĶ�����֤ÿ�ζ�����k�Ѻϲ����������һ�Σ����ϲ�Ϊ1�ѡ�
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
