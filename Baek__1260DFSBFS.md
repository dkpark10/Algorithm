# 백준 1260번 DFSBFS
## 문제
그래프를 DFS로 탐색한 결과와 BFS로 탐색한 결과를 출력하는 프로그램을 작성하시오. </br>
단, 방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문하고, </br>
더 이상 방문할 수 있는 점이 없는 경우 종료한다. 정점 번호는 1번부터 N번까지이다.
## 입력
>4 5 1 </br>
1 2</br>
1 3</br>
1 4</br>
2 4</br>
3 4</br>
## 출력
>1 2 4 3</br>
1 2 3 4
## 코드 
```c++
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<queue>
#define MAX 1001
using namespace std;

int N, M, V;
int Map[MAX][MAX];
int check[MAX];

void DFS(int v)
{
    printf("%d ", v);
    check[v] = 1;       // 방문표시

    for (int i = 1; i <= N; i++){
        if(Map[v][i] == 1 && check[i] == 0) // 간선이 연결되있고 방문하지 않은 곳이라면
            DFS(i);                         // 재귀탐색
    }
}

void BFS(int v)
{
    queue<int> q;
    printf("%d ", v);
    check[v] = 1;
    q.push(v); 

    while(!q.empty()){ 

        for(int i=1; i<=N; i++){
            if(Map[q.front()][i] == 1 && check[i] == 0){ // 간선이 연결되있고 방문하지 않은 곳이라면
                q.push(i);                               // 그 정점과 연결된 정점 push
                printf("%d ",i);
                check[i] = 1;
            }
        }q.pop();                                        // 다 돌았으면 pop 
    }
}

int main(void)
{
    int x,y;
    scanf("%d %d %d", &N, &M, &V);

    for(int i=0; i<M; i++){
        scanf("%d %d", &x, &y);
        Map[x][y] = 1;
        Map[y][x] = 1;
    }

    DFS(V); 
    fill(check, check + MAX, false);      // DFS돌린 후 방문한곳 초기화
    printf("\n");
    BFS(V);

    return 0;
}
```
## 풀이
풀이랄게 없다 걍 그래프의 기본임
