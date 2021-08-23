# 백준 11437번 LCA 

## 코드

```c++
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#define LEN 50001
using namespace std;
int N, M, depth[LEN], parents[LEN];
bool visited[LEN];
vector<vector<int>> tree;

void init(int curv, int parent)
{
	visited[curv] = true;
	depth[curv] = depth[parent] + 1;
	parents[curv] = parent;

	for (int& nextv : tree[curv]) {
		if (visited[nextv])
			continue;

		init(nextv, curv);
	}
}

int lca(int u, int v)
{
	// 계산하기 쉽게 v를 더 깊게
	if (depth[u] > depth[v]) {
		swap(u, v);
	}

	// 같은 깊이가 될 때 까지
	while (depth[u] != depth[v]) {
		v = parents[v];
	}

	// 이제 공통 조상 찾자
	while (u != v) {
		u = parents[u];
		v = parents[v];
	}

	return u;
}

int main(void)
{
	int u, v;
	scanf("%d", &N);
	tree.resize(N + 1);
	memset(depth, -1, sizeof(depth));

	for (int i = 0; i < N - 1; i++) {
		scanf("%d %d", &u, &v);
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	init(1, 0);
	
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &u, &v);
		printf("%d\n", lca(u, v));
	}

	return 0;
}
```
