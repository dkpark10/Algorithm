# Temp
# 아직 풀지 못하였습니다.... 조만간 풀 예정입니다...

```c++
#include <iostream>
#include <cstdio>
#include <cstdio>
using namespace std;
int map[50][50];

bool Check_1(int n, int x, int y) 
{
    if(map[x + 1][y + 1]  == n&& 
        map[x + 1][y - 1] == n&&
        map[x + 1][y] == n){

        map[x][y] = 0;
        map[x + 1][y + 1] = 0;
        map[x + 1][y - 1] = 0;
        map[x + 1][y] = 0;
        return true;
        } 
    else return false;
}

bool Check_2(int n, int x, int y) 
{
    if(map[x + 1][y]  == n&& 
        map[x + 1][y + 1] == n&&
        map[x + 1][y + 2] == n){
            
        map[x][y] = 0;
        map[x + 1][y] = 0;
        map[x + 1][y + 1] = 0;
        map[x + 1][y + 2] = 0;
        return true;
        }
    else return false;
}

bool Check_3(int n, int x, int y)
{
    if(map[x + 1][y + 1]  == n&& 
        map[x + 1][y - 1] == n&&
        map[x + 1][y - 2] == n){

        map[x][y] = 0;
        map[x + 1][y + 1] = 0;
        map[x + 1][y - 1] = 0;
        map[x + 1][y - 2] = 0;
        return true;
        }
    else return false;
}

bool Check_4(int n, int x, int y)
{
    if (map[x + 1][y] == n &&
        map[x + 2][y] == n &&
        map[x + 2][y + 1] == n){

        map[x][y] = 0;
        map[x + 1][y] = 0;
        map[x + 2][y] = 0;
        map[x + 2][y + 1] = 0;
        return true;
        }
    else return false;
}

bool Check_5(int n, int x, int y)
{
    if (map[x + 1][y] == n &&
        map[x + 2][y] == n &&
        map[x + 2][y - 1] == n){

        map[x][y] = 0;
        map[x + 1][y] = 0;
        map[x + 2][y] = 0;
        map[x + 2][y - 1] = 0;
        return true;
        }
    else return false;
}

int main(void)
{
    int N, M, result = 0;
    scanf("%d %d", &N, &M);

    for(int i=0; i< N; i++){
        for(int j=0; j<M; j++){
            scanf("%d", &map[i][j]);
        }
    }

    for(int i=0; i< N; i++){
        for(int j=0; j<M; j++){
            
            if(map[i][j]){
                if(Check_1(map[i][j], i,j)||
                    Check_2(map[i][j], i,j)||
                    Check_3(map[i][j], i,j)||
                    Check_4(map[i][j], i,j)||
                    Check_5(map[i][j], i,j)){
                        result++;
                    }
            }
        }
    }
    printf("%d\n", result);

    return 0; 
}
```
