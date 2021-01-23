// 서로 다른 N개의 자연수의 합이 S라고 한다. S를 알 때, 자연수 N의 최댓값은 얼마일까?


#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main(void)
{
	unsigned long S, idx = 1, sum = 0;
	scanf("%d", &S);

	while (1) {
		sum += idx;
		if (sum == S) {
			printf("%d\n", idx);
			break;
		}
		if (sum >= S) {
			printf("%d\n", idx - 1);
			break;
		}
		idx++;
	}
	return 0;
}
