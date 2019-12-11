# 백준 15552번 빠른 A + B

## 설명

c++을 사용하고 있다면 cin.tie(NULL), </br>

> ios_base::sync_with_stdio(false) </br>
cin.tie(NULL)

등을 써서 시간 초과를 줄여준다. endl은 개행문자를 출력할 뿐만 아니라 </br>
출력 버퍼를 지우는 역할까지 한다. 그래서 출력한 뒤 콘솔에 바로 보이게 </br>
할 수 있는데 그 버퍼를 비우는 작업이 매우 느리다. 게다가 온라인 저지에서는 </br>
바로 보여지는 것이 아니라 출력되는 것이 무엇인지 중요하기 때문에 버퍼를 자주 </br>
비울 필요가 없다. 그래서 개행문자 endl을 "\n"로 바꿔주기만 해도 시간을 줄일 수 있다. </br>
</br>
cin.tie(NULL)은 cin과 cout의 묶음을 풀어준다. 기본적으로 신으로 읽을 때 먼저 출력버퍼를 비우는데</br>
마찬가지로 마찬가지로 화면에 보여지는 것은 중요하지 않다.
</br>
ios_base::sync_with_stdio(false)는 씨와 씨플플의 버퍼를 분리한다. 신과 시아웃이 </br>
더이상 stdin/stdout과 맞춰 줄 필요가 없으므로 속도가 향상된다. 단 </br>
**버퍼가 분리되었으므로 cin과 scanf, gets,getchar등을 같이 사용해선 안되고** </br>
**cout과 printf,puts,putcjar를 같이 사용해선 안된다.**

##코드
```c++
#include<iostream>
using namespace std;
int main(void)
{
  ios_base::sync_with_stdio(false):
  cin.tie(NULL);
  int N;
  cin >> N;
  while(N--){
    int a,b;
    cin >> a >> b;
    cout << a + b << "\n";
  }
  return 0;
}
```
