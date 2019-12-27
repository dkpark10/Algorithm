# 백준 1026번 보물

## 문제

옛날 옛적에 수학이 항상 큰 골칫거리였던 나라가 있었다.</br>
이 나라의 국왕 김지민은 다음과 같은 문제를 내고 큰 상금을 걸었다.</br>
길이가 N인 정수 배열 A와 B가 있다. 다음과 같이 함수 S를 정의하자.</br>
</br>
S = A[0]*B[0] + ... + A[N-1]*B[N-1]
</br>
S의 값을 가장 작게 만들기 위해 A의 수를 재배열하자. 단, B에 있는 수는 재배열하면 안 된다.</br>
S의 최솟값을 출력하는 프로그램을 작성하시오.</br>

## 입력
> 5</br>
1 1 1 6 0</br>
2 7 8 3 1</br>

## 출력
> 18

## 코드

```c++
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

bool cmp(int a, int b)
{
    return a > b;
}

int main(void)
{
    int N, a[50], b[50], sum = 0;
    scanf("%d", &N);
    for(int i = 0; i< N; i++) scanf("%d", &a[i]);
    for(int i = 0; i< N; i++) scanf("%d", &b[i]);

    sort(a, a + N);
    sort(b, b + N, cmp);

    for(int i=0; i< N; i++){
        sum += a[i] * b[i]; 
    }
    printf("%d\n", sum);
    
    return 0;
}
```

## 풀이
두 배열중 한배열은 오름차순 나머지 하나는 내림차순으로 </br>
재배열 해줘서 계산해주도록 하자

