// 짱 쉬운문제.. 
// 3개의 수 입력받아 그 수의 각 자리 갯수 출력

#include<iostream>
using namespace std;

void Func(int n) {
	
	int arr[10] = {}; 
	int r;

	while (n) {
		r = n % 10;
		arr[r]++;
		n /= 10;
	}

	for (int i = 0; i < 10; i++) {
		cout << arr[i]<< endl;
	}
}

int main(void) {
	
	int a,b,c;
	cin >> a >> b >> c;

	Func(a*b*c);

	return 0;
}
