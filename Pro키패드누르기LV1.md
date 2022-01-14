[https://programmers.co.kr/learn/courses/30/lessons/67256](https://programmers.co.kr/learn/courses/30/lessons/67256)

## 코드

```c++
#include <string>
#include <vector>
#define PII pair<int,int>

using namespace std;
int pos[10][2] = { {3,1}, {0,0},{0,1},{0,2},{1,0},{1,1},{1,2},{2,0},{2,1},{2,2} };

// 더 가까운 곳을 찾는 함수
char calcul(PII& l, PII& r, int num, string& hand) {

  // 거리공식 (y2 - y1) + (x2 - x1)
	int ldst = abs(l.first - pos[num][0]) + abs(l.second - pos[num][1]);
	int rdst = abs(r.first - pos[num][0]) + abs(r.second - pos[num][1]);

	if (ldst < rdst) {
		return  'L';
	}
	else if (ldst > rdst) {
		return 'R';
	}
  // 같은거리라면 주로 사용하는 손 리턴
	else {
		return hand[0]- 32;
	}
}

string solution(vector<int> numbers, string hand) {

	string answer = "";
	PII lastl = { 3,0 };
	PII lastr = { 3,2 };

	for (int& ele : numbers) {
    // 왼쪽 누를 때
		if (ele == 1 || ele == 4 || ele == 7) {
			answer.push_back('L');
			lastl = { pos[ele][0],pos[ele][1] };
		}
    // 오른쪽 누를 때
		else if (ele == 3 || ele == 6 || ele == 9) {
			answer.push_back('R');
			lastr = { pos[ele][0],pos[ele][1] };
		}
    // 가운데 누를 때
		else {
			char closer = calcul(lastl, lastr, ele, hand);
			answer.push_back(closer);

			if (closer == 'L')
				lastl = { pos[ele][0],pos[ele][1] };
			else
				lastr = { pos[ele][0],pos[ele][1] };
		}
	}
	return answer;
}
```

## 풀이

간단한 구현문제
