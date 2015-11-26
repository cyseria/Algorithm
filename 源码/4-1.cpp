# include <stdio.h>
# include <algorithm>
using namespace std;

struct val //区间
{
    int l, r; //左右数值
}p[50];

bool cmp(struct val a, struct val b)
{
    return a.r < b.r;
}

int main()
{
    int n; //区间数
    scanf("%d",&n);

    //输入区间，左小右大
    for (int i = 0; i < n; i++) {
        int l,r;
        scanf("%d%d",&l,&r);
        if (l <= r) {
            p[i].l = l;
            p[i].r = r;
        } else {
            p[i].l = r;
            p[i].r = l;
        }
    }

    sort(p,p+n,cmp); //按右端点升序排列

    int cnt = 1, //最大相容数目
        limit = p[0].r;
    for (int i = 1; i < n; i++) {
        if (p[i].l >= limit) { //贪心选择满足相容性且终点最小的区间
            cnt ++;
            limit = p[i].r;
        }
    }
    cnt = n - cnt;
    printf("%d",cnt);
    return 0;
}