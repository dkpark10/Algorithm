[https://www.acmicpc.net/problem/10217](https://www.acmicpc.net/problem/10217)

## 코드

```c++
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
#define INF3 1e8
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

typedef struct Node {
	int dist, cost, next;
}Node;

int u, v, c, d, n, m, k, t;
vector<vector<Node>> graph;
int dp[101][10001];

int dijk() {

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			dp[i][j] = INF2;
		}
	}
		
	priority_queue<pair<int, PII>>pq;
	pq.push({ 0,{0,1} });	// 거리, 비용, 정점
	dp[1][0] = 0;

	while (!pq.empty()) {

		int cur = pq.top().second.second;
		int curcost = pq.top().second.first;
		int curdst = -pq.top().first;
		pq.pop();

		if (dp[cur][curcost] < curdst) {
			continue;
		}

		for (Node& d : graph[cur]) {
			int next = d.next;
			int nextcost = curcost + d.cost;
			int nextdist = curdst + d.dist;

			if (nextcost > m) {
				continue;
			}

			if (dp[next][nextcost] > nextdist){
				dp[next][nextcost] = nextdist;
				pq.push({ -nextdist, { nextcost, next } });
			}
		}
	}

	int ans = INF2;
	for (int i = 0; i <= m; i++) {
		ans = MIN(ans, dp[n][i]);
	}

	return ans;
}

int main(void)
{
	scanf("%d", &t);
	while (t--) {

		graph.clear();
		scanf("%d %d %d", &n, &m, &k);
		graph.resize(n + 1);
		for (int i = 0; i < k; i++) {
			scanf("%d %d %d %d", &u, &v, &c, &d);
			graph[u].push_back({ d,c,v });
		}

		int ans = dijk();
		if (ans == INF2) {
			printf("Poor KCM\n");
		}
		else {
			printf("%d\n", ans);
		}
	}

	return 0;
}
```

## 풀이

다익스트라로 여러가지를 고려해야 하기 때문에 dp점화식은 </br>

dp[현재정점][현재 코스트] 로 세운다. </br>

처음에는 dp점화식을 일반 다익스트라 문제 풀 때 처럼 1차원으로 dp[현재정점]으로 세웠는데 </br>

이렇게 점화식을 세운다면 최소 가중치가 업데이트 될 때 현재 코스트가 항상 최적임을 보장할 수 없다. </br>

그래서 쓸 데 없이 최소 가중치로 업데이트 되고 가격이 맞아도 다음 정점으로 갈 수 없다
