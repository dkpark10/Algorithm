/*
2×n 크기의 직사각형을 1×2, 2×1 타일로 채우는 방법의 수를 구하는 프로그램을 작성하시오.
아래 그림은 2×5 크기의 직사각형을 채운 한 가지 방법의 예이다.
점화식을 보면 n크기의 타일링 방법의 수는 (n - 2) + (n - 1)이다.
*/

#include <stdio.h>
int main(void)
{
    int N, tile[1001];
    scanf("%d", &N);

    tile[0] = 1;
    tile[1] = 2;

    for (int i = 2; i < N; i++)
        tile[i] = (tile[i - 2] + tile[i - 1]) % 10007; //여기서 10007을 나눠줘야함 출력문에서 나누면 왠지 모르지만 에러

    printf("%d",tile[N - 1]);

    return 0;
}
