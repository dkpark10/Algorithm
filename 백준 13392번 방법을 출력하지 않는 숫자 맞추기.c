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

int N, dp[100010][12];
string cur, target;

int turn(int idx, int left_acc) {

	int& ref = dp[idx][left_acc];
	if (ref != -1) {
		return ref;
	}
	if (idx >= N) {
		return 0;
	}

	int leftturn = (target[idx] - cur[idx] - left_acc + 20) % 10;
	int rightturn = 10 - leftturn;

	int leftresult = turn(idx + 1, (left_acc + leftturn) % 10) + leftturn;
	int rightresult = turn(idx + 1, left_acc) + rightturn;
	return ref = MIN(leftresult, rightresult);
}

int main(void) {

	cin >> N;
	cin >> cur >> target;

	memset(dp, -1, sizeof(dp));
	printf("%d\n", turn(0, 0));
	return 0;
}
