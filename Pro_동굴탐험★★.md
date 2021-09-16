풀이는 여기로....

[https://wakanda-developer.tistory.com/12?category=953490](https://wakanda-developer.tistory.com/12?category=953490)

```c++
#include <string>
#include <queue>
#include <vector>
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) > (b) ? (b) : (a))
 
#define LL long long
#define VS vector<string>
#define VI vector<int>
#define VB vector<bool>
#define PII pair<int,int>
#define PLL pair<LL,LL>
 
using namespace std;
 
vector<VI>graph;
vector<VI>tree;
VI parents;
 
void move(int cur, VI& prev, VB& visited, VI&nextv) {
 
	// 반드시 방문해야하는 노드가 있고 방문하지 않았다면 리턴
	int prevertex = prev[cur];
	if (prevertex != -1 && visited[prevertex] == false) {
		return;
	}
 
	// 방문처리
	visited[cur] = true;
 
	for (int& next : tree[cur]) {
		if(visited[next] == false)
			move(next, prev, visited, nextv);
	}
 
	int nextvertex = nextv[cur];
    // 다음에 방문해야할 노드가 없다면 그냥 리턴
	if (nextvertex == -1) 
		return;
 
	// 다음에 방문해야할 노드가 있고 그 다음 노드의 부모노드를 방문했다면
    // 트리 순회해준다.
	int pare = parents[nextvertex];
	if (visited[pare] == true) {
		move(nextvertex, prev, visited, nextv);
	}
}
 
void maketree(int parent, VB& visited) {
 
	visited[parent] = true;
 
	// 트리를 만들어주면서 부모노드를 담는다.
	for (int& next : graph[parent]) {
		if (visited[next] == false) {
			parents[next] = parent;
			tree[parent].push_back(next);
			maketree(next, visited);
		}
	}
}
 
bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
 
	graph.clear();
	tree.clear();
 
	graph.resize(n);
	tree.resize(n);
	VI prev(n, -1);
	VI next(n, -1);
	parents.resize(n);
 
	for (VI& item : path) {
		int v1 = item[0];
		int v2 = item[1];
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}
 
	for (VI& item : order) {
		int v1 = item[0];
		int v2 = item[1];
		prev[v2] = v1;	// 이전에 방문해야할 노드번호를 담는다.
		next[v1] = v2;	// 다음에 방문해야할 노드번호를 담는다.
	}
 
	VB visited(n, false);
	maketree(0, visited);
 
	fill(visited.begin(), visited.end(), false);
	move(0, prev, visited, next);
 
	for (bool vv : visited) {
		if (vv == false) 
			return false;
	}
	return true;
}
```
