# 백준 6603번 로또 

## 문제
독일 로또는 {1, 2, ..., 49}에서 수 6개를 고른다.</br>

로또 번호를 선택하는데 사용되는 가장 유명한 전략은 49가지 수 중 k(k>6)개의 수를 </br>
골라 집합 S를 만든 다음 그 수만 가지고 번호를 선택하는 것이다.</br>
예를 들어, k=8, S={1,2,3,5,8,13,21,34}인 경우 이 집합 S에서 수를 고를 수 있는</br>
경우의 수는 총 28가지이다. </br>
([1,2,3,5,8,13], [1,2,3,5,8,21], [1,2,3,5,8,34], [1,2,3,5,13,21], ..., [3,5,8,13,21,34])</br>
집합 S와 k가 주어졌을 때, 수를 고르는 모든 방법을 구하는 프로그램을 작성하시오.</br>

## 입력
> 7 1 2 3 4 5 6 7</br>

## 출력
> 1 2 3 4 5 6</br>
1 2 3 4 5 7</br>
1 2 3 4 6 7</br>
1 2 3 5 6 7</br>
1 2 4 5 6 7</br>
1 3 4 5 6 7</br>
2 3 4 5 6 7</br>

## 코드
```c++
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int N, lotto[14], num[14];

void Search(int dep, int cur, int idx)
{
    if(dep == 6){
        for(int i =1; i<=6; i++){
            printf("%d ",num[i]);
        }
        printf("\n");
        return;
    }

    if (idx > N) return;
    num[cur] = lotto[idx];
    Search(dep + 1, cur + 1, idx + 1);
    Search(dep, cur, idx + 1);
}

int main(void)
{
    while(scanf("%d", &N) && N){

        for(int i=1; i<= N; i++){
            scanf("%d", &lotto[i]);
        }
        Search(0, 1, 1);
        printf("\n");
    }
    return 0;
}
```

## 풀이
함수의 인자를 잘보자 깊이, 현재, 인덱스를 넘긴다 </br>
재귀로 들어가면서 출력할 로또배열에 대입한다. </br>
깊이가 6일때 출력해주고 리턴 마지막 배열인덱스에 </br>
남은 로또번호를 대입해준다. 전위연산자 이진트리 생각하면 된다. </br>
