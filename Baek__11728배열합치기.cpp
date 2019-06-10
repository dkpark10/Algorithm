// 정렬되어있는 두 배열 A와 B가 주어진다. 두 배열을 합친 다음 정렬해서 출력하는 프로그램을 작성하시오.

#include<stdlib.h>
#include<algorithm>
#include<stdio.h>
using namespace std;

int main(void)
{
    int n,m;
    scanf("%d %d", &n, &m);

    int size = n + m;
    int *a = (int *)malloc(sizeof(int) * n);
    int *b = (int *)malloc(sizeof(int) * m);
    int *c = (int *)malloc(sizeof(int) * size);

    for(int i=0; i< n; i++) scanf("%d",&a[i]);
    for(int i=0; i< m; i++) scanf("%d",&b[i]);
    
    for(int i=0; i< n; i++)
        c[i] = a[i];
    for(int i=n; i< size; i++)
        c[i] = b[i - n]; // 첫 배열끝나고 그다음 인덱스에 삽입

    sort(c,c+size); // 정렬
    for(int i=0; i<size; i++)
        printf("%d ",c[i]);

    free(a);
    free(b);
    free(c);

    return 0;
}
