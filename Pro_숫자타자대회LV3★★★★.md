# 프로그래머스 레벨3 숫자 타자 대회

## 문제
[ https://school.programmers.co.kr/learn/courses/30/lessons/136797]( https://school.programmers.co.kr/learn/courses/30/lessons/136797)

## 코드

```c++
#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <map>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <random>
#include <cstdio>
#include <ctime>
#include <sstream>
#include <set>

#pragma warning(disable : 4996)

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) > (b) ? (b) : (a))

#define INF1 1e15
#define INF2 987654321
#define LL long long
#define VS vector<string>
#define VI vector<int>
#define VLL vector<LL>
#define VB vector<bool>
#define VC vector<char>
#define PII pair<int, int>
#define PLL pair<LL, LL>
#define DIVI 1000000

using namespace std;
int dp[100000][10][10];
const int weight[10][10] = {
    {1, 7, 6, 7, 5, 4, 5, 3, 2, 3},
    {7, 1, 2, 4, 2, 3, 5, 4, 5, 6},
    {6, 2, 1, 2, 3, 2, 3, 5, 4, 5},
    {7, 4, 2, 1, 5, 3, 2, 6, 5, 4},
    {5, 2, 3, 5, 1, 2, 4, 2, 3, 5},
    {4, 3, 2, 3, 2, 1, 2, 3, 2, 3},
    {5, 5, 3, 2, 4, 2, 1, 5, 3, 2},
    {3, 4, 5, 6, 2, 3, 5, 1, 2, 4},
    {2, 5, 4, 5, 3, 2, 3, 2, 1, 2},
    {3, 6, 5, 4, 5, 3, 2, 4, 2, 1},
};

string numbers2;
int touch(int idx, int left, int right) {
    if (idx >= numbers2.size()) {
        return 0;
    }

    int &ref = dp[idx][left][right];
    if (ref != -1) {
        return ref;
    }

    int number = numbers2[idx] - '0';
    int result = INF2;

    if (number != right){
        result = MIN(result, touch(idx + 1, number, right) + weight[left][number]);
    }

    if ( number != left ) {
        result = MIN(result, touch(idx + 1, left, number) + weight[right][number]);
    }

    return ref = result;
}

int solution(string numbers) {
    int answer = 0;
    memset(dp, -1, sizeof(dp));
    numbers2 = numbers;
    return touch(0, 4, 6);
}
```

## 풀이

기본적으로 dp 

★ 연산 줄이기 ★
파라미터로 길이가 큰 변수를 계속 넘길 경우

파라미터로 넘기지말고 전역변수에다 할당하여 계산한다.

동일 로직이라도 파라미터로 넘기면 시간이 좀 더 오래걸림
