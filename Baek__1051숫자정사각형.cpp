/*
N*M크기의 직사각형이 있다. 각 칸은 한 자리 숫자가 적혀 있다. </br>
이 직사각형에서 꼭짓점에 쓰여 있는 수가 모두 같은 가장 큰 정사각형을 </br>
찾는 프로그램을 작성하시오. 이때, 정사각형은 행 또는 열에 평행해야 한다.</br>
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int main(void)
{
    int rec[50][50], N, M, temp = 1, ans = 0;
    scanf("%d %d",&N,&M);
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            scanf("%1d", &rec[i][j]);
        }
    }

    for(int i=0; i< N; i++){
        for(int j=0; j<M; j++){
            int cur = rec[i][j];
            while((i+temp) < N && (j+temp) < M){
                if (rec[i][j + temp] == cur &&
                    rec[i + temp][j] == cur &&
                    rec[i + temp][j + temp] == cur){
                        ans = max(ans,temp);
                    }temp++;
            }temp = 1;
        }
    }
    printf("%d\n", (int)pow(ans + 1, 2));
    return 0;
}
