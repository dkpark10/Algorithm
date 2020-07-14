/*
양수 A가 N의 진짜 약수가 되려면, N이 A의 배수이고, A가 1과 N이 아니어야 한다. 
어떤 수 N의 진짜 약수가 모두 주어질 때, N을 구하는 프로그램을 작성하시오.

쉽다... 소트하고 처음과 마지막 인덱스 곱해주자 ... 
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int main(void)
{
    int N,arr[51];
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%d", &arr[i]);
    }

    sort(arr, arr + N);
    printf("%d\n", arr[0] * arr[N - 1]);

    return 0;
}
