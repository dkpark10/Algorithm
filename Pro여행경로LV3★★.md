// 생각보다 빡쎈문제

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
using namespace std;

#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) > (b) ? (b) : (a))

#define INF1 1e15
#define INF2 987654321
#define INF3 1e9
#define LL long long
#define ULL unsigned long long
#define VS vector<string>
#define VI vector<int>
#define VLL vector<LL>
#define VB vector<bool>
#define VC vector<char> 
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define DIVI 1000000000

VS ans;
bool useticket[10010];
bool dfs(string cur, vector<VS>& tickets) {

  // 모든 티켓을 다 사용했다면 
	if (ans.size() == tickets.size() + 1) {
		return true;
	}

	for (int i = 0; i < (int)tickets.size(); i++) {
		string from = tickets[i][0];
		string to = tickets[i][1];

		// 현재 티켓을 사용했거나 현재 출발점이 아니면
		if (useticket[i] == true || cur.compare(from) != 0) {
			continue;
		}
		ans.push_back(to);
		useticket[i] = true;
		bool cango = dfs(to, tickets);
		if (cango) return true;

		// 갈 수 없는곳 끊긴 곳이라면 현재 티켓 사용 금지
		useticket[i] = false;
	}
	ans.pop_back();

	return false;
}

VS solution(vector<VS> tickets) {
  
  // 오름차순 정렬
	sort(tickets.begin(), tickets.end(),
		[](VS& t1, VS& t2)->bool {
			if (t1[1].compare(t2[1]) == 0) {
				return t1[0] < t2[0];
			}
			return t1[1] < t2[1];
		});

	ans.push_back("ICN");
	dfs("ICN", tickets);

	return ans;
}
