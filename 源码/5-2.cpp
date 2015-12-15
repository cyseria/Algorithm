#include <iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;

int n, c;
int sum = 0;
int leaf = 0;

void getSubSum(int i,int *ary,int *x){

    if(i >= n){
        leaf++;                        //叶子节点+1
        if(sum == c) {
            for(int i = 0; i < n; i++){
                if(x[i]==1)
                    cout<<ary[i]<<" ";
            }
            exit(0);                //只输出第一个解
        }
        if(leaf == pow(2,n))
            cout<<"No Solution"<<endl;
        return;
    }

    x[i] = 1;                                  //遍历左子树
    sum += ary[i];
    getSubSum(i+1,ary,x);
    sum -= ary[i];
    x[i] = 0;                                   //遍历右子树
    getSubSum(i+1,ary,x);
}


int main()
{
    cin >> n >> c;
    int *x = new int[n];           //由于只输出遇到的第一个解，所以此处只设置一个解向量
    int *a = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    getSubSum(0,a,x);
    return 0;
}
