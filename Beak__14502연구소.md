# 백준 14502번 연구소 

## 문제
인체에 치명적인 바이러스를 연구하던 연구소에서 바이러스가 유출되었다. 다행히 바이러스는 아직 퍼지지 않았고,</br>
바이러스의 확산을 막기 위해서 연구소에 벽을 세우려고 한다.</br>

연구소는 크기가 N×M인 직사각형으로 나타낼 수 있으며, 직사각형은 1×1 크기의 정사각형으로 나누어져 있다.</br>
연구소는 빈 칸, 벽으로 이루어져 있으며, 벽은 칸 하나를 가득 차지한다. </br>
일부 칸은 바이러스가 존재하며, 이 바이러스는 상하좌우로 인접한 빈 칸으로 모두 퍼져나갈 수 있다.</br>
새로 세울 수 있는 벽의 개수는 3개이며, 꼭 3개를 세워야 한다.</br>
예를 들어, 아래와 같이 연구소가 생긴 경우를 살펴보자.</br>

> 2 0 0 0 1 1 0</br>
0 0 1 0 1 2 0</br>
0 1 1 0 1 0 0</br>
0 1 0 0 0 0 0</br>
0 0 0 0 0 1 1</br>
0 1 0 0 0 0 0</br>
0 1 0 0 0 0 0</br>

이때, 0은 빈 칸, 1은 벽, 2는 바이러스가 있는 곳이다. 아무런 벽을 세우지 않는다면,</br>
바이러스는 모든 빈 칸으로 퍼져나갈 수 있다.</br>
2행 1열, 1행 2열, 4행 6열에 벽을 세운다면 지도의 모양은 아래와 같아지게 된다.</br>

> 2 1 0 0 1 1 0</br>
1 0 1 0 1 2 0</br>
0 1 1 0 1 0 0</br>
0 1 0 0 0 1 0</br>
0 0 0 0 0 1 1</br>
0 1 0 0 0 0 0</br>
0 1 0 0 0 0 0</br>

바이러스가 퍼진 뒤의 모습은 아래와 같아진다.</br>

> 2 1 0 0 1 1 2</br>
1 0 1 0 1 2 2</br>
0 1 1 0 1 2 2</br>
0 1 0 0 0 1 2</br>
0 0 0 0 0 1 1</br>
0 1 0 0 0 0 0</br>
0 1 0 0 0 0 0</br>

벽을 3개 세운 뒤, 바이러스가 퍼질 수 없는 곳을 안전 영역이라고 한다. 위의 지도에서 안전 영역의 크기는 27이다.</br>
연구소의 지도가 주어졌을 때 얻을 수 있는 안전 영역 크기의 최댓값을 구하는 프로그램을 작성하시오.</br>

## 입력

> 7 7 </br>
2 0 0 0 1 1 0</br>
0 0 1 0 1 2 0</br>
0 1 1 0 1 0 0</br>
0 1 0 0 0 0 0</br>
0 0 0 0 0 1 1</br>
0 1 0 0 0 0 0</br>
0 1 0 0 0 0 0</br>

## 출력
> 27

## 코드
```c++
#include <iostream>
#include <cstdio>
#include <algorithm>    
#include <cstring>
#include <vector>
#define PII pair<int,int>
 using namespace std;
vector<PII>virus;
int N,M,cnt = 0;
int map[9][9], temp1[9][9], temp2[9][9];
int diry[4] = {0, 0, 1, -1};
int dirx[4] = {1, -1, 0, 0};

int Findcnt()
{
    int ret = 0;
    for(int i=0; i< N; i++){
        for(int j=0; j<M;j++){
            if(temp2[i][j] == 0) ret++;
        }
    }
    return ret;
}

void Copymap(int (*arr1)[9], int (*arr2)[9])
{
    for(int i=0; i< N; i++){
        for(int j=0; j< M; j++){
            arr1[i][j] = arr2[i][j];
        }
    }
}

void Spread(int y, int x)
{
    temp2[y][x] = 2;
    for(int i=0; i<4; i++){
        int ny = y + diry[i];
        int nx = x + dirx[i];
        
        if(ny < 0 || nx < 0 || ny >= N || nx >= M)
            continue;
        if(temp2[ny][nx] == 0)
            Spread(ny,nx);
    }
}

void Create_Wall(int wcnt)
{
    if(wcnt == 3){
        Copymap(temp2, temp1);
        for(auto value: virus){
            Spread(value.first, value.second);
        }
        cnt = max(cnt, Findcnt());
        return;
    }

    for (int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if (temp1[i][j] == 0){
                temp1[i][j] = 1;    
                Create_Wall(wcnt + 1);
                temp1[i][j] = 0;
            }
        }
    }
}

int main(void)
{
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            scanf("%d", &map[i][j]);
            temp1[i][j] = map[i][j];
            if(map[i][j] == 2) 
                virus.push_back({i,j});
        }
    }

    Create_Wall(0);
    printf("%d\n",cnt);
    return 0;
}
```

## 풀이
풀이는 생각보다 간단하다. 모든 벽을 세울 수 있는 경우를 다 따져야 한다. </br>
Create_Wall함수로 벽을 세우고 벽이 3개가 세워졌을 경우 바이러스를 퍼트린다. </br>
바이러스 퍼트리는 알고리즘은 DFS로 작성했다. </br>
맵을 기억해야 하기 때문에 초기 배열, 벽이 세워진 배열, 벽이 세워진배열에 바이러스를 </br>
퍼트린 배열 이렇게 3개의 배열을 복사하고 사용하였다. </br>
바이러스를 퍼트리는 함수는 처음 작성하였을 때 인자를 3개줬다. </br>
(y,x,wcnt) 이렇게 3개를 썼었는데 시간초과가 어마어마하게 뜬다. </br>
wcnt하나만 인자로 넣어도 된다. </br>
