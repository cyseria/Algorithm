#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int dotPos;
int pos;

//求最大公约数
long long GCD(long long a, long long b)
{
	return b == 0 ? a : GCD(b, a%b);
}

//字符c在str的位置
int getPos(char str[], char c)
{
	for (int i = 0; i < strlen(str) - 1; i++)
	{
		if (str[i] == c)
			return i;
	}
	return false;
}

//判断小数位是否为纯数字
int isDig(char str[])
{
	for (int i = dotPos + 1; i < strlen(str) - 1; i++){
		if (str[i] < '0' || str[i] > '9') {
			return false;
		}
	}
	return true;
}

long long pow10(long long n)
{
    long long sum = 1;
    for(int i = 0; i < n; i++ ) {
        sum *= 10;
    }
    return sum;
}
//小数转分数
int change(char str[]) {
	long long zi=0, mu, gcd; //分子，分母, 最大公约数
	long long intNum = 0; //整数部分
	long long norLen = 0, cycLen = 0;//非循环节长度，循环节长度,
	//非循环小数
	if (isDig(str)) {
		norLen = strlen(str) - dotPos - 1;
		for (int i = dotPos + 1; i < strlen(str); i++){
			zi = zi * 10 + str[i] - '0';
		}
		mu = pow10(norLen);
	}
	//带循环小数
	else {
        pos = getPos(str, '('); //括号位置
		long long a = 0, b = 0;
		if (pos) {
			for (int i = dotPos + 1; i < pos; i++) {
				a = a * 10 + str[i] - '0';
				norLen ++;
			}
			for (int i = pos + 1; i < strlen(str) - 1; i++) {
				b = b * 10 + ( str[i] - '0' );
				cycLen ++;
			}
			zi = a * (pow10(cycLen) - 1) + b ;
			mu = (pow10(cycLen) - 1)*pow10(norLen);
		}
	}

    //整数部分处理
    for (int i = 0; i < dotPos; i++) {
        intNum = intNum * 10 + (str[i] - '0');
    }
	if (intNum > 0) {
		zi += intNum * mu;
	}
	gcd = GCD(zi, mu);
	printf("%lld ", zi/gcd);
	printf("%lld",mu/gcd);
	return true;
}

int main()
{
	char num[128];
	scanf("%s", &num);
    dotPos = getPos(num,'.'); //小数点位置
	change(num);
	return 0;
}