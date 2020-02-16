# 백준 2003번 문제 수들의합2

## 문제
N개의 수로 된 수열 A[1], A[2], …, A[N] 이 있다.</br>
이 수열의 i번째 수부터 j번째 수까지의 합 A[i]+A[i+1]+…+A[j-1]+A[j]가 </br>
M이 되는 경우의 수를 구하는 프로그램을 작성하시오.</br>

## 입력
> 4 2 </br>
1 1 1 1 </br>

## 출력
> 3 </br>

## 코드

```c++
#include<iostream>
#include<cstdio>
using namespace std;
int main(void)
{
    int N,M,arr[10001];
    scanf("%d %d", &N, &M);
    for(int i=1; i<= N; i++){
        scanf("%d",&arr[i]);
    }

    int ans = 0, begin = 1, end = 1, sum = arr[1];
    while(1){
        if(sum == M) ans++;
        if(sum >= M) sum -= arr[begin++];
        else if(end == N) break;
        else if(sum < M) sum += arr[++end];
    }
    printf("%d\n", ans);
    return 0;
}
```

## 풀이
전형적인 투포인트 알고리즘 문제 비긴과 엔드를 적절히 이용하여 </br>
값이 M인경우 카운트 업 해서 출력해주면 되는 비교적 쉽고도 어려운 문제 </br>
