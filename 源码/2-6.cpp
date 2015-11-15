
#include <stdio.h>

int MAXCOUNT = 0, //众数重数
    NUM = 0; //众数

void split(int a[],int n, int &l,int &r)
{
    int mid = n/2;
    for (l = 0; l < n; ++l) {
        if (a[l] == a[mid])
            break;
    }
    for (r = l + 1; r < n; ++r) {
        if (a[r] != a[mid])
            break;
    }
}

//求众数
void getMode(int a[], int n)
{
    int l,r;
    split(a,n,l,r);
    int count = r - l; //某一段的众数的重数

    //更新
    if(count > MAXCOUNT) {
        MAXCOUNT = count;
        NUM = a[n/2];
    }

    //左边递归
    if (l+1 > MAXCOUNT) {
        getMode(a,l+1);
    }
    //右边递归
    if (n-r > MAXCOUNT) {
        getMode(a+r,n-r);
    }
}

//排序
void insertSort(int arr[], int n){
	for(int i = 1;i < n;i++){
		int temp = arr[i];
		int j = i - 1;
		while(temp < arr[j]){
			arr[j+1] = arr[j];
			j--;
			if(j == -1)	break;
		}
		arr[j+1] = temp;
	}
}
int main()
{
    int n;
    scanf("%d",&n);
    int *a = new int[n];
    for (int i = 0; i < n; i++) {
        scanf("%d",&a[i]);
    }
    insertSort(a,n);
    getMode(a,n);
    printf("%d %d",NUM,MAXCOUNT);
    return 0;
}
