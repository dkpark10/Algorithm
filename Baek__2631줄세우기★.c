// 이 문제의 핵심은 가장 긴 최장수열을 찾는것이다.

#include <string>
#include <cstring> 
#include <queue>
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <random>
#include <cstdio>
#include <ctime>
#include <sstream>
#include <set>

#pragma warning(disable:4996)

#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) > (b) ? (b) : (a))

#define INF1 1e15
#define INF2 987654321
#define INF3 1e9
#define LL long long
#define ULL unsigned long long
#define VS vector<string>
#define VI vector<int>
#define VLL vector<LL>
#define VB vector<bool>
#define VC vector<char> 
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define DIVI 1000000000

using namespace std;

int N, child[210], dp[210], ans = 0;
int main(void) {

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &child[i]);
	}

	for (int i = 0; i < N; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (child[i] > child[j] && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
			}
		}
		ans = MAX(ans, dp[i]);
	}
	printf("%d\n", N - ans);
	return 0;
}
