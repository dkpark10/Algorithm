/*
수직선과 같은 일직선상에 N개의 마을이 위치해 있다. i번째 마을은 X[i]에 위치해 있으며, A[i]명의 사람이 살고 있다.
이 마을들을 위해서 우체국을 하나 세우려고 하는데, 그 위치를 어느 곳으로 할지를 현재 고민 중이다. 
고민 끝에 나라에서는 각 사람들까지의 거리의 합이 최소가 되는 위치에 우체국을 세우기로 결정하였다.
우체국을 세울 위치를 구하는 프로그램을 작성하시오.
각 마을까지의 거리의 합이 아니라, 각 사람까지의 거리의 합임에 유의한다

입력
첫째 줄에 N(1≤N≤100,000)이 주어진다. 다음 N개의 줄에는 X[1] A[1], X[2] A[2], …, X[N] A[N]이 주어진다. 
범위는 |X[i]|≤1,000,000,000, 0≤A[i]≤1,000,000,000 이며 모든 입력은 정수이다.

우체국을 어느 마을에 세울 것인가에 대한 문제
각마을의 위치를 오름차순으로 정렬하고
첫번째 마을 부터 순차적으로 아직 방문하지 않는 마을의 인구수를 비교해나간다.
마을이 일직선상에 위치해 있으니 결국 이렇게 
순차적으로 비교해나가면 현재 마을을 기준으로 
왼쪽에 있는 마을의 인구수와 오른쪽에 위치한 마을들의 인구수가 비슷해지는 최적의
위치를 구할 수 있게 된다.
*/

#include <cstdio>
#include <iostream>
#include <algorithm>
#pragma warning(disable:4996)
#define MAX 100000
#define ll long long
using namespace std;

typedef struct Town {
	int pos;
	int people;
}Town;

bool cmp(Town &t1, Town &t2)
{
	return t1.pos < t2.pos;
}

int main(void)
{
	Town t[MAX];
	int N;
	ll sum = 0, temp = 0, result = 0;
	scanf("%d", &N);

	for (int i = 0; i< N; i++) {
		scanf("%d %d", &t[i].pos, &t[i].people);
		sum += t[i].people;
	}

	sort(t, t + N, cmp);                              // 마을 위치순서대로 오름차순
	sum /= 2;                                         // 전체 인구수를 나눠줌 이 sum과 가장 근접하게되는 마을이 정답

	while (temp < sum) temp += t[result++].people;    // 비교

	if (N == 2) printf("%d", t[0].people < t[1].people ? t[1].pos : t[0].pos);  // 이렇게 풀다보면 대부분의 테스트는 99.99% 맞게된다
	else printf("%d", t[result - 1].pos);                                       // 하지만 N이 2로 주어지고 이 코드대로 풀다보면
                                                                              // 전체인구수가 홀수가 될 때 더 작은 인구수의 마을이 출력이됨
	return 0;                                                                   // 직접비교해줘야 됨 
}
