[https://programmers.co.kr/learn/courses/30/lessons/86052](https://programmers.co.kr/learn/courses/30/lessons/86052)

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

// 동 남 서 북
// 시계방향으로 돌려줌
int diry[4] = { 0,1,0, -1 };
int dirx[4] = { 1,0,-1 ,0 };
bool visited[501][501][4];

int go(int y, int x, int dir, VS& grid) {

	int ret = 0;
	while (1) {

		if (visited[y][x][dir] == true)
			break;

		visited[y][x][dir] = true;
		ret++;

    // 시계방향으로 돌려주고 인덱스 초과시 0으로
		if (grid[y][x] == 'R') {
			dir++;
			if (dir > 3)
				dir = 0;
		}
    // 반시계방향으로 돌려주고 인덱스 0 미만시 3으로
		else if (grid[y][x] == 'L') {
			dir--;
			if (dir < 0)
				dir = 3;
		}

    // 범위를 벗어나는 좌표에 대해서 그리드 사이즈를 더하고 모듈연산자를 사용한다.
		y = (y + diry[dir] + grid.size()) % grid.size();
		x = (x + dirx[dir] + grid[0].size()) % grid[0].size();
	}
	return ret;
}

vector<int> solution(vector<string> grid) {

	vector<int> answer;

	int row = grid.size();
	int col = grid[0].size();
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			for (int k = 0; k < 4; k++) {
        // y,x, 빛의 네방향 좌표 반복문 돌리기
				if(visited[i][j][k] == false)
					answer.push_back(go(i, j, k, grid));
			}
		}
	}
	sort(answer.begin(), answer.end());
	return answer;
}
```

## 풀이

문제 자체가 이해가 어려운데 결국 모든 칸에서 동서남북 네방향 빚을 모두 쏴줘야 한다.

사이클 방문여부는 visited[y좌표][x좌표][빛의 네방향] 을 체크해야 한다.

