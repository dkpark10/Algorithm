#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int N, S;
int arr[20];
int result = 0;

void Go(int* arr, int idx, int sum)
{
    sum += arr[idx];
    if(idx >= N) return;
    if(sum == S) result++;

    Go(arr, idx + 1, sum);                  // 모든경우를 탐색하는 코드
    Go(arr, idx + 1, sum - arr[idx]);       // 현재인덱스 빼고 다음 인덱스 계산하겠단 뜻
}

int main(void)
{
    scanf("%d %d", &N, &S);
    for(int i=0; i<N; i++){
        scanf("%d", &arr[i]);
    }

    Go(arr,0,0);
    printf("%d\n", result);

    return 0;
}
