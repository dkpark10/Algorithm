/*
우리 나라는 가족 혹은 친척들 사이의 관계를 촌수라는 단위로 표현하는 독특한 문화를 가지고 있다. 
이러한 촌수는 다음과 같은 방식으로 계산된다. 기본적으로 부모와 자식 사이를 1촌으로 정의하고 이로부터 사람들 간의 촌수를 계산한다. 
예를 들면 나와 아버지, 아버지와 할아버지는 각각 1촌으로 나와 할아버지는 2촌이 되고, 아버지 형제들과 할아버지는 1촌, 
나와 아버지 형제들과는 3촌이 된다.
여러 사람들에 대한 부모 자식들 간의 관계가 주어졌을 때, 주어진 두 사람의 촌수를 계산하는 프로그램을 작성하시오.

간단하게 한정점에서 정점까지 거리를 묻는 문제
가중치가 주어지지 않았을 때 최단경로를 구하는 문제이다.
BFS 자체가 그리 어렵진 않지만 응용하려니 어렵다....
*/

#include<iostream>
#include<algorithm>
#include<cstdio>
#include<queue>
#define MAX 101
using namespace std;
int N, M, X, Y;
int family[MAX][MAX];
int kinship[MAX]; // 촌수를 넣는 배열 

int Calc(int x)   // X가 입력될때 X와의 거리를 kinship배열에 넣어 리턴하는 함수
{
    kinship[x] = 0; // 방문은 0으로 
    queue<int>q;    // BFS를 구현하기 위한 큐
    q.push(x);
    
    while(!q.empty()){

        for (int i = 1; i <= N; i++){
            
            if (family[q.front()][i] == 1 && kinship[i] == -1){ // 각 정점끼리 연결되어있고 방문하지 않았더라면 
                
                kinship[i] = kinship[q.front()] + 1;            // 이문제의 핵심코드 i노드의 거리를 계산하는 수식
                q.push(i);                                      // i노드의 부모노드 즉 kinship[q.front]노드의 들어있는 값에
                if(i == Y) return kinship[i];                   // 1을 더한다 kinship[q.front]의 값은 시작노드 X의 값에서부터
            }                                                   // 쭈욱 촌수를 계산해 누적해온 값이 들어있다.
        }q.pop();
    }
    return -1;
}

int main(void)
{
    int a, b;
    scanf("%d",&N);
    scanf("%d %d", &X, &Y);
    scanf("%d",&M);

    for (int i = 0; i < M; i++){
        scanf("%d %d", &a, &b);
        family[a][b] = 1;
        family[b][a] = 1;
    }

    fill(kinship,kinship + MAX , -1); // 방문하지 않은 표시 전부 -1로 
    printf("%d",Calc(X));
  
    return 0;
}
