/*
대학생 새내기들의 90%는 자신이 반에서 평균은 넘는다고 생각한다. 당신은 그들에게 슬픈 진실을 알려줘야 한다.

입력:
5
5 50 50 70 80 100
7 100 95 90 80 70 60 50
3 70 90 80
3 70 90 81
9 100 99 98 97 96 95 94 93 91

출력:
40.000%
57.143%
33.333%
66.667%
55.556%
c언어 배울 때 했던 과제가 생각나는 문제군요 ^^
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int main(void)
{
    int T,N,people[1000];
    scanf("%d",&T);
    while(T--){
        double sum = 0.0;
        int cnt = 0;
        scanf("%d ",&N);
        for(int i=0; i<N; i++){
            scanf("%d", &people[i]);
            sum += people[i];
        }
        for(int i=0; i<N; i++){
            if(people[i] > (sum/N)) cnt++;
        }
        double temp = (double)cnt / (double)N;
        printf("%2.3lf%%\n", temp * 100);
    }
    return 0;
}
