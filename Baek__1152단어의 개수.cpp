#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm> 
using namespace std;

int main(void)
{
    char str[101]; 
    int num = 0, idx = 0;

    while(1){
        
        scanf("%c", &str[idx]);
        if(str[idx] == '\n') break; 
        idx ++;
    }

    idx = 0;
    while(str[idx] != '\n'){                                // 널이 아닐때까지 반복

        if(str[idx] == ' '){                                // 공백이면 걍 인덱스 추가
            idx++;
            continue;
        }
        else{
            while(str[idx] != ' ' && str[idx] != '\n'){     // 공백이 아니고 널이 아닐때까지
                idx++;
            }
            num++;
        }
    }
    printf("%d", num);

    return 0;
}

