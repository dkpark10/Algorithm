# 백준 1969번 DNA

## 문제
[https://www.acmicpc.net/problem/1969](https://www.acmicpc.net/problem/1969)
DNA란 어떤 유전물질을 구성하는 분자이다. 이 DNA는 서로 다른 4가지의 뉴클레오티드로 이루어져 있다
(Adenine, Thymine, Guanine, Cytosine). 우리는 어떤 DNA의 물질을 표현할 때, 이 DNA를 이루는
뉴클레오티드의 첫글자를 따서 표현한다. 만약에 Thymine-Adenine-Adenine-Cytosine-Thymine-Guanine-
Cytosine-Cytosine-Guanine-Adenine-Thymine로 이루어진 DNA가 있다고 하면, “TAACTGCCGAT”로 표현할 
수 있다. 그리고 Hamming Distance란 길이가 같은 두 DNA가 있을 때, 각 위치의 뉴클오티드 문자가 
다른 것의 개수이다. 만약에 “AGCAT"와 ”GGAAT"는 첫 번째 글자와 세 번째 글자가 다르므로 Hamming Distance는 2이다.
우리가 할 일은 다음과 같다. n개의 길이가 같은 DNA가 주어져 있을 때(이 DNA를 a1a2a3a4...이라고 하자)
Hamming Distance의 합이 가장 작은 DNA s를 구하는 것이다. 즉, s와 a1의 Hamming Distance + s와
a2의 Hamming Distance + s와 a3의 Hamming Distance ... 의 합이 최소가 된다는 의미이다.

## 코드
```c++
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int main(void)
{
	char str[1001][51];
	int N, M, cnt = 0;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("\n%c", &str[i][j]);
		}
	}
	int temp[26];
	for (int i = 0; i < M; i++) {
		memset(temp, 0, sizeof(temp));
		for (int j = 0; j < N; j++) {
			temp[str[j][i] - 65]++;
		}
		int max = 0, idx = 0, tempcnt = 0;
		for (int j = 0; j < 26; j++) {
			tempcnt += temp[j];
			if (max < temp[j]) {
				max = temp[j];
				idx = j;
			}
		}
		cnt += tempcnt - temp[idx];
		printf("%c", idx + 65);
	}
	printf("\n");
	printf("%d", cnt);

	return 0;
}
```

## 풀이 

세로방향으로 2차원 배열 돌면서 가장 많은 문자열 출력 그외 다른 문자열이 나타난 카운트를 증감해줘서 계산
