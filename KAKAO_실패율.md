# 카카오 코딩테스트 실패율

## 문제
슈퍼 게임 개발자 오렐리는 큰 고민에 빠졌다. 그녀가 만든 프랜즈 오천성이</br>
대성공을 거뒀지만, 요즘 신규 사용자의 수가 급감한 것이다. </br>
원인은 신규 사용자와 기존 사용자 사이에 스테이지 차이가 너무 큰 것이 문제였다.</br>
이 문제를 어떻게 할까 고민 한 그녀는 동적으로 게임 시간을 늘려서 난이도를 조절하기로 했다. </br>
역시 슈퍼 개발자라 대부분의 로직은 쉽게 구현했지만, 실패율을 구하는 부분에서</br>
위기에 빠지고 말았다. 오렐리를 위해 실패율을 구하는 코드를 완성하라.</br>
실패율은 다음과 같이 정의한다.</br>
</br>
> 스테이지에 도달했으나 아직 클리어하지 못한 플레이어의 수 / 스테이지에 도달한 플레이어 수
</br>
전체 스테이지의 개수 N, 게임을 이용하는 사용자가 현재 멈춰있는 스테이지의 </br>
번호가 담긴 배열 stages가 매개변수로 주어질 때, 실패율이 높은 스테이지부터 </br>
내림차순으로 스테이지의 번호가 담겨있는 배열을 return 하도록 solution 함수를 완성하라.</br>
</br>

**제한사항**</br>

1. 스테이지의 개수 N은 1 이상 500 이하의 자연수이다.
2. stages의 길이는 1 이상 200,000 이하이다.
3. stages에는 1 이상 N + 1 이하의 자연수가 담겨있다.
4. 각 자연수는 사용자가 현재 도전 중인 스테이지의 번호를 나타낸다.
5. 단, N + 1 은 마지막 스테이지(N 번째 스테이지) 까지 클리어 한 사용자를 나타낸다.
6. 만약 실패율이 같은 스테이지가 있다면 작은 번호의 스테이지가 먼저 오도록 하면 된다.
7. 스테이지에 도달한 유저가 없는 경우 해당 스테이지의 실패율은 0 으로 정의한다.

## 입출력

| N | stages | result |
|---|---|---|
| 5 | 2,1,2,6,2,4,3,3 | 3,4,2,1,5 |
| 4 | 4,4,4,4,4 | 4,1,2,3 |

## 코드

```c++
#include <string>
#include <vector>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <cstring>
using namespace std;

typedef struct Failure {
	int pos;
	double failure;
}Failure;

bool cmp(Failure &a, Failure &b)
{
	if (a.failure == b.failure) return a.pos < b.pos;
	else return a.failure > b.failure;
}

vector<int> solution(int N, vector<int> stages) {

	vector<int> answer;
	int list[501], size = stages.size();
	Failure ret[501];
	memset(list, 0, sizeof(list));

	for (int i = 0; i< size; i++) list[stages[i]]++;

	int idx = 1, stage = 1, temp = N;
	while (temp--) {

		double failure = (double)(list[idx] * 100) / (double)size;
		if (size == 0) {
			ret[idx].pos = stage;
			ret[idx].failure = 0;
			idx++;
			stage++;
			continue;
		}
		ret[idx].pos = stage;
		ret[idx].failure = failure;
		size -= list[idx];
		idx++;
		stage++;
	}

	sort(ret + 1, ret + N + 1, cmp);
	for (int i = 1; i <= N; i++) {
		answer.push_back(ret[i].pos);
	}

	return answer;
}
```

## 풀이
어찌 풀었떠라 ;; </br>
리스트 배열에 각 스테이지에 도달한 플레이어수를 넣어준다. 리스트배열에서 인덱스는 스테이지 !!!</br>
그 다음 스테이지 수 만큼 실패율을 구해주자 </br>
스테이지에 도달했지만 노 클리어 / 도달한 플레이어 수 실패율을 구해서 실패율 구조체에 넣어주었다.</br>
실패율 구조체는 pos는 스테이지 failure는 실패율 이다. </br>
이렇게 해서 반복문을 빠져 나오면 sort해주자 실패율이 같다면 스테이지가 적은 순서대로 소트해주는</br>
cmp함수를 만들어 넣어주면 된다. </br>
여기서 !!!!!!!!! 예외사례 하나가 있다 바로 아무도 스테이지에 도달하지 않았을 경우 즉 0으로 나눌경우</br>
이번 스테이지에서 0이 나왔으면 앞으로 나올 모든 스테이지도 도달한 플레이어가 없으므로 다 0이다.</br>
당연한거다 예를들어 4탄을 깬 사람이 아무도 없는데 5탄을 깬 사람은 있을리가 없지 않은가 </br>
그러므로 ret구조체에 스테이지와 실패율 0을 계속 넣어주자 ~~~~ 이거땜에 삽질함 ~~~~~~~ 

