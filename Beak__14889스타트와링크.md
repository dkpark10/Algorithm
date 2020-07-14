# 백준 14889번 스타트와 링크

## 문제

오늘은 스타트링크에 다니는 사람들이 모여서 축구를 해보려고 한다. 축구는 평일 오후에 하고</br>
의무 참석도 아니다. 축구를 하기 위해 모인 사람은 총 N명이고 신기하게도 N은 짝수이다. 이제 N/2명으로 </br>
이루어진 스타트 팀과 링크 팀으로 사람들을 나눠야 한다.</br>
BOJ를 운영하는 회사 답게 사람에게 번호를 1부터 N까지로 배정했고, 아래와 같은 능력치를 조사했다. </br>
능력치 Sij는 i번 사람과 j번 사람이 같은 팀에 속했을 때, 팀에 더해지는 능력치이다. </br>
팀의 능력치는 팀에 속한 모든 쌍의 능력치 Sij의 합이다. Sij는 Sji와 다를 수도 있으며, </br>
i번 사람과 j번 사람이 같은 팀에 속했을 때, 팀에 더해지는 능력치는 Sij와 Sji이다.</br>
N=4이고, S가 아래와 같은 경우를 살펴보자.</br>

> 1 2 3 4 </br>
1 0 1 2 3 </br>
2 4 0 5 6 </br>
3 7 1 0 2 </br>
4 3 4 5 0 </br>

예를 들어, 1, 2번이 스타트 팀, 3, 4번이 링크 팀에 속한 경우에 두 팀의 능력치는 아래와 같다.</br>
</br>
스타트 팀: S12 + S21 = 1 + 4 = 5</br>
링크 팀: S34 + S43 = 2 + 5 = 7</br>
1, 3번이 스타트 팀, 2, 4번이 링크 팀에 속하면, 두 팀의 능력치는 아래와 같다.</br>
</br>
스타트 팀: S13 + S31 = 2 + 7 = 9</br>
링크 팀: S24 + S42 = 6 + 4 = 10</br>
축구를 재미있게 하기 위해서 스타트 팀의 능력치와 링크 팀의 능력치의 차이를 최소로 하려고 한다.</br>
위의 예제와 같은 경우에는 1, 4번이 스타트 팀, 2, 3번 팀이 링크 팀에 속하면 스타트 팀의 능력치는 6,</br>
링크 팀의 능력치는 6이 되어서 차이가 0이 되고 이 값이 최소이다.</br>

## 입력
> 6</br>
0 1 2 3 4 5</br>
1 0 2 3 4 5</br>
1 2 0 3 4 5</br>
1 2 3 0 4 5</br>
1 2 3 4 0 5</br>
1 2 3 4 5 0</br>

## 출력
> 2

## 코드
```c++
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>
using namespace std;
int N, team[21][21], diff = 987654321;
bool check[21];
vector<int> start;
vector<int> link;

int Calcul()
{
    int s = 0, l = 0;
    for (int i = 0; i < (N / 2) - 1; i++){
        for (int j = i; j < (N / 2) - 1; j++){
            s += team[start[i]][start[j + 1]];
            s += team[start[j + 1]][start[i]];
            l += team[link[i]][link[j + 1]];
            l += team[link[j + 1]][link[i]];
        }
    }
    return abs(s - l);
}

void Teamsel(int cnt, int idx)
{
    if(cnt == N / 2){                                         // 팀선택을 다했으면      
        for(int i=1; i <= N; i++){        
            if(check[i]) start.push_back(i);                  // 각의 번호를 벡터에 넣어줌 
            else link.push_back(i);                           // 각의 번호를 벡터에 넣어줌
        }
        diff = min(diff, Calcul());
        start.clear();                                        // 위 포문이 첨부터 다 돌기 때문에 클리어해주자
        link.clear();
        return;
    }

    if(idx > N) return;                                       // 범위 벗어나면 리턴
    check[idx] = true;                    
    Teamsel(cnt + 1, idx + 1);
    check[idx] = false;
    Teamsel(cnt, idx + 1);            
}

int main(void)
{
    scanf("%d", &N);
    memset(check, false, sizeof(check));
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            scanf("%d",&team[i][j]);
        }
    }
    Teamsel(0, 1);
    printf("%d\n", diff);

    return 0;
}
```

## 풀이
팀을 선택하는데 있어 재귀를 호출하여 모든경우를 탐색한다. </br>
모두를 탐색하는 알고리즘은 '암호만들기', '로또', '수열의 합' 등 </br>
위 문제들의 알고리즘과 비슷하다. (완전히 같을 수 있다.)</br> 
팀선택을 다하면 계산해준다. 이 문제는 위 코드의 주석을 보자 </br> 

