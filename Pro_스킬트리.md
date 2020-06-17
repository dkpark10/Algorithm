# 프로그래머스 스킬트리

## 문제

선행 스킬이란 어떤 스킬을 배우기 전에 먼저 배워야 하는 스킬을 뜻합니다. </br>
예를 들어 선행 스킬 순서가 스파크 → 라이트닝 볼트 → 썬더일때, 썬더를 배우려면 먼저 라이트닝
볼트를 배워야 하고, 라이트닝 볼트를 배우려면 먼저 스파크를 배워야 합니다.
위 순서에 없는 다른 스킬(힐링 등)은 순서에 상관없이 배울 수 있습니다. 따라서 스파크 → 힐링 → 
라이트닝 볼트 → 썬더와 같은 스킬트리는 가능하지만, 썬더 → 스파크나 라이트닝 볼트 → 스파크 →
힐링 → 썬더와 같은 스킬트리는 불가능합니다.
선행 스킬 순서 skill과 유저들이 만든 스킬트리1를 담은 배열 skill_trees가 매개변수로 주어질
때, 가능한 스킬트리 개수를 return 하는 solution 함수를 작성해주세요.

## 입출력

skill  | skill_trees | return
--- | --- | ---
"CBD" | ["BACDE", "CBADF", "AECB", "BDA"] | 2

BACDE: B 스킬을 배우기 전에 C 스킬을 먼저 배워야 합니다. 불가능한 스킬트립니다. </br>
CBADF: 가능한 스킬트리입니다.</br>
AECB: 가능한 스킬트리입니다.</br>
BDA: B 스킬을 배우기 전에 C 스킬을 먼저 배워야 합니다. 불가능한 스킬트리입니다.</br>

## 코드

```c++
#include <string>
#include <vector>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int ans = 0;
    vector<int>temp;
    
    for(string &s : skill_trees){

        temp.clear();
        for(int i=0; i<s.size(); i++){
            for(int j=0; j<skill.size(); j++){
                if(s[i] == skill[j]){
                    temp.push_back(j);                  // 스킬트리에서 스킬이랑 문자열 같으면 인덱스 푸쉬
                }
            }
        }
        bool check = true;
        for(int i=0; i<temp.size(); i++){
            if(temp[i] != i){                         // 옳게된 스킬트리라면 0,1,2,3... 이렇게 이쁘게 담겨져있어야함
                check = false;                        // 아니라면 check = false 해주고 
                break;                                // 그리고 쀍해주자
            }
        }
        if(check) ans++;                              // 이쁘게 담겨져있으면 답 증감
    }
    return ans;
}
```

## 여담

아 요즘 알고리즘 자신없네 옛날엔 자신감 만땅이었는데 퇴화된거같음 ㅅㄱ
이거 푸는데도 꽤 시간걸림 ㅠㅜㅠㅜ
