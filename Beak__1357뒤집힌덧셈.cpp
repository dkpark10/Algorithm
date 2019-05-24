#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

int Reverse(int n) {

	int result = 0.0;
	vector<int> v;

	while (n) {
		v.push_back(n % 10); // 1의자리 숫자를 벡터에 푸쉬
		n /= 10; 
	}

	for (int i = 0; i < v.size(); i++) {
		result += v[i] * (int)pow(10.0, v.size() - 1 - i); // 첫 인덱스부터 벡터사이즈 - 1 만큼 10의 제곱해주고 곱함
	}

	return result;
}

int main(void) {

	int x, y;
	cin >> x >> y;

	x = Reverse(x);
	y = Reverse(y);
	cout << Reverse(x + y);

	return 0;
}

