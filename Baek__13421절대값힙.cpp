/*
절댓값 힙은 다음과 같은 연산을 지원하는 자료구조이다.
배열에 정수 x (x ≠ 0)를 넣는다.
배열에서 절댓값이 가장 작은 값을 출력하고, 그 값을 배열에서 제거한다.
절댓값이 가장 작은 값이 여러개일 때는, 가장 작은 수를 출력하고, 
그 값을 배열에서 제거한다.
프로그램은 처음에 비어있는 배열에서 시작하게 된다.

절대값을 비교해 최소힙을 나타내는 문제
어찌 풀까 고민하다  
음수 양수 우선순위큐를 나누어서 품
양수큐는 내림차순으로
음수큐는 오름차순으로 
*/

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;

int main(void)
{
    priority_queue<int, vector<int>, greater<int> > posi;
    priority_queue<int> nega;

    int N, x;
    scanf("%d", &N);

    while(N--){
        
        scanf("%d",&x);
        if(x){
            if (x < 0) nega.push(x);                              // 음수면 nega 푸쉬
            else posi.push(x);                                    // 양수면 posi 푸쉬
        }
        else if(x == 0 && posi.empty() && nega.empty())           // 입력값이 0이고 둘다 비면 0출력
            printf("%d\n", 0);
        else{                         
            if(posi.empty()){                                     // posi가 다 비었다면 다 출력했다는 뜻 nega를 출력하고 
                printf("%d\n",nega.top());                        // nega를 pop()
                nega.pop();
            }
            else if(nega.empty()){                                // nega가 다 비었다면 다 출력했다는 뜻 posi를 출력하고
                printf("%d\n",posi.top());                        // posi를 pop()
                posi.pop();
            }
            else if(abs(nega.top()) <= posi.top()){               // 네거 탑과 포지 탑의 절대값 비교 네거의 절대값이 더 적다면
                printf("%d\n",nega.top());                        // 네거 출력하고 pop()
                nega.pop();
            }
            else{                                                 
                printf("%d\n",posi.top());                        // 포지의 절대값이 더 적다면
                posi.pop();                                       // 포지 출력하고 pop()
            }
        }
    }
    return 0;
}
