/*
문제 자체는 어렵지 않으나 cout , cin , scanf등 개념을 모르고
푸니까 자꾸 틀린다..... 틀렸던 코드와 맞았던 코드의
차이점을 잘 모르겠다...
*/
#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;
int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);    
    bool check[21];
    memset(check, false, sizeof(check));
    int N;
    cin >> N;

    while(N--){
        int num;
        string s;
        cin >> s;

        if(s == "add"){
            cin >> num;
            check[num] = true;
        }
        else if(s == "remove"){
            cin >> num;
            check[num] = false;
        }
        else if(s == "check"){
            cin >> num;
            if(check[num]) printf("%d\n",1);
            else printf("%d\n",0);
        }
        else if(s == "toggle"){
            cin >> num;
            if(check[num]) check[num] = false;
            else check[num] = true;
        }
        else if(s == "all") memset(check, true, sizeof(check));
        else memset(check, false, sizeof(check));
    }
    return 0;
}
