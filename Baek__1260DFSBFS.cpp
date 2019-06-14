// DFS와 BFS 구현
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
