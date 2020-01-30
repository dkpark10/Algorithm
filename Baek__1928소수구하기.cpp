/*
N ~ M까지의 소수 구하기 
일반적으로 알고있는 소수구하기 알고리즘을 사용하면 시간초과가 뜬다. O(n ^ 2)
그러므로 연산횟수를 줄이기 위해 에라토스테네스의 체를 쓴다. 
1을 예외로 두고 2부터 소수 판별하여 2의 배수를 지워준다
그 다음은 3의 배수를 지워주고 이렇게 점차 지워나간다 
4는 2의 배수이므로 x
이렇게 하면 연산이 많이 줄어듬
*/

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
    fill(check, check + MAX + 1, true); // 1 ~ 1000000까지 모두 소수라 가정
    check[1] = false;                   // 1은 예외

    for (int i = 2; i <= MAX; i++){

        if(check[i])                    // i가 소수면 
            temp = i;                   // temp에 대입

        for (int j = temp * 2; j <= MAX; j += temp){ // temp 의배수를 일일이 찾아
            check[j] = false;                        // 소수가 아님을 false로 표시
        }
    }

    for (int i = N; i <= M; i++){
        if(check[i])                                 // 소수라면 즉 true라면
            printf("%d\n",i);
    }
    return 0;
}
