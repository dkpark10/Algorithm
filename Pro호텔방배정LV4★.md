# 프로그래머스 호텔방배정 lv4

## 문제

"스노우타운"에서 호텔을 운영하고 있는 "스카피"는 호텔에 투숙하려는 고객들에게 방을 배정하려 합니다. </br>
호텔에는 방이 총 k개 있으며, 각각의 방은 1번부터 k번까지 번호로 구분하고 있습니다. 처음에는 모든 방이 비어 있으며 </br>
"스카피"는 다음과 같은 규칙에 따라 고객에게 방을 배정하려고 합니다.</br>
</br>
한 번에 한 명씩 신청한 순서대로 방을 배정합니다.</br>
고객은 투숙하기 원하는 방 번호를 제출합니다.</br>
고객이 원하는 방이 비어 있다면 즉시 배정합니다.</br>
고객이 원하는 방이 이미 배정되어 있으면 원하는 방보다 번호가 크면서 비어있는 방 중 가장 번호가 작은 방을 배정합니다.</br>
예를 들어, 방이 총 10개이고, 고객들이 원하는 방 번호가 순서대로 [1, 3, 4, 1, 3, 1] 일 경우 다음과 같이 방을 배정받게 됩니다.</br>

전체 방 개수 k와 고객들이 원하는 방 번호가 순서대로 들어있는 배열 room_number가 매개변수로 주어질 때, </br>
각 고객에게 배정되는 방 번호를 순서대로 배열에 담아 return 하도록 solution 함수를 완성해주세요.</br>
</br>
**[제한사항]**
k는 1 이상 1012 이하인 자연수입니다.
room_number 배열의 크기는 1 이상 200,000 이하입니다.
room_number 배열 각 원소들의 값은 1 이상 k 이하인 자연수입니다.
room_number 배열은 모든 고객이 방을 배정받을 수 있는 경우만 입력으로 주어집니다.
예를 들어, k = 5, room_number = [5, 5] 와 같은 경우는 방을 배정받지 못하는 고객이 발생하므로 이런 경우는 입력으로 주어지지 않습니다.


## 코드

```c++
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <cstring>
#define ll long long
using namespace std;
map<ll , ll> room;
ll Find(ll n)
{
    if(room.find(n) == room.end()) return n;
    else return room[n] = Find(room[n]);
}
vector<long long> solution(long long k, vector<long long> room_number)
{
    vector<ll> ans;
    for(ll& ele : room_number){
        ll rr = Find(ele);
        ans.push_back(rr);
        ll next = Find(rr + 1);
        room[rr] = next;
    }
    return ans;
}
```

## 풀이

K가 10 ^ 12 이기 때문에 무식하게 찾는건 시간초과 **유니온 파인드 알고리즘** 을 이용한다. </br>
방번호를 찾고 없으면 그 방번호를 리턴해준다. </br> 
손님이 원하는 방이 없을경우 현재 비어있는 방에서 가장 낮은 방번호를 찾아야 하기 때문에 </br>
찾은방에서 다음 + 1에 루트를 찾아준다. </br>
n + 1방에서 루트를 찾아 다음에 가야할 방을 넣어주는 것이다. </br>

```c++
int find(int n){
  if(room[n] == n) return n;
  return room[n] = find(room[n]);
}
```

보통 유니온파인드 알고리즘에서 루트를 찾을 때 **room[n] == n** 자기 자신이면 리턴을 주로 했지만 </br>
이 문제처럼 다른 조건식으로도 짤 수 있다는 걸 알았다. 중요한건 밑에 코드 재귀적으로 루트를 찾는게 유니온 파인드의 핵심이다. </br>
