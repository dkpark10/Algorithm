/*
한 개의 회의실이 있는데 이를 사용하고자 하는 N개의 회의들에 대하여 회의실 사용표를 만들려고 한다. 
각 회의 I에 대해 시작시간과 끝나는 시간이 주어져 있고, 각 회의가 겹치지 않게 하면서 
회의실을 사용할 수 있는 최대수의 회의를 찾아라. 단, 회의는 한번 시작하면 중간에 중단될 수 없으며 
한 회의가 끝나는 것과 동시에 다음 회의가 시작될 수 있다.
회의의 시작시간과 끝나는 시간이 같을 수도 있다. 이 경우에는 시작하자마자 끝나는 것으로 생각하면 된다.
*/

#include<iostream>
#include<algorithm>
using namespace std;

typedef struct Meeting {
	int start, end;
}Meeting;

Meeting m[100000]; // 배열의 갯수가 적을경우 런타임에러가남 왜인지는 모름 ㅡㅡ 
bool cmp(const Meeting& m1, const Meeting& m2) {
	if (m1.end == m2.end)
		return m1.start < m2.start;
	else
		return m1.end < m2.end; 
}

int main(void) {
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	int num; 
	cin >> num;

	for (int i = 0; i < num; i++) {
		cin >> m[i].start >> m[i].end; 
	}

	sort(m, m + num, cmp); // 끝나는 순으로 정렬 

	int cur =0, result = 0;
	for (int i = 0; i < num; i++) {
		if (m[i].start >= cur) {
			cur = m[i].end;
			result++;
		}
	}
	cout << result;

	return 0;
}
