/*
걍 내림차순 
sort함수로 직빵으로 해결...
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAX 1000001
using namespace std;

bool cmp(int a, int b) {return a > b;}
int main(void)
{
    int N,arr[MAX];
    scanf("%d",&N);
    for(int i=0; i<N; i++){
        scanf("%d",&arr[i]);
    }
    sort(arr, arr + N, cmp);
    for(int i=0; i<N; i++){
        printf("%d\n",arr[i]);
    }
    return 0;
}
