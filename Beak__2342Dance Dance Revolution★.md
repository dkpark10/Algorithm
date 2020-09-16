# 백준 2342번 Dance Dance Revolution

## 문제

승환이는 요즘 "Dance Dance Revolution"이라는 게임에 빠져 살고 있다. 하지만 그의 춤 솜씨를 보면 알 수 있듯이, 그는 DDR을 잘 하지 못한다. 그럼에도 불구하고 그는 살을 뺄 수 있다는 일념으로 DDR을 즐긴다.

DDR은 아래의 그림과 같은 모양의 발판이 있고, 주어진 스텝에 맞춰 나가는 게임이다. 발판은 하나의 중점을 기준으로 위, 아래, 왼쪽, 오른쪽으로 연결되어 있다. 편의상 중점을 0, 위를 1, 왼쪽을 2, 아래를 3, 오른쪽을 4라고 정하자.

![https://www.acmicpc.net/JudgeOnline/upload/201011/ddr.PNG](https://www.acmicpc.net/JudgeOnline/upload/201011/ddr.PNG)

처음에 게이머는 두 발을 중앙에 모으고 있다.(그림에서 0의 위치) 그리고 게임이 시작하면, 지시에 따라 왼쪽 또는 오른쪽 발을 움직인다. 하지만 그의 두 발이 동시에 움직이지는 않는다.

이 게임에는 이상한 규칙이 더 있다. 두 발이 같은 지점에 있는 것이 허락되지 않는 것이다. (물론 게임 시작시에는 예외이다) 만약, 한 발이 1의 위치에 있고, 다른 한 발이 3의 위치에 있을 때, 3을 연속으로 눌러야 한다면, 3의 위치에 있는 발로 반복해야 눌러야 한다는 것이다.

오랫동안 DDR을 해 온 백승환은 발이 움직이는 위치에 따라서 드는 힘이 다르다는 것을 알게 되었다. 만약, 중앙에 있던 발이 다른 지점으로 움직일 때, 2의 힘을 사용하게 된다. 그리고 다른 지점에서 인접한 지점으로 움직일 때는 3의 힘을 사용하게 된다. (예를 들면 왼쪽에서 위나 아래로 이동할 때의 이야기이다.) 그리고 반대편으로 움직일때는 4의 힘을 사용하게 된다. (위쪽에서 아래쪽으로, 또는 오른쪽에서 왼쪽으로). 만약 같은 지점을 한번 더 누른다면, 그때는 1의 힘을 사용하게 된다.

만약 1 → 2 → 2 → 4를 눌러야 한다고 가정해 보자. 당신의 두 발은 처음에 (point 0, point 0)에 위치하여 있을 것이다. 그리고 (0, 0) → (0, 1) → (2, 1) → (2, 1) → (2, 4)로 이동하면, 당신은 8의 힘을 사용하게 된다. 다른 방법으로 발을 움직이려고 해도, 당신은 8의 힘보다 더 적게 힘을 사용해서 1 → 2 → 2 → 4를 누를 수는 없을 것이다.

## 코드

```c++
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
vector<int>foot;
int dp[100010][5][5],n;
int Cal(int foot, int num)
{
	if (foot == 0) return 2;
	else if (foot == num) return 1;
	else if (abs(foot - num) == 2)return 4;
	else return 3;
}
int F(int idx, int left, int right)
{
	if (idx >= (int)foot.size()) return 0;
	
	int& ref = dp[idx][left][right];
	if (ref != -1) return ref; 

	int nxtf = foot[idx];					// 다음발
	int tmpl = F(idx + 1, nxtf, right) + Cal(left, nxtf);  // 왼발 밟으며 계산
	int tmpr = F(idx + 1, left, nxtf) + Cal(right, nxtf);  // 오른발 밟으며 계산
	return ref = min(tmpl, tmpr);

}
int main(void)
{
	while (scanf("%d", &n) && n)
		foot.push_back(n);
    
	memset(dp, -1, sizeof(dp));
	printf("%d\n", F(0,0,0));
	return 0;
}
```

## 풀이

어렵다.. 역싀 .. dp로 푸는건 알았고 어찌 짜야할지 머리가 새하얗다 경찰차 문제랑 비슷한데.
다른 사람 풀이를 한번 보고 단번에 깨달았다. 결국엔 디피는 **그리디**이며 **완전탐색**이다.
이건 기본이지.. 다들 알겠지.. 나의 생각에 차이가 문제해결에 결정적이었다. 결국엔 재귀적으로 탐색한다면 **Top-Bottom ** 방식인데 *(가장 맨 마지막  단계에서 부터 밟을 발부터 계산하며 차근차근 내려오면서 짜는방식)* 자꾸 Bottom-Top방식으로 생각을 하였다. Bottom-Top 방식은 내가알기론 재귀적으로 수행하는 코드를 한번도 본적이 없다. 