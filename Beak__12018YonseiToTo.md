# 백준 12018번 연세토토

## 문제

연세대학교 수강신청이 얼마 전부터 바뀌어, 마일리지 제도로 바뀌었다. 이 제도는 각각의 학생들에게 마일리지를 주어 듣고
싶은 과목에 마일리지를 과목당 1~36을 분배한다. 그리고 모두 분배가 끝이 나면 과목에 대해서 마일리지를 많이 투자한 순으로 그 과목의 수강인원만큼 신청되는 방식이다.
성준이는 연세대학교 재학 중인 학생이다. 성준이는 저번 수강신청에서 실패하여 휴학을 했기 때문에 이번 수강신청만은
필사적으로 성공하려고 한다. 그래서 성준이는 학교 홈페이지를 뚫어버렸다.
그 덕분에 다른 사람들이 신청한 마일리지를 볼 수 있게 되었다. 성준이는 주어진 마일리지로 최대한 많은 과목을 신청하고 싶어 한다.
(내가 마일리지를 넣고 이후에 과목을 신청하는 사람은 없다) 마일리지는 한 과목에 1에서 36까지 넣을 수 있다.

## 코드

```c++
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
bool cmp(int a, int b)
{
	return a > b;
}
int main(void)
{
	int N, M, ans = 0;
	vector<int> classes;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {

		vector<int>temp;
		int p, l;
		scanf("%d %d", &p, &l);
		for (int i = 0; i < p; i++) {
			int z;
			scanf("%d", &z);
			temp.push_back(z);
		}

		sort(temp.begin(), temp.end(), cmp);
		if (p < l)classes.push_back(1);
		else classes.push_back(temp[l - 1]);
	}

	sort(classes.begin(), classes.end());

	for (int i = 0; i < N; i++) {
		if (classes[i] <= M) {
			M -= classes[i];
			ans++;
		}
		else break;
	}

	printf("%d\n", ans);

	return 0;
}
```
## 풀이

수강인원보다 수강신청인원이 더 적을시 1 마일리지만 사용</br>
아닐시 L번째 학생(0부터 시작하므로 L-1)을 푸쉬해서 차감해서 넣어준다.</br>
