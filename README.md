# Algorithm
> 알고리즘 푼거

## 보일러 플레이트

```c++
#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <map>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <random>
#include <cstdio>
#include <ctime>
#include <sstream>
#include <regex>
#include <set>

#pragma warning(disable : 4996)

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) > (b) ? (b) : (a))

#define INF1 1e15
#define INF2 987654321
#define LL long long
#define VS vector<string>
#define VI vector<int>
#define VLL vector<LL>
#define VB vector<bool>
#define VC vector<char>
#define PII pair<int, int>
#define PLL pair<LL, LL>
#define DIVI 1000000

using namespace std;

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  return 0;
}
```

## 실행 및 디버깅

#### mac

맥은 desktop이나 home에 경로를 두면 디버깅할 때 자꾸 폴더 접근 모달이 귀찮게 떠서 나중에 이동
실행: control + option + n

### window
몰루?

## 꾸르팁

1. 배열의 길이가 길어서 함수에 파라미터로 계속 넘겨주기 보단 전역변수에 따로 할당을 해서 사용하자 사용시간의 유의미한 차이가 있다.
  #### 프로그래머스 숫자 타자 대회
  ```javascript
    /**
     * @param {numbers} number[] 아주 긴 배열
     */
    touch(idx + 1, left, right, numbers) // (x)

    globalNumbers = numbers;
    touch(idx + 1, left, right) // (O)
  ```


2. dp는 탑다운 방식과 다운탑 방식 둘다 다룰줄 알아야 한다. 탑다운 방식은 재귀적으로 수행하는데 이게 최적의 캐싱연산을 보장하지 않는다.
  #### 프로그래머스 숫자 타자 대회
  [https://school.programmers.co.kr/questions/43710](https://school.programmers.co.kr/questions/43710)

3. cout의 출력에서 줄바꿈은 endl 보다 "\n" 이 더 최적이다.
  ```c++
    cout << result << endl (x) 
    cout << result << "\n"; (o)
  ```

  ref
  [https://heroine-day.tistory.com/50](https://heroine-day.tistory.com/50)
  [https://yechoi.tistory.com/48](https://yechoi.tistory.com/48)

