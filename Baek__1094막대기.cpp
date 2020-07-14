/*
지민이는 길이가 64cm인 막대를 가지고 있다. 어느 날, 그는 길이가 Xcm인 막대가 가지고 싶어졌다. 
지민이는 원래 가지고 있던 막대를 더 작은 막대로 자른다음에, 풀로 붙여서 길이가 Xcm인 막대를 만들려고 한다.

막대를 자르는 가장 쉬운 방법은 절반으로 자르는 것이다. 지민이는 아래와 같은 과정을 거쳐서 막대를 자르려고 한다.

지민이가 가지고 있는 막대의 길이를 모두 더한다. 처음에는 64cm 막대 하나만 가지고 있다. 이때, 합이 X보다 크다면, 아래와 같은 과정을 반복한다.
가지고 있는 막대 중 길이가 가장 짧은 것을 절반으로 자른다.
만약, 위에서 자른 막대의 절반 중 하나를 버리고 남아있는 막대의 길이의 합이 X보다 크거나 같다면, 위에서 자른 막대의 절반 중 하나를 버린다.
이제, 남아있는 모든 막대를 풀로 붙여서 Xcm를 만든다.
X가 주어졌을 때, 위의 과정을 거친다면, 몇 개의 막대를 풀로 붙여서 Xcm를 만들 수 있는지 구하는 프로그램을 작성하시오. 
*/

/*
문제이해하는데 어려웠으나 자세히 천천히 뜯어보면 이건 X를 이진수로 표현했을 때 1의 갯수를 묻는 문제이다..... 
*/

// 이코드는 쓰레기코드 문제 뭣도 모르고 무작정 풀려다 나온 코드 
#include<iostream>
#include<math.h>
using namespace std;
int main(void){

    int X;
    int num = 1, i = 0, stick = 64, dump = 0;

    cin >> X;

    while (i<=6){

        if(X==(int)pow(2,i++) || X==64)
            break;

        if (stick > X){
            stick /= 2;
            dump = stick;
        }
        else{
            if(stick + dump > X)
                dump /= 2;
            else if(stick + dump < X){
                num++;
                stick += dump; 
                dump /= 2;
            }else{
                num++;
                break;
            }
        }
    }
    cout << num;

    return 0;
}

/*
#include<iostream> // 걍 이진수의 1이 몇개있는지 구하면 됨 그게 끝 
#include<math.h>
using namespace std;
int main(void){

    int X, num = 0;

    cin >> X;

    while(X){
        if (X % 2 != 0)
            num++;
        X /= 2;
    }

    cout<<num;

    return 0;
}
*/
