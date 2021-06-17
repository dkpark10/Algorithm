# 프로그래머스 리튼프렌스 사천성 LV3

## 문제

리틀 프렌즈 사천성은 프렌즈 사천성과 유사한 게임이다. 게임은 2차원 배열에서 진행되는데,</br>
여러 가지 무늬로 구성된 타일이 배치되어 있으며 같은 모양의 타일은 두 개씩 배치되어 있다. </br>
게임의 목적은 배치된 모든 타일을 제거하는 것으로, 같은 모양의 타일을 규칙에 따라 제거하면 된다. </br>
타일을 제거할 수 있는 경우는 다음과 같다.</br>
</br>
다음 조건을 만족하는 경로가 있을 때 두 타일을 제거할 수 있다.</br>
</br>

> 경로의 양 끝은 제거하려는 두 타일이다.</br>
  경로는 두 개 이하의 수평/수직 선분으로 구성되어 있고, 이들은 모두 연결되어 있다. (즉, 경로를 한 번 이하로 꺾을 수 있다) </br>
  참고: 프렌즈 사천성은 경로가 세 개 이하의 선분으로 구성되어야 한다는 점이 다르다. (즉, 경로를 두 번 이하로 꺾을 수 있다) </br>
  경로 상에는 다른 타일 또는 장애물이 없어야 한다. </br>

**입력 형식**
입력은 게임판의 크기를 나타내는 m과 n, 그리고 배치된 타일의 정보를 담은 문자열 배열 board로 주어진다. </br>
이 배열의 크기는 m이며, 각각의 원소는 n글자의 문자열로 구성되어 있다. 입력되는 값의 제한조건은 다음과 같다.</br>
</br>
> 1 <= m, n <= 100

board의 원소는 아래 나열된 문자로 구성된 문자열이다. 각 문자의 의미는 다음과 같다. </br>
.: 빈칸을 나타낸다. </br>
*:* 막힌 칸을 나타낸다. </br>
알파벳 대문자(A-Z): 타일을 나타낸다. 이 문제에서, 같은 글자로 이루어진 타일은 한 테스트 케이스에 항상 두 개씩만 존재한다. </br>
board에는 알파벳 대문자가 항상 존재한다. 즉, 타일이 없는 입력은 주어지지 않는다. </br>

**출력 형식**
해가 존재하는 경우 타일을 제거하는 순서대로 한 글자씩 이루어진 문자열을, 그렇지 않은 경우 IMPOSSIBLE을 리턴한다. </br>
해가 여러 가지인 경우, 알파벳 순으로 가장 먼저인 문자열을 리턴한다.</br>

**예제 입출력**

| m    | n    | board                            | answer       |
| ---- | ---- | -------------------------------- | ------------ |
| 3    | 3    | ["DBA", "C*A", "CDB"]            | "ABCD"       |
| 2    | 4    | ["NRYN", "ARYA"]                 | "RYAN"       |
| 4    | 4    | [".ZI.", "M.**", "MZU.", ".IU."] | "MUZI"       |
| 2    | 2    | ["AB", "BA"]                     | "IMPOSSIBLE" |


## 코드

```c++
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#define PII pair<int,int>
using namespace std;
bool isAlpha(char c)
{
	return c >= 65 && c <= 90;
}
bool isOut(int y, int x, int mr, int mc)
{
	return y < 0 || x < 0 || y >= mr || x >= mc;
}
bool isConnect1(vector<string>& board, PII& p1, PII& p2)
{
	bool xlr = p1.second > p2.second ? true : false;              // 좌우 중 어디로 갈지 
	if (xlr) {
		for (int i = p1.second - 1; i >= p2.second; i--) {          // 왼쪽으로 가로를 체크
			int y = p1.first;
			int x = i;
			if (y == p2.first && x == p2.second) 
				return true;
			if (board[y][x] != '.') return false;;
		}
	}
	else {
		for (int i = p1.second + 1; i <= p2.second; i++) {        // 오른쪽으로 가로를 체크
			int y = p1.first;
			int x = i;
			if (y == p2.first && x == p2.second) 
				return true;
			if (board[y][x] != '.') return false;;
		}
	}

	for (int i = p1.first + 1; i <= p2.first; i++) {            // 세로로 내려오면서 체크
		int y = i;
		int x = p2.second;
		if (y == p2.first && x == p2.second) 
			return true;
		if (board[y][x] != '.') return false;;
	}
	return false;
}

bool isConnect2(vector<string>& board, PII& p1, PII& p2)
{
	bool xlr = p1.second > p2.second ? true : false;
	for (int i = p1.first + 1; i <= p2.first; i++) {
		int y = i;
		int x = p1.second;
		if (y == p2.first && x == p2.second)
			return true;
		if (board[y][x] != '.') return false;;
	}

	if (xlr) {
		for (int i = p1.second - 1; i >= p2.second; i--) {
			int y = p2.first;
			int x = i;
			if (y == p2.first && x == p2.second)
				return true;
			if (board[y][x] != '.') return false;;
		}
	}
	else {
		for (int i = p1.second + 1; i <= p2.second; i++) {
			int y = p2.first;
			int x = i;
			if (y == p2.first && x == p2.second)
				return true;
			if (board[y][x] != '.') return false;;
		}
	}

	return false;
}

string solution(int m, int n, vector<string> board) {
	string ans;
	vector<vector<PII>>coord(26);
	int cnt = 0, len = coord.size();
	bool multi = false;

	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			char c = board[i][j];
			if (isAlpha(c)) {
				cnt++;
				coord[c - 65].push_back({ i,j });
			}
		}
	}
	cnt /= 2;

	for (int i = 0; i < len; i++) {                         // 타일 사이즈를 다 돌아야 한다. len - 1 까지 돌면 fail ...
		for (int j = 0; j < coord.size(); j++) {

			if (coord[j].size() == 0) continue;
			if (isConnect1(board, coord[j][0], coord[j][1]) ||
				isConnect2(board, coord[j][0], coord[j][1])) {

				int y1 = coord[j][0].first;
				int x1 = coord[j][0].second;
				int y2 = coord[j][1].first;
				int x2 = coord[j][1].second;

				board[y1][x1] = '.';
				board[y2][x2] = '.';

				coord[j].clear();
				ans += j + 65;
				break;                                            // 출력순서를 위해 연결성공시 루프 
			}
		}
	}
	if (ans.size() != cnt) return "IMPOSSIBLE";
	return ans;
}
```

## 풀이

한번만 꺾을 수 있다는 것은 두 점사이 사각형을 그릴 수 있다. </br>
연결 구현은 간단하다. </br>
</br>

**가로로 먼저 시작**

1. 시작점에서 좌우중 어디로 갈지 정한다. 시작점보다 도착점의 x좌표가 크다면 오른쪽 작다면 왼쪽 </br>
2. 가는 도중 장애물을 만나면 false를 반환 목표점에 도착하면 true를 반환
3. 가로로 움직였으니 세로로 움직인다. 도착점의 y좌표까지 반복문을 돌려준다. 반복문을 돌면서 2를 체크

**세로로 먼저 시작**

1. 세로로 움직인다. 도착점의 y좌표까지 반복문을 돌려준다.
2. 가는 도중 장애물을 만나면 false를 반환 목표점에 도착하면 true를 반환
3. 세로로 움직였으니 가로로 움직인다. 시작점보다 도착점의 x좌표가 크다면 오른쪽 작다면 왼쪽 루프돌면서 2를 체크</br>

그 다음 출력순서를 고려한다. 연결에 성공했다면 반복문을 빠져나와 다시 알파벳 순서대로 루프를 돌려준다.

