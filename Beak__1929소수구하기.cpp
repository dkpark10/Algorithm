// M이상 N이하의 소수를 모두 출력하는 프로그램을 작성하시오.
// 일반적인 소수구하는 알고리즘으로 시간초과
// 에라토스테네스의 체를 사용 
// 소수를 찾았을 때 그 소수의 배를 모두 체크하여 작성

#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstdio>
#define MAX 1000000
using namespace std;

int main()
{
    bool check[MAX + 1];
    int N, M, temp;

    scanf("%d %d", &N, &M);
    fill(check, check + MAX + 1, true);
    check[1] = false;

    for (int i = 2; i <= MAX; i++){

        if(check[i])
            temp = i;

        for (int j = temp * 2; j <= MAX; j += temp){
            check[j] = false;
        }
    }

    for (int i = N; i <= M; i++){
        if(check[i])
            printf("%d\n",i);
    }
    return 0;
}
