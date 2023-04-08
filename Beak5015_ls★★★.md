# 백준 5015번 ls

## 문제 

[https://www.acmicpc.net/problem/5015](https://www.acmicpc.net/problem/5015)

현진이는 집에서 취미로 운영 체제를 만들고 있다. 오늘은 디렉토리 안의 파일 리스트를 보여주는 "ls"를 구현해야 할 차례이다. 
현진이는 사용자들이 와일드카드(*)를 이용해서 패턴과 일치한 파일 이름을 보여주게 하려고 한다. 와일드 카드는 어떤 문자의 0개 또는 그 이상에 해당한다.

## 입력
첫째 줄에 패턴 P가 주어진다. P는 1글자~100글자이고, 알파벳 소문자와 '.', '*'로만 이루어져 있다. 둘째 줄에는 디렉토리의 파일 개수 N이 주어진다. 
(1 ≤ N ≤ 100) 다음 N개의 줄에는 디렉토리에 있는 파일의 이름이 한 줄에 하나씩 주어진다. 파일의 이름은 1글자~100글자이고, 알파벳 소문자와 '.'으로만 이루어져 있다.

## 출력
패턴 P와 일치하는 파일의 이름을 입력으로 주어진 순서를 따라서 한 줄에 하나씩 출력한다.

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
#include <regex>
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

string pattern, fn;
int dp[111][111];
int N, psize, fsize;

// *.*
// 4
// main.c
// a.out
// readme
// yacc

// *a*a*a
// 4
// aaa
// aaaaa
// aaaaax
// abababa
int check(int pdx, int fdx)
{
    int &ref = dp[pdx][fdx];
    if (ref != -1)
        return ref;

    if (pdx >= psize) 
        return ref = (fdx == fsize);
    if (pattern[pdx] == fn[fdx])
        return ref = check(pdx + 1, fdx + 1);
		// 에스트리크는 모든 패턴에 매칭 하는지 체크
    if (pattern[pdx] == '*')
        return ref = check(pdx + 1, fdx) || check(pdx, fdx + 1);
    return ref = 0;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> pattern >> N;
    psize = pattern.size();

    for (int i = 0; i < N; i++)
    {
        cin >> fn;
        memset(dp, -1, sizeof(dp));
        fsize = fn.size();
        if (check(0, 0))
            cout << fn << "\n";
    }

    return 0;
}
```

## 풀이
다이나믹 프로그래밍