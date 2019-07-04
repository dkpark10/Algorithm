/*
집에서 시간을 보내던 오영식은 박성원의 부름을 받고 급히 달려왔다. 
박성원이 캠프 때 쓸 N개의 랜선을 만들어야 하는데 너무 바빠서 영식이에게 도움을 청했다.
이미 오영식은 자체적으로 K개의 랜선을 가지고 있다. 그러나 K개의 랜선은 길이가 제각각이다. 
박성원은 랜선을 모두 N개의 같은 길이의 랜선으로 만들고 싶었기 때문에 K개의 랜선을 잘라서 만들어야 한다. 
예를 들어 300cm 짜리 랜선에서 140cm 짜리 랜선을 두 개 잘라내면 20cm 은 버려야 한다.(이미 자른 랜선은 붙일 수 없다.)
편의를 위해 랜선을 자르거나 만들 때 손실되는 길이는 없다고 가정하며, 
기존의 K개의 랜선으로 N개의 랜선을 만들 수 없는 경우는 없다고 가정하자. 
그리고 자를 때는 항상 센티미터 단위로 정수길이만큼 자른다고 가정하자. 
이때 만들 수 있는 최대 랜선의 길이를 구하는 프로그램을 작성하시오.

입력
첫째 줄에는 오영식이 이미 가지고 있는 랜선의 개수 K, 그리고 필요한 랜선의 개수 N이 입력된다.
K는 1이상 10,000이하의 정수이고, N은 1이상 1,000,000이하의 정수이다. 그리고 항상 K ≦ N 이다.
그 후 K줄에 걸쳐 이미 가지고 있는 각 랜선의 길이가 센티미터 단위의 정수로 입력된다. 랜선의 길이는 2^31-1보다 작거나 같은 자연수이다.

출력
첫째 줄에 N개를 만들 수 있는 랜선의 최대 길이를 센티미터 단위의 정수로 출력한다.

이상한 술집이랑 완전 동일 문제
범위는 2^31 - 1 까지이니 일일이 증감연산자를 통해 하기는 비효율
이분탐색으로 자를 수 있는 최대선 까지 자른다.
int로 하면 틀림으로 나옴 왜인지는.... 몰라
long long으로 변환해서 
*/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <climits>
#define ll long long
using namespace std;

ll bottle[10001];
ll MAX = (1 << 31) - 1;
int N, K;

bool IsCutted(ll mid) {

	ll sum = 0;

	for (int i = 0; i < N; i++) {
		sum += bottle[i] / mid;
	}
	if (sum >= K) return true;
	else return false;
}

ll Lan()
{
	ll left = 0;
	ll right = MAX;

	while (left <= right) {
		ll mid = (left + right) / 2;
		if (IsCutted(mid))
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

	cout << Lan();

	return 0;
}
