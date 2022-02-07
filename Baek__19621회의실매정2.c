// 기본적인 완전탐색 백트래킹

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
#define LL long long
#define VS vector<string>
#define VI vector<int>
#define VLL vector<LL>
#define VB vector<bool>
#define VC vector<char> 
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define DIVI 1000000

using namespace std;
int N, ans = 0;
typedef struct Meet {
	int start, end, num;
}Meet;
Meet meeting[34];

bool cmp(Meet &m1, Meet &m2) {
	if (m1.end == m2.end) {
		return m1.start < m2.start;
	}
	return m1.end < m2.end;
}

void go(int cur, int sum){
	
	if (cur > N - 1){
		ans = MAX(ans, sum);
		return;
	}

	go(cur + 1, sum);
	go(cur + 2, sum + meeting[cur].num);
}

int main(void){

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int s, e, n;
		scanf("%d %d %d", &s, &e, &n);
		meeting[i].start = s;
		meeting[i].end = e;
		meeting[i].num = n;
	}

	sort(meeting, meeting + N, cmp);
	go(0, 0);
    printf("%d\n", ans);

	return 0;
}
