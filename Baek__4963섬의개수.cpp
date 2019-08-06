# 백준 4963번 섬의 개수
## 문제

![island](https://user-images.githubusercontent.com/43857226/62511260-bb8bba80-b84d-11e9-8e72-b56dede04136.png)

정사각형으로 이루어져 있는 섬과 바다 지도가 주어진다. 섬의 개수를 세는 프로그램을 작성하시오. </br>
한 정사각형과 가로, 세로 또는 대각선으로 연결되어 있는 사각형은 걸어갈 수 있는 사각형이다. </br>
두 정사각형이 같은 섬에 있으려면, 한 정사각형에서 다른 정사각형으로 걸어서 갈 수 있는 경로가 있어야 한다. </br>
지도는 바다로 둘러쌓여 있으며, 지도 밖으로 나갈 수 없다. </br>

## 입력
> 3 2 </br> 
0 0 1</br>
0 1 0</br>
1 0 0</br
1 0 1 0 1 </br>
1 0 1 0 1 </br>
1 0 1 0 1 </br>
1 0 1 0 1 </br>
1 0 1 0 1 </br>
0 0</br>

## 출력 
> 1 </br>
3 </br>

## 코드
```c++
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int dirx[8] = {0, 0, 1, -1, -1, -1, 1, 1};
int diry[8] = {1, -1, 0, 0, -1, 1, -1, 1};
int map[50][50];
int W, H;

void Go(int x, int y)
{
    if(x >= H || y >= W || x < 0 || y < 0) return;
    map[x][y] = 0;

    for(int i=0; i< 8; i++){
        int nx = x + dirx[i];
        int ny = y + diry[i];

        if(map[nx][ny]){
            Go(nx, ny);
        }
    }
}

int main(void)
{
    while(scanf("%d %d",&W, &H) && W && H){
        
        int cnt = 0;
        for(int i=0; i< H; i++){
            for(int j =0; j< W; j++){
                scanf("%d", &map[i][j]);
            }
        }

        for(int i=0; i<H; i++){
            for(int j=0; j<W; j++){
                if(map[i][j]){
                    Go(i,j);
                    cnt++;
                }
            }
        }
        printf("%d\n", cnt);
        memset(map, 0, sizeof(map));

        for(int i=0; i< H; i++){
            for(int j=0; j< W; j++){
                printf("%d ",map[i][j]);
            }printf("\n");
        }
    }
    return 0;
}
```
## 풀이
풀이랄게 없다 걍 대각선만 추가된것뿐... 쉬운문제 그만풀자 이제 제발
