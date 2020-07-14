// 주어진 수 N개 중에서 소수가 몇 개인지 찾아서 출력하는 프로그램을 작성하시오.

#include<iostream>
#include<cstdio>
using namespace std;

int main(void)
{

    int prime[101] = {};
    int N, j, i, cnt = 0;
    scanf("%d",&N);

    for (int i = 1; i <= N; i++)
        scanf("%d", &prime[i]);

    for (int i = 1; i <= N; i++){
        for (j = 2; j < prime[i]; j++){
            if (prime[i] % j == 0)
                break;
        }
        if(prime[i] == j)
            cnt++;
    }
    printf("%d",cnt);

    return 0;
}
