# include <iostream>
# include <string>

using namespace std;
string str1, str2;

int f( int m, int n) {
    if ((m < 0) || (n < 0) || str1[m] != str2[n]) {
        return 0;
    } else {
        return f(m - 1, n - 1) + 1;
    }
}

int main() {
    int sum = 0, seat;
    cin >> str1;
    cin >> str2;
    for (int i = str1.length() - 1; i >= 0; i--)
        for (int j = str2.length() - 1; j >= 0; j--)
            if (f(i, j) >= sum) {
                sum = f(i, j);
                seat = i;
            }
    cout << sum << endl;
    cout << str1.substr(seat - sum + 1, sum) << endl;
}


