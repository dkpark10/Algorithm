# 백준 10216번 Count Circle Group

## 문제

백준이는 국방의 의무를 수행하기 위해 떠났다. 혹독한 훈련을 무사히 마치고 나서, 정말 잘 생겼고</br>
코딩도 잘하는 백준은 그 특기를 살려 적군의 진영을 수학적으로 분석하는 일을 맡게 되었다.</br>
</br>
2차원 평면 위의 N곳에 적군의 진영이 설치되어 있다. 각 적군의 진영들은 진영마다 하나의 통신탑을</br>
설치해, i번째 적군의 통신탑은 설치 위치로부터 Ri 이내 거리에 포함되는 모든 지역을 자신의 </br>
통신영역 Ai로 가지게 된다. 만약 임의의 통신영역 Ai와 Aj가 닿거나 겹치는 부분이 있다면</br>
진영 i와 진영 j는 직접적으로 통신이 가능하다. 물론 직접적으로 통신이 가능하지 않더라도,</br>
임의의 지역 i와 j가 중간에 몇 개의 직접통신을 거쳐서 최종적으로 통신이 가능하다면 i와 j는 상호간에 통신이 가능한 것으로 본다.</br>
적들은 영리해서, 상호간에 통신이 가능한 부대끼리는 결집력있는 한 그룹처럼 행동한다. 백준은</br>
이러한 그룹의 개수를 알아내 아군의 전략지침에 도움을 주고자 한다. 군대에 가서도 코딩하는 불쌍한 백준을 위해 적군의 통신망 분석을 도와주자!</br>

## 코드

```c++
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#pragma warning(disable:4996)
using namespace std;
vector<pair<pair<int, int>, int>> camp;
vector<vector<int>> graph;
bool visited[3010];
void DFS(int curver)
{
	visited[curver] = true;

	for (int& nextver : graph[curver]) {
		if (!visited[nextver]) 
			DFS(nextver);
	}
}
int main(void)
{
	int T, N;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		camp.clear();
		graph.clear();
		memset(visited, 0, sizeof(visited));

		for (int i = 0; i < N; i++) {
			int y, x, r;
			scanf("%d %d %d", &x, &y, &r);
			camp.push_back({ { x,y }, r });
		}

		graph.resize(N + 1);
		for (int i = 0; i < N; i++) {
			for (int j = 1; j < N; j++) {
				if (i == j) continue;
				int dst = camp[i].second + camp[j].second;

				int ydif = abs(camp[i].first.first - camp[j].first.first);
				int xdif = abs(camp[i].first.second - camp[j].first.second);

				if (dst >= sqrt(pow(ydif, 2) + pow(xdif, 2))) {          // 적진영 i와 j가 원을 그려 접점인지 계산
					graph[i].push_back(j);                                  // 접점이면 그래프를 연결
					graph[j].push_back(i);
				}
			}
		}

		int ans = 0;
		for (int i = 0; i < N; i++) {
			if (visited[i]) continue;
			DFS(i);                                                 // 그래프 돌면서 카운트
			ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}
```

