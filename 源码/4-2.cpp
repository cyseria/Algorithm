#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#define REP(i, n) for(int i = 0; i < (n); ++i)
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
const int N = 110;
int n, m, a[N];

priority_queue<int, vector<int>, greater<int> > qmi;
priority_queue<int, vector<int>, less<int> >qmx;

int main()
{

    int n, k;
    while(scanf("%d%d", &n, &k) > 0) {
        REP(i, n) {
            scanf("%d", a + i);
            qmi.push(a[i]);
            qmx.push(a[i]);
        }

        int ans = 0;
        if(n > k) {
            int t = (n - k) % (k - 1);
            if(t) {
                while(!qmi.empty() && t >= 0) {
                    ans += qmi.top();
                    qmi.pop();
                    --t;
                }
                if(!qmi.empty()) qmi.push(ans);
            }
        }
        while(true) {
            int a = 0;
            for(int i = 0; !qmi.empty() && i < k; ++i) {
                a += qmi.top();
                qmi.pop();
            }
            ans += a;
            if(qmi.empty()) break;
            qmi.push(a);
        }
        printf("%d ", ans);

        ans = 0;
        while(true) {
            int a = 0;
            for(int i = 0; i < 2 && !qmx.empty(); ++i) {
                a += qmx.top();
                qmx.pop();
            }
            ans += a;
            if(qmx.empty()) break;
            qmx.push(a);
        }
        printf("%d\n", ans);
    }
    return 0;
}
