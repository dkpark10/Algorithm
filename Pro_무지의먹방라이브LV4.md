```c++
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <queue>
#define PII pair<int,int>
#define ll long long
using namespace std;
int sol(vector<int>& ft, long long K)
{
	ll sum = 0;
	priority_queue<PII> pq;
	for (int i = 0; i < ft.size(); i++) {
		sum += ft[i];
		pq.push({ -ft[i], i + 1 });
	}
	if (sum <= K) return -1;

	int before = 0;
	while ((-pq.top().first - before) * ft.size() <= K) {
		K -= (-pq.top().first - before) * ft.size();
		before = -pq.top().first;
		pq.pop();
	}

	vector<PII> vp(1);
	while (!pq.empty()) {
		vp.push_back({ pq.top().second, -pq.top().second });
		pq.pop();
	}
	sort(vp.begin(), vp.end());
	return vp[K % ft.size()].first;
}
int main(void)
{
	vector<int>ft = { 1,1,1,4,1 };
	int K = 6;
	cout << sol(ft, K) << endl;

	return 0;
}
```
