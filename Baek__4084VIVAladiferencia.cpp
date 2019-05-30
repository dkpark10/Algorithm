/*
네 개의 양의 정수 a, b, c, d가 있을 때, 아래와 같이 차이를 계산할 수 있다.
|a-b| |b-c| |c-d| |d-a|
이렇게 나온 네 개의 수를 이용해서 다시 또 차이를 계산할 수 있다. 이 작업을 모든 네 개의 정수가 같아질 때까지 반복한다.
예를 들어, 1, 3, 5, 9로 시작했을 때를 생각해보자.

1 3 5 9

2 2 4 8 (1)

0 2 4 6 (2)

2 2 2 6 (3)

0 0 4 4 (4)

0 4 0 4 (5)

4 4 4 4 (6)
위의 경우에서 수열은 6번 만에 수렴한다. a, b, c, d가 주어졌을 때, 이 수열이 얼마나 빨리 수렴하는지 구하는 프로그램을 작성하시오.
쉬운문제 같아질 때 까지 루프돌려주면 된다 문제 알고리즘은 쉬우나 0 0 0 0이 입력될 때 까지 계속 입력받는 문법을 너무 길게 씀
다른사람 코드를 보니 신기하게 씀
for(; scanf("%d %d %d %d",&a,&b,&c,&d),a) 이렇게도 쓸 수 있구나 배웠다 쓸 일이 있을진... 
*/

#include <iostream>
#include <stdlib.h> // c++에선 abs 함수가 이 헤더파일에 있음 math.h만 달랑 쓰면 안됨
#include <stdio.h>
#include <math.h>
using namespace std;

int result[10001];
int main()
{
    int *ptr, index = 0;
    int a, b, c, d;
    int ta, tb, tc, td;

    while(true){
        int cnt = 0;
        ptr= (int*)malloc(sizeof(int)*4);

        for(int i=0; i< 4; i++)
            cin>>ptr[i];

        if (ptr[0] == 0 && ptr[1] == 0 && ptr[2] == 0 && ptr[3] == 0) break;

        while (!(ptr[0] == ptr[1] && ptr[1] == ptr[2] && ptr[2] == ptr[3] && ptr[3] == ptr[1]))
        {
            ta = abs(ptr[0] - ptr[1]);
            tb = abs(ptr[1] - ptr[2]);
            tc = abs(ptr[2] - ptr[3]);
            td = abs(ptr[3] - ptr[0]);

            ptr[0] = ta;
            ptr[1] = tb;
            ptr[2] = tc;
            ptr[3] = td;
            cnt++;
        }
        result[index++]= cnt; 
        free(ptr);
    }
    for(int i=0; i<index; i++)
        cout << result[i] << endl;

    return 0;
}
