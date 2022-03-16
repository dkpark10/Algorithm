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
#include <stack>
#include <sstream>
#include <set>

#pragma warning(disable:4996)
using namespace std;

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

VI ans(1);
int search(int val) {

	int left = 0;
	int right = ans.size() - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (ans[mid] < val) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return left;
}

int main(void) {

	int N;
	scanf("%d", &N);
	scanf("%d", &ans[0]);

	for (int i = 1; i < N; i++) {
		int val;
		scanf("%d", &val);

		if (ans.back() < val) {
			ans.push_back(val);
		}
		else {
			int idx = search(val);
			ans[idx] = val;
		}
	}
	printf("%d\n", ans.size());
	return 0;
}
