// 틀려서 수정중 하나만 수정하면 된다......

#include<iostream>
#include<algorithm>

using namespace std;

int BottleCapacity(const int *bottle, int size)
{
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += bottle[i];
	}

	return sum;
}

int StrangeBar(const int* bottle, int n, int k)  // 427 541 774 822 ->205
{
	int left = 0;
	int right = bottle[0];
	int capacity = BottleCapacity(bottle, n);
	int mid = (left + right) / 2;

	while (true) {
		
		if (mid*k <= capacity) {
			left = mid;
			mid = (left + right) / 2;
		}
		else if (mid*k > capacity) {
			mid = left;
			break;
		}
	}

	return mid;
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k, result;
	int bottle[10001];

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> bottle[i];
	}

	sort(bottle, bottle + n);
	result = StrangeBar(bottle, n, k);
	cout << result;

	return 0;
}
