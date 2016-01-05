#include <iostream>
#include <cmath>
#include <string.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int arr[n+1][n+1];
    int res[n+1][n+1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> arr[i][j];         
        }     
    }
      // 初始化res结果数组
    for (int i = 1; i <= n; i++) {         
        res[n][i] = arr[n][i];     
    }
    for (int i = n - 1; i >= 1; i--) {    
        for (int j = 1; j <= i; j++) { // 动规填表
            res[i][j] = max(res[i+1][j], res[i+1][j+1]) + arr[i][j];         
        }     
    }
    cout << res[1][1] << endl;//最大路径和值

    // 找出靠右路径
    int y = 1;     
    cout << arr[1][y] << " ";
    //顶部最大
    for (int i = 2; i <= n; i++) {
    // 从上往下找，只需要比较 y 和 y+1，相应输出 “最大值下标对应的” 原值
        if (res[i][y] <= res[i][y+1]) {
            cout << arr[i][y+1] << " ";
            y = y+1; //更新y
        } else {
            cout << arr[i][y] << " ";
        }     
    }
    cout << endl;     
    return 0;
}
