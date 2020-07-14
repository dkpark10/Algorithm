# 백준 1018번 체스판다시칠하기

## 문제
지민이는 자신의 저택에서 MN개의 단위 정사각형으로 나누어져 있는 M*N 크기의 보드를 찾았다.</br>
어떤 정사각형은 검은색으로 칠해져 있고, 나머지는 흰색으로 칠해져 있다. </br>
지민이는 이 보드를 잘라서 8*8 크기의 체스판으로 만들려고 한다.</br>
체스판은 검은색과 흰색이 번갈아서 칠해져 있어야 한다. 구체적으로, </br>
각 칸이 검은색과 흰색 중 하나로 색칠되어 있고, 변을 공유하는 두 개의 사각형은</br>
다른 색으로 칠해져 있어야 한다. 따라서 이 정의를 따르면 체스판을</br>
색칠하는 경우는 두 가지뿐이다. 하나는 맨 왼쪽 위 칸이 흰색인 경우, 하나는 검은색인 경우이다.</br>
보드가 체스판처럼 칠해져 있다는 보장이 없어서, 지민이는 8*8 크기의 체스판으로 </br>
잘라낸 후에 몇 개의 정사각형을 다시 칠해야겠다고 생각했다. </br>
당연히 8*8 크기는 아무데서나 골라도 된다.</br>
지민이가 다시 칠해야 하는 정사각형의 최소 개수를 구하는 프로그램을 작성하시오.

## 입력
> 10 13</br>
BBBBBBBBWBWBW</br>
BBBBBBBBBWBWB</br>
BBBBBBBBWBWBW</br>
BBBBBBBBBWBWB</br>
BBBBBBBBWBWBW</br>
BBBBBBBBBWBWB</br>
BBBBBBBBWBWBW</br>
BBBBBBBBBWBWB</br>
WWWWWWWWWWBWB</br>
WWWWWWWWWWBWB</br>

## 출력
> 12 

## 코드
```c++
#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAX 987654321
using namespace std;
int N, M, ans = MAX;
char board[51][51];
int CheckMate(int y, int x, char c)
{
    if (y + 8 > N || x + 8 > M) return MAX;
    int ret = 0;
    for(int i=y; i< y+8; i+=2){
        for(int j=x; j<x+8; j+=2){
            if(board[i][j] != c) ret++;
            if(board[i][j+1] == c) ret++;
        }
    }
    for(int i=y+1; i< y+8; i+=2){
        for(int j=x+1; j<x+8; j+=2){
            if(board[i][j] != c) ret++;
            if(board[i][j-1] == c) ret++;
        }
    }
    return ret;
}
int main(void)
{
    cin >> N >> M;
    for(int i=0; i< N; i++){
        for(int j=0; j<M; j++){
            cin >> board[i][j];
        }
    }
    for(int i=0; i< N; i++){
        for(int j=0; j<M; j++){
            ans = min(ans,CheckMate(i,j,'W'));
            ans = min(ans,CheckMate(i,j,'B'));
        }
    }
    printf("%d\n", ans);
    return 0;
}
```

## 풀이
걍 격자로 체크해주면서 하면 댐 풀이랄게 ㄷ없음.
