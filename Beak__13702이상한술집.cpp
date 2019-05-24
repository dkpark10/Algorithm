/*
프로그래밍 대회 전날, 은상과 친구들은 이상한 술집에 모였다.
이 술집에서 막걸리를 시키면 주전자의 용량은 똑같았으나 안에 들어 있는 막걸리 용량은 랜덤이다.
즉 한 번 주문에 막걸리 용량이 802ml 이기도 1002ml가 나오기도 한다.
은상은 막걸리 N 주전자를 주문하고, 자신을 포함한 친구들 K명에게 막걸리를 똑같은 양으로 나눠주려고 한다.
그런데 은상과 친구들은 다른 주전자의 막걸리가 섞이는 것이 싫어서, 분배 후 주전자에 막걸리가
조금 남아 있다면 그냥 막걸리를 버리기로 한다.
(즉, 한 번 주문한 막걸리에 남은 것을 모아서 친구들에게 다시 주는 경우는 없다.
예를 들어 5명이 3 주전자를 주문하여 1002, 802, 705 ml의 막걸리가 각 주전자에 담겨져 나왔고,
이것을 401ml로 동등하게 나눴을 경우 각각 주전자에서 200ml, 0m, 304ml 만큼은 버린다.)
이럴 때 K명에게 최대한의 많은 양의 막걸리를 분배할 수 있는 용량 ml는 무엇인지 출력해주세요.
*/

// 거의 다 풀었지만 그 하나를 못풀어서 결국은 남의 코드를 참고해서 푼 문제
// 분하지만 많이 배웠다.

#include <iostream>
using namespace std;

int bottle[10001];
int MAX = 1 << 31 - 1;
int N, K;

bool IsDivided(int mid) {

	int sum = 0;

	for (int i = 0; i < N; i++) 
		sum += bottle[i] / mid; // 나눠줄 사람 수
	
	if (sum >= K) return true; // 용량이 부족함 더 크게 나눠줄 수 있음
	else return false; // 용량이 넘침 조금 줄여야 정해진 인원이 마실 수 있음
}

int StrangeBar()
{
	int left = 0;
	int right = MAX;

	while (left <= right) {
		int mid = (left + right) / 2;
		if (IsDivided(mid))
			left = mid + 1;
		else
			right = mid - 1;
	}
	return right;
}

int main(void)
{
	cin >> N >> K;

	for (int i = 0; i < N; i++)
		cin >> bottle[i];
	
	cout << StrangeBar();

	return 0;
}
