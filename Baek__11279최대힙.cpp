/*
널리 잘 알려진 자료구조 중 최대 힙이라는 것이 있다. 
최대 힙을 이용하여 다음과 같은 연산을 지원하는 프로그램을 작성하시오.
배열에 자연수 x를 넣는다.
배열에서 가장 큰 값을 출력하고, 그 값을 배열에서 제거한다.
프로그램은 처음에 비어있는 배열에서 시작하게 된다.

딱히 설명할게 없다... 
힙은 완전 이진트리이다.
모든 부모노드는 자식 노드보다 우선순위가 높다.
우선순위 큐를 이용해 쉽게 구현
우선순위 큐는 큐랑 똑같은데 
나가는 순서가 다르다.
제일 우선순위가 높은것을 pop()
*/

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;

int main(void)
{
    priority_queue<int>pq;
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
