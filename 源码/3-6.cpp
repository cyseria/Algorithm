#include <iostream>

using namespace std;
int m[100][100];

int sum_a(int *a,int i,int j){
    int sum = 0,k;
    if(i > j)
        return 0;
    for(k = i; k <= j; k++){
        sum += a[k];
    }
    return sum;
}

void combin_stone1(int *a,int n){
    //最低得分
    for (int i = n-2; i >= 0; i--){
        for (int j = i + 1; j < n; j++){
            int temp = m[i][i]+m[i+1][j];
            for (int k = i; k < j; k++){
                temp = min((m[i][k] + m[k+1][j]),temp);
            }
            m[i][j] = temp + sum_a(a,i,j);
        }
    }

    cout << m[0][n-1];

    //最高得分
    for(int i = n-2; i >= 0; i--){
        for(int j = i + 1; j < n; j++){
            int temp = m[i][i] + m[i+1][j];
            for(int k = i; k < j; k++){
                    temp = max(temp,m[i][k]+m[k+1][j]);
            }
            m[i][j] = temp + sum_a(a,i,j);
        }
    }
    cout<<" " << m[0][n-1] << endl;
}

void combin_stone2(int *a,int n) {
    int **m=new int*[2*n-1],*b=new int[2*n-1],i,j,k,temp,n1;
    n1=2*n-1;
    for(i=0;i<n;i++) b[i]=a[i];
    for(i=n;i<n1;i++) b[i]=a[i-n];
    for(i=0;i<n1;i++) m[i]=new int[n1];
    for(i=0;i<n1;i++) m[i][i]=0;

    for(i=n1-2;i>=0;i--){
        j=i+1;
        while(j<n1&&j<(n+i)){
            temp=m[i][i]+m[i+1][j];
            for(k=i;k<j;k++){
                if(temp>(m[i][k]+m[k+1][j]))
                    temp=m[i][k]+m[k+1][j];
            }
            m[i][j]=temp+sum_a(b,i,j);
            j++;
        }
    }

    temp=m[0][n-1];
    for(i=0;i<n;i++){
        if(temp>m[i][n+i-1]) temp=m[i][n+i-1];
    }
    cout<<temp<<" ";

    for(i=n1-2;i>=0;i--){
        j=i+1;
        while(j<n1&&j<(n+i)){
            temp=m[i][i]+m[i+1][j];
            for(k=i;k<j;k++){
                if(temp<(m[i][k]+m[k+1][j]))
                    temp=m[i][k]+m[k+1][j];
            }
            m[i][j]=temp+sum_a(b,i,j);
            j++;
        }
    }

    temp=m[0][n-1];
    for(i=0;i<n;i++){
        if(temp<m[i][n+i-1])
            temp=m[i][n+i-1];
    }
    cout<<temp<<" ";
}

int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        m[i][i] = 0;
    }

    combin_stone1(a,n);
    combin_stone2(a,n);
    return 0;
}
