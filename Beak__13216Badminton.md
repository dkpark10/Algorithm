# 백준 13216번문제 Badminton

## 문제
Anisa (Player A) and Ben (Player B) are playing a singles badminton match. Here are the basic badminton rules: </br>
To win a match, a player needs to win 2 out of 3 games.</br>
The first player to reach 21 points wins the game. </br>
(A different rule applies when the players are tied 20-20. You may assume this case does not happen.)</br>
Either player can score a point no matter who serves.</br>
After a game is won, a new game begins and the score resets to 0-0.</br>

## 코드

```c++
#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

int main(void)
{
    string s;
    int ascore,bscore,a,b;
    ascore = bscore =  a = b = 0;

    cin >> s;
    for(int i=0; i< s.size(); i++){
        
        if(s[i] == 'A') ascore++;
        else bscore++; 
        
        if(ascore == 21){
            a++;
            printf("%d-%d\n",ascore,bscore);
            ascore = bscore = 0;
        }
        else if(bscore == 21){
            b++;
            printf("%d-%d\n",ascore,bscore);
            ascore = bscore = 0;
        }
    }
    printf("%c\n", a > b ? 'A' : 'B');

    return 0; 
}
```

## 풀이
풀이랄게 없다 3판 2선으로 이긴놈 출력해주면 끝 
