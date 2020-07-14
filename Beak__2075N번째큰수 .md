## 백준 2075번 N번째 큰수 

N×N의 표에 수 N2개 채워져 있다. 채워진 수에는 한 가지 특징이 있는데, </br>
모든 수는 자신의 한 칸 위에 있는 수보다 크다는 것이다. N=5일 때의 예를 보자.</br>
</br>
12 7	9	 15	 5</br>
13 8	11 19	 6</br>
21 10 26 31	16</br>
48 14 28 35	25</br>
52 20 32 41	49</br>
</br>
이러한 표가 주어졌을 때, N번째 큰 수를 찾는 프로그램을 작성하시오. 표에 채워진 수는 모두 다르다.

## 입력
> 5</br>
12 7 9 15 5</br>
13 8 11 19 6</br>
21 10 26 31 16</br>
48 14 28 35 25</br>
52 20 32 41 49</br>

## 출력
> 35

## 코드
```c++
#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
int main(void)
{
    int N, num;
    priority_queue<int, vector<int>, greater<int>> pq;
    scanf("%d", &N);
    for(int i=0; i< N*N; i++){
        scanf("%d", &num);
        pq.push(num);
        if(pq.size() > N){
            pq.pop();           
        }
    }
    printf("%d\n",pq.top());
    return 0;
}
```

## 풀이
문제자체는 쉬우나 이문제에 조건이 있다 바로 메로리용량이 **10MB** 밖에 </br>
안된다는 것. 그러면 어찌 푸냐 크기가 N 고정인 힙에 넣고 풀자 </br>
윈도우 슬라이딩 , 투포인터 알고리즘을 떠올리면 쉽다. </br>
사이즈가 N이상되면 팝해주고 top을 출력해주자 </br>
그리고 힙은 stl쓰지말고 직접 구현해보기로 하자 </br>


