/*
등산가 김강산은 가족들과 함께 캠핑을 떠났다. 하지만, 캠핑장에는 다음과 같은 경고문이 쓰여 있었다.
캠핑장은 연속하는 20일 중 10일동안만 사용할 수 있습니다.
강산이는 이제 막 28일 휴가를 시작했다. 이번 휴가 기간 동안 강산이는 캠핑장을 며칠동안 사용할 수 있을까?
강산이는 조금 더 일반화해서 문제를 풀려고 한다. 
캠핑장을 연속하는 P일 중, L일동안만 사용할 수 있다. 강산이는 이제 막 V일짜리 휴가를 시작했다. 강산이가 캠핑장을 최대 며칠동안 사용할 수 있을까?

문제 자체는 어렵지 않은데 예외사례가 많아 머리 아픈 문제
*/

#include<iostream>
#include<cstdio>
#include<algorithm> 
#include<vector>
using namespace std;

int main(void)
{   
    int L,P,V;
    int temp = 0, i = 1;

    while(1){
        int day = 0;
        scanf("%d %d %d", &L, &P, &V);
        if(L == 0 && P ==0 && P ==0)
            break;

        if(V < P) V < L ? day = V : day = L;    // 휴가 일수가 P일보다 작고 L 보다 작으면 전체휴가 일수를 캠핑 L보다 작으면 연속 여는 캠핑일수
        else{
            temp = V / P;                       
            day += temp * L;                    // 캠핑 여는 날 
            V -= temp * P;                      // 휴가 뻄
            day += V > L ? L : V;               // 남은휴가가 L보다 크면 L을 더함 작으면 남은 휴가 전부 캠핑 ㄱㄱ
        }                                       // 너무 예외사례가 많아서 너무 빢치는 문제 
        printf("Case %d: %d\n", i++, day);
    }
    return 0;
}
