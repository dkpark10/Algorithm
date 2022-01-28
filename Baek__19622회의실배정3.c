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
int N;
typedef struct Meet {
	int start, end, num;
}Meet;
Meet meeting[100034];
 
bool cmp(Meet &m1, Meet &m2) {
	if (m1.end == m2.end) {
		return m1.start < m2.start;
	}
	return m1.end < m2.end;
}
 
int main(void){
 
	scanf("%d", &N);
	int dp[100010];
	for (int i = 0; i < N; i++) {
		int s, e, n;
		scanf("%d %d %d", &s, &e, &n);
		meeting[i].start = s;
		meeting[i].end = e;
		meeting[i].num = n;
	}
 
	sort(meeting, meeting + N, cmp);
	dp[0] = meeting[0].num;
	dp[1] = MAX(dp[0], meeting[1].num);
	for (int i = 2; i < N; i++) {
		dp[i] = MAX(dp[i - 2] + meeting[i].num, dp[i - 1]);
	}
	
	printf("%d\n", dp[N - 1]);
 
	return 0;
}
