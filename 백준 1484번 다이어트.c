// 굳이 투포인터로 안풀어도 될 듯

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

using namespace std;

int main(void) {

	int g, left = 1, right = 2;
	scanf("%d", &g);
	VI ans;
	
	while (true){
		
		int curweight = right * right;
		int memoryweight = left * left;
		
		if (curweight - memoryweight == g) {
			ans.push_back(right);
		}

		if (curweight - memoryweight > g && right - left == 1) {
			break;
		}
		curweight - memoryweight > g ? left++ : right++;
	}

	if (ans.size() == 0) {
		printf("%d\n", -1);
	}
	else {
		for (int data : ans) {
			printf("%d\n", data);
		}
    }
	return 0;
}
