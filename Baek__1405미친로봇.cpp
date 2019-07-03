/*
통제 할 수 없는 미친 로봇이 평면위에 있다. 그리고 이 로봇은 N번의 행동을 취할 것이다.
각 행동에서 로봇은 4개의 방향 중에 하나를 임의로 선택한다. 그리고 그 방향으로 한 칸 이동한다.
로봇이 같은 곳을 한 번보다 많이 이동하지 않을 때, 로봇의 이동 경로가 단순하다고 한다.
(로봇이 시작하는 위치가 처음 방문한 곳이다.) 로봇의 이동 경로가 단순할 확률을 구하는 프로그램을 작성하시오.
예를 들어, EENE와 ENW는 단순하지만, ENWS와 WWWWSNE는 단순하지 않다. (E는 동, W는 서, N은 북, S는 남)

입력
첫째 줄에 N, 동쪽으로 이동할 확률, 서쪽으로 이동할 확률, 남쪽으로 이동할 확률, 북쪽으로 이동할 확률이 주어진다. 
N은 14보다 작거나 같은 자연수이고,  모든 확률은 100보다 작거나 같은 자연수 또는 0이다. 그리고, 동서남북으로 이동할 확률을 모두 더하면 100이다.

DFS 문제
모두 방문하여 확률을 더해준다 어렵다 
완전이해 x 
*/

#include<cstdio>
#include<iostream>
#define db double
using namespace std;
db prob[4];
db EWSN1[4] = {0, 0, 1, -1}; //동서남북
db EWSN2[4] = {1, -1, 0, 0}; //동서남북
bool visited[29][29];

db Move(int x, int y, int act)
{
    if(act < 1)
        return 1.0;

    db result = 0.0;
    visited[x][y] = true;

    for(int i=0; i<4; i++){
        
        int nx = x + EWSN1[i];
        int ny = y + EWSN2[i];
        if(!visited[nx][ny])
            result += prob[i] * Move(nx, ny, act - 1); // 방문한곳에 확률을 모두 더해줌
    }
    visited[x][y]=false;                               // 중요한 코드 한번 방문한 곳은 또 방문할 수 있기 때문에 방문하지 않음을 표시해줘야댐!!!
    return result;
}

int main(void)
{
    int N;
    scanf("%d",&N);

    for(int i=0; i<4; i++){
        scanf("%d",&prob[i]);
        prob[i] *= 0.01;
    }

    printf("%0.10lf", Move(14, 14, N));

    return 0;
}
