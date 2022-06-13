// 풀이
// 1. 시작점부터 다익스트라 거리 구해주기
// 2. 정점을 순회하면서 정점 인덱스를 시작점으로 다익스트라 거리 구하기
// 3. 시작점 + a까지 거리 + b까지 거리 찾아주기
#include <string>
#include <vector>
#include <cstdio>
#include <queue>
#include <algorithm>
#define VI vector<int>
#define PII pair<int,int>
#define INF 987654321
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

using namespace std;

vector<vector<PII>> graph;
void connect(vector<VI>& fares) {
	for (VI item : fares) {
		int v1 = item[0];
		int v2 = item[1];
		int cost = item[2];
		graph[v1].push_back({ cost, v2 });
		graph[v2].push_back({ cost, v1 });
	}
}

void dijk(int begin, vector<int>& dst) {
		
	fill(dst.begin(), dst.end(), INF);
	dst[begin] = 0;
	priority_queue<PII> pq;
	pq.push({ 0,begin });

	while (!pq.empty()) {
		int curver = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();

		if (dst[curver] < cost) {
			continue;
		}

		for (PII& item : graph[curver]) {
			int nextver = item.second; 
			int nextcost = cost + item.first;

			if (dst[nextver] > nextcost) {
				dst[nextver] = nextcost;
				pq.push({ -nextcost , nextver });
			}
		}
	}
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
	
	int answer = INF;
	int mindst = INF;
	graph.resize(n + 1);
	connect(fares);

	vector<int>dstfroms(n + 1);
	dijk(s, dstfroms);

	for (int i = 1; i <= n; i++) {
	
		vector<int> dst(n + 1);
		dijk(i, dst);

		if (dst[a] == INF || dst[b] == INF)
			continue;

		answer = MIN(answer, dst[a] + dst[b] + dstfroms[i]);
	}

	return answer;
}