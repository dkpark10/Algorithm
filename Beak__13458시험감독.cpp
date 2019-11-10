# 백준 13458번 문제 시험감독

## 문제
총 N개의 시험장이 있고, 각각의 시험장마다 응시자들이 있다. i번 시험장에 있는 응시자의 수는 Ai명이다.</br>
감독관은 총감독관과 부감독관으로 두 종류가 있다. 총감독관은 한 방에서 감시할 수 있는 응시자의 수가 B명이고,</br>
부감독관은 한 방에서 감시할 수 있는 응시자의 수가 C명이다.</br>
각각의 시험장에 총감독관은 오직 1명만 있어야 하고, 부감독관은 여러 명 있어도 된다.</br>
각 시험장마다 응시생들을 모두 감시해야 한다. 이때, 필요한 감독관 수의 최솟값을 구하는 프로그램을 작성하시오.</br>

## 입력
> 3</br>
3 4 5</br>
2 2</br>
</br>
5</br>
10 9 10 9 10</br>
7 20</br>

## 출력
> 7</br>
10</br>

## 코드
```c++
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAX 1000001
#define ll long long
using namespace std;

int main(void)
{
    ll N, B, C, cnt = 0;
    ll arr[MAX];

    scanf("%lld",&N);
    for(ll i=0; i< N; i++){
        scanf("%lld", &arr[i]);
    }
    
    scanf("%lld %lld", &B, &C);

    for(ll i=0; i< N; i++){
        arr[i] -= B;
        cnt++;

        if(arr[i] <= 0) continue;
        if(arr[i] <= C){
            cnt++;
            continue;
        }
        if(arr[i] % C != 0){
            cnt += arr[i] / C;
            cnt++;
        }
        else cnt += arr[i] / C;
    }

    printf("%lld\n",cnt); 

    return 0;
}
```
## 풀이
딱히 어려운 문제는 아니다. 메인 감독관이 감시할 수 있는 수만큼 차감해주고 </br>
남은인원을 보조감독관 수만큼 나눠주면 된다. </br>
다만 한가지 신경써야할 것은 값이 응지자수가 극단적으로 크고 </br>
감독관의 감시할 수 있는 수가 1일 때 그 감독관의 수는 매우 커지고 </br>
int형의 범위를 넘어선다 그러므로 long long으로 해주자 </br>
