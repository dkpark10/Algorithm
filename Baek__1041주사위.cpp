/*
주사위는 위와 같이 생겼다. 주사위의 여섯 면에는 수가 쓰여 있다. 위의 전개도를 수가 밖으로 나오게 접는다.
A, B, C, D, E, F에 쓰여 있는 수가 주어진다.
지민이는 현재 동일한 주사위를 N^3개 가지고 있다. 이 주사위를 적절히 회전시키고 쌓아서, N*N*N크기의 정육면체를 만들려고 한다.
이 정육면체는 탁자위에 있으므로, 5개의 면만 보인다.
N과 주사위에 쓰여 있는 수가 주어질 때, 보이는 5개의 면에 쓰여 있는 수의 합의 최솟값을 출력하는 프로그램을 작성하시오.
    
      D
    E A B F        <--- 전개도
      C
      
1면, 2면, 3면의 갯수를 구하는 과정은 쉬웠으나 주사위 최소합을 구하는 알고리즘이 어려웠다 
일일이 대입해 볼 수 있으나 그렇게 하긴 싫었고 결국 못구해 남의 것 참조
마주보는 3쌍끼리 비교해 나온 최소값으로 구하면 되는 것이였음 물론 나는 생각 못함
그리고 최대값을 넣으면 값이 커지기 때문에 long long형으로 데이터 타입 정함
이거 때문에 삽질함
*/

#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;

ll Min(ll a, ll b)
{
    if(a<b) return a;
    else return b;
}

int main(void)
{
    ll N, dice[6];
    ll result = 0;
    ll min1 = 0, min2 = 0, min3 = 0;

    cin>>N;
    for(int i=0; i< 6; i++) cin>>dice[i];

    ll side1 = 4 * (N - 1) * (N - 2) + (N - 2) * (N - 2);
    ll side2 = 4 * (N - 1) + 4 * (N - 2);
    ll side3 = 4;

    if(N==1){
        sort(dice,dice + 6);
        for(int i=0; i<5; i++)
            result += dice[i];
    }
    else{
        dice[0] = Min(dice[0], dice[5]);
        dice[1] = Min(dice[1], dice[4]);
        dice[2] = Min(dice[2], dice[3]);

        sort(dice,dice + 3);
        min1 = dice[0];
        min2 = dice[0] + dice[1];
        min3 = dice[0] + dice[1] + dice[2];

        result += min1 * side1;
        result += min2 * side2;
        result += min3 * side3;
    }

    cout << result;
    return 0;
}
