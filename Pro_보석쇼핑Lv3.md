# 투포인터 알고리즘을 이용해서 ~

```c++
#include <string>
#include <queue>
#include <vector>
#include <map>
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) > (b) ? (b) : (a))

#define LL long long
#define VS vector<string>
#define VI vector<int>
#define VB vector<bool>
#define PII pair<int,int>
#define PLL pair<LL,LL>

using namespace std;

vector<int> solution(vector<string> gems) {

	vector<int> answer(2);
	map<string, int> gemnum;

	int cnt = 0, ans = 0;
	for (string& s : gems) {
		if (gemnum.find(s) == gemnum.end()) {
			gemnum.insert({ s, cnt++ });
		}
	}

	vector<int>visited(cnt);
	for (int i = 0; i < cnt; i++) {
		int gm = gemnum[gems[i]];
		if (visited[gm] == 0) {
			ans++;
		}
		visited[gm]++;
	}

	if (ans == cnt) {
		return vector<int>{ 1, cnt };
	}

	int begin = 0, end = cnt - 1, len = 100001;
	while (true) {

		if (ans < cnt) {

			end++;
			if (end >= gems.size()) {
				break;
			}
			int endgm = gemnum[gems[end]];

			if (visited[endgm] == 0) {
				ans++;
			}

			visited[endgm]++;
		}
		else if (ans >= cnt) {

			if (len > end - begin) {
				answer[0] = begin + 1;
				answer[1] = end + 1;
				len = end - begin;
			}

			int begingm = gemnum[gems[begin]];

			if (visited[begingm] != 0) {
				visited[begingm]--;
				if (visited[begingm] == 0) {
					ans--;
				}
			}

			begin++;
			if (begin > gems.size() - cnt) {
				break;
			}
		}
	}

	return answer;
}
```
