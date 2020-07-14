/*
널리 잘 알려진 자료구조 중 최소 힙이라는 것이 있다. 
최소 힙을 이용하여 다음과 같은 연산을 지원하는 프로그램을 작성하시오.

배열에 자연수 x를 넣는다.
배열에서 가장 작은 값을 출력하고, 그 값을 배열에서 제거한다.
프로그램은 처음에 비어있는 배열에서 시작하게 된다.

딱히 설명할게 없당...
기본적으로 우선순위 큐는 최대힙이므로
2,3번째 인자에 컨테이너와, 비교함수를 넣어주면 된당 
최대힙을 풀면 건져주는 문제이당
문제 많이 푼거 티내기 좋당
*/

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;

int main(void)
{
    priority_queue<int, vector<int>, greater<int> > pq;
    int N, x;
    scanf("%d", &N);

    while(N--){

        scanf("%d", &x);
        if(x) pq.push(x);
        else if(x == 0 && pq.empty())
            printf("%d\n", 0);
        else{
            printf("%d\n", pq.top());
            pq.pop();
        }
    }
    return 0;
}
