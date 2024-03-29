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
