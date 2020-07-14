/*
준규가 가지고 있는 동전은 총 N종류이고, 각각의 동전을 매우 많이 가지고 있다.
동전을 적절히 사용해서 그 가치의 합을 K로 만들려고 한다. 이때 필요한 동전 개수의 최솟값을 구하는 프로그램을 작성하시오.

가장 최소화 할 수 있는 방법은 가장 큰 금액으로 나누는 것
가장 큰 값부터 자료구조 디큐에 넣어주고 
구하고자 하는 값과 비교 K보다 크다면 pop()해주어 나눌 수 있을 때 까지
*/

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<deque>
using namespace std;
deque<int> coins;
int result = 0;

void Min(int k)
{
    int cnt = 0;
    if(k == 0)                      // 값이 0이 된다면 리턴 
        return;

    while(k < coins.front()){       // 가장 큰 동전으로 나눌 수 없으면
        coins.pop_front();          // 나눌 수 있을 때 까지 빼자 
    }
    cnt = k / coins.front();        // 나눈 수 
    result += cnt;                  // result에 누적합
    k -= coins.front() * cnt;       // 가장 큰 금액으로 나눈 값을 전체에서 빼줌
    coins.pop_front();              // 이제 나눴던 큰 금액으로 나눌 수 없으니 팝 해줌
    Min(k);                         // 나머지 값을 다시 재귀호출로 ~
}

int main(void)
{
    int N, K, coin;
    scanf("%d %d", &N, &K);

    for(int i=0; i<N; i++){
        scanf("%d",&coin);
        coins.push_front(coin);
    }

    Min(K);
    printf("%d", result);

    return 0;
}
