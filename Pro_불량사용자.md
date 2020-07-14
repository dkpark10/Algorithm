# 프로그래머스 불량사용자

## 문제

[https://programmers.co.kr/learn/courses/30/lessons/64064](https://programmers.co.kr/learn/courses/30/lessons/64064)

문제 쓰기 귀찮.. 링크를 타고 확인해보자

## 코드

```c++
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;
bool visited[1 << 8];
vector<vector<int>> vv;
bool Ischeck(string &bi, string &ui)                        // 불량사용자 맵핑함수
{
    if(bi.size() != ui.size()) return false;                // 문자열 사이즈 다르면 false
    for(int i=0; i<bi.size(); i++){
        if(bi[i] != ui[i] && bi[i] != '*') return false;    // 하나라도 어긋나면 false
    }
    return true;
}
int Go(int bits, int cur)
{
    int ret = 0;
    if(cur == vv.size()){                                   // 다 방문했다면
        if(visited[bits]) return 0;
        visited[bits] = true;
        return 1;
    }
    for(int & value : vv[cur]){
        if(bits & (1 << value)) continue;                   // 이미 방문한곳이라면 컨티뉴
        ret += Go(bits | (1 << value), cur + 1);            // 재귀로 들어가 불량사용자 체크
    }
    return ret;
}
int solution(vector<string> user_id, vector<string> banned_id)
{ 
    int ans = 0;
    vv.resize(banned_id.size());
    for(int i=0; i<banned_id.size(); i++){
        for(int j=0; j<user_id.size(); j++){
            
            if(Ischeck(banned_id[i], user_id[j])){              // 불량사용자 맵핑
                vv[i].push_back(j);    
            }
        }
    }    
    return ans = Go(0,0);
}
```

## 풀이 
맵핑시켜주고 비트마스킹 ㄱㄱ 
