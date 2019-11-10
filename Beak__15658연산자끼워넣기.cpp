# 백준 15658번 문제 연산자 끼워넣기

## 문제
N개의 수로 이루어진 수열 A1, A2, ..., AN이 주어진다. 또, 수와 수 사이에 끼워넣을 수 있는 N-1개의 연산자가 주어진다.</br>
연산자는 덧셈(+), 뺄셈(-), 곱셈(×), 나눗셈(÷)으로만 이루어져 있다.</br>
우리는 수와 수 사이에 연산자를 하나씩 넣어서, 수식을 하나 만들 수 있다. 이때, 주어진 수의 순서를 바꾸면 안 된다.</br>
예를 들어, 6개의 수로 이루어진 수열이 1, 2, 3, 4, 5, 6이고, 주어진 연산자가 </br>
덧셈(+) 2개, 뺄셈(-) 1개, 곱셈(×) 1개, 나눗셈(÷) 1개인 경우에는 총 60가지의 식을 만들 수 있다.</br>
예를 들어, 아래와 같은 식을 만들 수 있다.</br>
</br>
1+2+3-4×5÷6</br>
1÷2+3+4-5×6</br>
1+2÷3×4-5+6</br>
1÷2×3-4+5+6</br>
식의 계산은 연산자 우선 순위를 무시하고 앞에서부터 진행해야 한다. 또, 나눗셈은 정수 나눗셈으로 몫만 취한다. </br>
음수를 양수로 나눌 때는 C++14의 기준을 따른다. 즉, 양수로 바꾼 뒤 몫을 취하고, 그 몫을 음수로 바꾼 것과 같다.</br>
이에 따라서, 위의 식 4개의 결과를 계산해보면 아래와 같다.</br>
</br>
1+2+3-4×5÷6 = 1</br>
1÷2+3+4-5×6 = 12</br>
1+2÷3×4-5+6 = 5</br>
1÷2×3-4+5+6 = 7</br>
N개의 수와 N-1개의 연산자가 주어졌을 때, 만들 수 있는 식의 결과가 최대인 것과 최소인 것을 구하는 프로그램을 작성하시오.</br>

## 입력
> 6</br>
1 2 3 4 5 6</br>
2 1 1 1</br>

## 출력
> 54</br>
-24</br>

## 코드
```c++
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#define MAX 1000000001
using namespace std;
int N,ansmax = -MAX,ansmin = MAX;
int arr[11 + 1];
int oper[4];

void Calcul(int idx, int sum)
{
    if(idx >= N - 1){
        ansmax = max(ansmax, sum);
        ansmin = min(ansmin, sum);
        return; 
    }

    if (oper[0] > 0){
        oper[0]--;
        Calcul(idx + 1, sum + arr[idx + 1]);
        oper[0]++;
    }
    if (oper[1] > 0){
        oper[1]--;
        Calcul(idx + 1, sum - arr[idx + 1]);
        oper[1]++;
    }
    if (oper[2] > 0){
        oper[2]--;
        Calcul(idx + 1, sum * arr[idx + 1]);
        oper[2]++;
    }
    if (oper[3] > 0){
        oper[3]--;
        Calcul(idx + 1, sum / arr[idx + 1]);
        oper[3]++;
    }
}

int main(void)
{
    scanf("%d\n", &N);
    for(int i=0; i<N; i++){
        scanf("%d", &arr[i]); 
    }
    for(int i=0; i<4; i++){
        scanf("%d", &oper[i]);
    }
    Calcul(0, arr[0]);
    printf("%d\n%d\n",ansmax,ansmin);

    return 0;
}
```

## 풀이
재귀로 돌면서 연산자의 개수를 카운트 모든 경우를 다돌아준다. 끝 ~ </br>
